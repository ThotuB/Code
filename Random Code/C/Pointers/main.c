#include <stdio.h>

void printAddress(int *ptr) {
    printf("0x%p\n", ptr);
}

void printAddressOf(int nr) {
    printf("0x%p\n", &nr);
}

void print(int nr) {
    printf("%d\n", nr);
}

void printValueAt(int *ptr) {
    printf("%d\n", *ptr);
}

int main() {
    int x = 6;
    int *ptrX = &x;

    printAddress(ptrX);
    printAddressOf(x);
    print(x);
    printValueAt(ptrX);

    return 0;
}
