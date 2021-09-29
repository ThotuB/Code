#include <stdio.h>

void printAddress(int *ptr) {
    printf("0x%p\n", ptr);
}

void printValue(int nr) {
    printf("%d\n", nr);
}

void printValueAt(int *ptr) {
    printf("%d\n", *ptr);
}

int main() {
    int x = 6;

    printf("INT:\n");
    printAddress(&x);
    printValue(x);
    printValueAt(&x);

    int arr[] = {1, 2, 3, 4, 5};
    printf("\nARRAY:\n");
    printAddress(arr);
    printValue(arr[0]);
    printValueAt(arr);

    return 0;
}
