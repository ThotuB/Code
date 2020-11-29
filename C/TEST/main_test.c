#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 80

char* get_buffer(){
    char *buffer = (char*)calloc(BUF_SIZE , sizeof(char));

    printf("Input:");
    fgets(buffer, BUF_SIZE, stdin);

    return buffer;
}

void print_buffer(char *buffer){
    for (unsigned i = 0 ; i < BUF_SIZE ; i++){
        if ( isalpha(buffer[i]) || isspace(buffer[i]) ){
            printf("%c", buffer[i]);
        }
    }
}

int main() {
    char *buffer = get_buffer();
    print_buffer(buffer);

    return 0;
}
