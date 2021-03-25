#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void print_Divizori(const char *numSTR) {

    int num = atoi(numSTR);
    int count = 0;

    char string[10000] = {0};

    strcat(string, "PID: ");
    sprintf(string + strlen(string), "<%d> ", getpid());

    strcat(string, "nr: ");
    sprintf(string + strlen(string), "<%d>: ", num);

    for (int i = 1; i < num; i++)
        if (num % i == 0) {
            sprintf(string + strlen(string), "%d ", i);
            count ++;
        }

    strcat(string, "\n");
    printf("%s", string);

    exit(count);
}

int main( int argc, char const *argv[] ) {

    if( argc < 4 ) {
        printf("Usage : %s, file_name number1 number2 ...\n", argv[0]);
        exit(1);
    }

    int pid1 = fork();

    if( pid1 < 0 ) {
        perror("Error at fork1");
        exit(2);
    }

    if( pid1 == 0 ) {
        if(execlp("wc" , "wc", "-l", argv[1], (char *)NULL) < 0) {
            perror("Error at execlp!");
            exit(3);
        }
    }

    for (int i = 2; i < argc; ++i) {

        int pid2 = fork();

        if ( pid2 < 0 ) {
            perror("Error at fork");
            exit(2);
        }

        if( pid2 == 0 ) 
            print_Divizori(argv[i]);
        
    }

    for (int i = 2; i < argc; ++i) {

        int status;
        pid_t w = wait(&status);

        if ( w == -1 ) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        // if ( WIFEXITED(status) ) {
        //      printf("exited, status= %d\n", WEXITSTATUS(status));
        // }

        printf("Procesul <%d> s-a incheiat cu codul <%d> \n", w, WEXITSTATUS(status));
    }

    int status1;

    pid_t w1 = wait(&status1);
    if( w1 == -1 ){
        perror("wait 1!");
        exit(4);
    }

    return 0;
}