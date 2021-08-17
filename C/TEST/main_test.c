#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 1000

struct record {
    char name[32];
    int budget;
    int year;
    struct record* next;
};

typedef struct record record_t;

record_t* makeNewRecord() {
    record_t* newRecord = (record_t*)malloc(sizeof(record_t));
    strcpy(newRecord->name, "null");
    newRecord->budget = -1;
    newRecord->year = -1;
    newRecord->next = NULL;
    return newRecord;
}

void printRecord(record_t* record) {
    printf("%s, %d, %d\n", record->name, record->year, record->budget);
}

int compare(record_t* mov1, record_t* mov2) {
    if (mov1->year == mov2->year)
        return strcmp(mov1->name, mov2->name);

    return mov2->year - mov1->year;
}

void insertRecord(record_t** headPtr, record_t* record) {
    if (*headPtr == NULL) {
        *headPtr = record;
        return;
    }

    record_t* head = *headPtr;
    if (compare(head, record) < 0) {
        record->next = head;
        *headPtr = record;
        return;
    }
    while (compare(head->next, record) >= 0 && head->next != NULL)
        head = head->next;

    if (head->next == NULL) {
        head->next = malloc(sizeof(record_t));
        head->next = record;
    } else {
        record->next = head->next;
        head->next = record;
    }
}

void printAll(record_t* head) {
    record_t* temp = head;
    while (temp != NULL) {
        printRecord(temp);
        temp = temp->next;
    }
}

void readCSV(FILE* fin, record_t** headPtr) {
    char line[1024];
    char* token;
    int step = 0;
    int count = 0;
    while (fgets(line, 1024, fin)) {
        step = 0;
        token = strtok(line, ",");
        record_t* newRecord = makeNewRecord();
        while (token != NULL) {
            if (strcmp(token, "") != 0 && strcmp(token, "\n") != 0) {
                if (step == 0)
                    newRecord->year = atoi(token);
                if (step == 2)
                    strncpy(newRecord->name, token, 32);
                if (step == 10)
                    newRecord->budget = atoi(token);
            }
            token = strtok(NULL, ",");
            step++;
        }
        insertRecord(headPtr, newRecord);
        count++;
    }
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen("movies.csv", "r");

    record_t* head = NULL;

    readCSV(fin, &head);

    record_t* temp = head;
    while (temp != NULL) {
        printRecord(temp);
        temp = temp->next;
    }

    return 0;
}