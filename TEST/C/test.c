#include <stdio.h>

void print_char(char *a)
{
    a[0]++;
    printf("%s\n", a);
}

void print_num(int a)
{
    printf("%d\n", ++a);
    printf("%d\n", a++);
}

int main()
{
    char a[] = "Hello";
    print_char(a);

    print_char("hello");

    print_num(5);

    return 0;
}