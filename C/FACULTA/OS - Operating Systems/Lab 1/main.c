#include <stdio.h>
#include <stdlib.h>

unsigned **read_mat(char *fileName, size_t size){
    FILE *fin = fopen(fileName, "r");

    unsigned **Mat = (unsigned**)calloc(size, sizeof(unsigned*));

    for (unsigned i = 0 ; i < size ; i++){
        Mat[i] = (unsigned*)calloc(size, sizeof(unsigned));
        for (unsigned j = 0 ; j < size ; j++){
            fscanf(fin, "%d", &Mat[i][j]);
        }
    }
    
    return Mat;
}

void print_mat(unsigned **Mat, size_t size){
    for (unsigned i = 0 ; i < size ; i++){
        for (unsigned j = 0 ; j < size ; j++){
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv){
    printf("%d\n", argc);
    if ( argc != 3 ){
        printf("USAGE: /name.exe <n> <file>\n", argv[0]);
        exit(1);
    }
    unsigned size = atoi(argv[1]);

    unsigned **Mat = read_mat(argv[2], size);
    print_mat(Mat, size);

    return 0;
}