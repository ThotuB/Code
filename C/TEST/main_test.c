#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coderole {
    int code;
    char role[100];
}CODEROLE;

int main() {
    CODEROLE *codeptr=(CODEROLE*)malloc(100000*sizeof(CODEROLE));
    int index = 0;
    FILE *find;
    find = fopen("in.txt", "r");

    while (!feof(find)) {
        printf("sunt in while %d\n", index);
        char str[100];
        fscanf(find, "%d", &codeptr[index].code);
        fgetc(find);
        fgets(str, 50, find);
        str[strlen(str) - 1] = '\0';
        strcpy(codeptr[index].role, str);
        index++;
    }

//    for (int i = 0; i < index; i++) {
//        printf("%d \n", codrptr[i].code);
//    }
//
//    for (int i = 0; i < index; i++) {
//        printf("%s \n", codrptr[i].role);
//    }

    printf("%d \n", index);
    printf("%d %s", codeptr[0].code, codeptr[0].role);
    printf("%d \n", index);
    printf("%d %s", codeptr[1].code, codeptr[1].role);
    printf("%d \n", index);

    return 0;
}
