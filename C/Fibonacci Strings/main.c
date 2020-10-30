#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

int main()
{
    int n;

    fscanf(stdin, "%d", &n);

    char *s1=malloc(SIZE*sizeof(char));
    char *s2=malloc(SIZE*sizeof(char));
    char *s3=malloc(sizeof(char));

    //strcpy(s1,"a");
    //strcpy(s2,"b");

    fscanf(stdin, "%3s %3s", s1, s2);
    printf("1 - %s\n2 - %s", s1, s2);

    for(int i=0;i<n;i++){
        s3=realloc(s3, (strlen(s1) + strlen(s2) + SIZE) * sizeof(char));
        strcpy(s3, s1);
        strcat(s3, s2);
        s1=realloc(s1, (strlen(s2) + SIZE) * sizeof(char));
        strcpy(s1, s2);
        s2=realloc(s2, (strlen(s3) + SIZE) * sizeof(char));
        strcpy(s2, s3);
        printf("\n%d - %s", i+3,s3);
    }
    return 0;
}
