#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);

    for (int i = 0; i < a_len && i < b_len; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }

    return a_len - b_len;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);

    for (int i = 0; i < a_len && i < b_len; i++) {
        if (a[i] != b[i]) {
            return b[i] - a[i];
        }
    }

    return b_len - a_len;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);

    int a_chars[27] = {0};
    int b_chars[27] = {0};

    int a_distinct_chars = 0;
    int b_distinct_chars = 0;

    for (int i = 0; i < a_len ; i++) {
        int char_index = a[i] - 'a';
        if (a_chars[char_index] == 0) {
            a_distinct_chars++;
            a_chars[char_index] = 1;
        }
    }

    for (int i = 0; i < b_len ; i++) {
        int char_index = b[i] - 'a';
        if (b_chars[char_index] == 0) {
            b_distinct_chars++;
            b_chars[char_index] = 1;
        }
    }

    if (a_distinct_chars == b_distinct_chars) {
        return lexicographic_sort(a, b);
    }
    return a_distinct_chars - b_distinct_chars;
}

int sort_by_length(const char* a, const char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);

    if (a_len == b_len) {
        return lexicographic_sort(a, b);
    }
    return a_len - b_len;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void print_array(char** arr, const int len) {
    for (int i = 0; i < len; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char* arr[] = {"wkue", "qoi", "sbv", "fekls"};

    print_array(arr, 4);
    printf("Lexicographic\n");
    string_sort(arr, 4, lexicographic_sort);
    print_array(arr, 4);
    printf("Lexicographic Reverse\n");
    string_sort(arr, 4, lexicographic_sort_reverse);
    print_array(arr, 4);
    printf("Length\n");
    string_sort(arr, 4, sort_by_length);
    print_array(arr, 4);
    printf("Number of Distinct Chars\n");
    string_sort(arr, 4, sort_by_number_of_distinct_characters);
    print_array(arr, 4);

    return 0;
}