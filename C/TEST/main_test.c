#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void fun(int *ptr){
    *ptr = 3;
}

int main() {
    int x  = 645;
    fun(&x);
    printf("%d", x);

    return 0;
}
