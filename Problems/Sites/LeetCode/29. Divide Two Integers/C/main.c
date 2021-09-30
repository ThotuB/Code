#include <stdio.h>
#include <stdbool.h>

bool getSignBit(int num) {
    return num & 0x80000000;
}

int divide(int dividend, int divisor){
    int result = 0;

    

    while (dividend >= divisor) {
        dividend -= divisor;
        result++;
    }

    return sign ? -result : result;
}

int main() {
    printf("%d", divide(-2, 1));

    return 0;
}