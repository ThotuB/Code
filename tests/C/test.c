#include <stdio.h>

int create_int() {
    return 32;
}

int a = create_int();

int main()
{
    char a[] = "Hello";
    print_char(a);

    print_char("hello");

    print_num(5);

    return 0;
}