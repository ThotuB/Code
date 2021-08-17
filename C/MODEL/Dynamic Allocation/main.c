#include <stdio.h>
#include <stdlib.h>

typedef struct exStruct {
    int int1;
    char *str;
} exStruct_t;

int main() {
    ///     ~~~~~~~~~~      Malloc()       ~~~~~~~~~~

    //      ~     malloc( len * sizeof(type) )      ~
    int *pInt1 = malloc(5 * sizeof(int));

    //      ~            malloc( size )             ~
    int *pInt2;
    pInt2 = malloc(20);

    exStruct_t *ptrExStruct = malloc(1 * sizeof(exStruct_t));
    ptrExStruct[0].str = malloc(10 * sizeof(char));
    scanf("%9s", ptrExStruct[0].str);
    //printf("%s", ptrExStruct[0].str);

    ///     ~~~~~~~~~~       Free()        ~~~~~~~~~~

    //      ~            free( *ptr )               ~
    free(pInt2);

    ///     ~~~~~~~~~~      Realloc()      ~~~~~~~~~~

    //      ~        realloc( *ptr, size )          ~
    char *s = malloc(2 * sizeof(char));
    int k = 0;
    s[0] = getchar();
    s[1] = '\0';
    for (int i = 1; i < 10 && s[k] != '\n'; i++) {
        s = realloc(s, (i + 2) * sizeof(char));
        //printf("%s\n",s);

        s[k + 1] = getchar();
        s[k + 2] = '\0';

        k++;
    }
    return 0;
}
