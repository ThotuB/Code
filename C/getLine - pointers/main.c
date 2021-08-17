#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line {
    char* text;
    int cnt;
} line_t;

char* getLine(FILE* stream) {
    char* s = malloc(2 * sizeof(char));
    s[0] = '\0';
    int k = 0;
    char c;
    while ((c = fgetc(stream)) != EOF && c != '\n') {
        s[k] = c;
        k++;
        s = realloc(s, (k + 2) * sizeof(char));
    }
    s[k] = '\0';
    return s;
}

int main() {
    FILE* fin = fopen("in.txt", "r");

    line_t* linii = malloc(1 * sizeof(line_t));
    int k = 0;

    linii[k].text = getLine(fin);
    while (linii[k].text[0] != '\0') {
        linii[k].cnt = strlen(linii[k].text);
        k++;

        linii = realloc(linii, (k + 2) * sizeof(line_t));
        linii[k].text = getLine(fin);
    }

    for (int i = 0; i < k; i++) {
        printf("%s\n", linii[i].text);
    }

    // char *s=getLine(fin);
    // while ( s[0] != '\0' ){
    //   printf("%d%s\n",sizeof(s),s);
    //
    //   s=getLine(fin);
    // }
    return 0;
}
