#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int x = 0b00101101;
    int y = 0b01010101;

    printf("%b\n", x ^ y);

    return 0;
}