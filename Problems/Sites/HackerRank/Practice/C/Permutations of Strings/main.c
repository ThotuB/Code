#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int index1, int index2) {
    if (index1 == index2) {
        return;
    }
    char *temp = s[index1];
    s[index1] = s[index2];
    s[index2] = temp;
}

void reverse(char **str, int start, int end) {
    while (start < end) {
        swap(str, start++, end--);
    }
}

int search(char **str, int start, int end, char *key) {
    int index = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (strcmp(str[mid], key) <= 0) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            if (index == -1 || strcmp(str[index], str[mid]) >= 0){
                index = mid;
            }
        }
    }
    return index;
}

int next_permutation(int n, char **s){
    int i = n - 2;

    while (i >= 0 && strcmp(s[i], s[i + 1]) > 0) {
        i--;
    }

    if (i < 0) {
        return 0;
    }

    int index = search(s, i + 1, n - 1, s[i]);
    swap(s, i, index);
    reverse(s, i + 1, n - 1);

    return 1;
}

void print_permutation(int n, char **s){
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }
    printf("\n");
}

int main() {
    char* arr[] = {"a", "bc", "bc"};

    int max = 6;
    do {
        print_permutation(3, arr);
    } while (next_permutation(3, arr) && max--);

    return 0;
}