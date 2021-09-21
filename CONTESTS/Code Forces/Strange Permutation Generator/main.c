#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned *exPerm = NULL;
unsigned *outPerm = NULL;

unsigned *rArray = NULL;
unsigned *count = NULL;

void realloc_arrays(unsigned size){
    exPerm = (unsigned*)realloc(exPerm, size * sizeof(unsigned));
    outPerm = (unsigned*)realloc(outPerm, size * sizeof(unsigned));
    rArray = (unsigned*)realloc(rArray, size * sizeof(unsigned));
    count = (unsigned*)realloc(count, size * sizeof(unsigned));;
}

void get_perms(FILE* stream, unsigned size){
    for (unsigned i = 0 ; i < size ; i++){
        fscanf(stream, "%u", &exPerm[i]);
        outPerm[i] = 0;
    }
}

void reset_count(unsigned size){
    for (unsigned i = 0 ; i < size ; i++){
        count[i] = 0;
    }
}

void get_r_and_count(unsigned size){
    unsigned r;
    for (unsigned i = 0 ; i < size; i++){
        r = 0;
        for (unsigned j = i ; j < size; j++){
            if ( outPerm[j] == 0 ){
                r = j + 1;
                break;
            }
        }
        if ( r != 0 ){
            rArray[i] = r;
            count[r-1]++;
        }
        else {
            rArray[i] = 0;
        }
    }
}

unsigned get_index(unsigned nr, unsigned size){
    for (unsigned i = 0 ; i < size ; i++){
        if ( exPerm[i] == nr ){
            return i;
        }
    }

    return 0;
}

unsigned find_max_count(unsigned size){
    unsigned max = 0;
    for (unsigned i = 0 ; i < size ; i++){
        if ( count[i] > max ){
            max = count[i];
        }
    }

    return max;
}

void print_r_and_count(FILE *stream, unsigned size){
    for (unsigned i = 0 ; i < size; i++){
        fprintf(stream, "%u ", rArray[i]);
    }
    fprintf(stream, "\n");
    for (unsigned i = 0 ; i < size; i++){
        fprintf(stream, "%u ", count[i]);
    }
    fprintf(stream, "\n");
}

int main(){
    FILE *prob_in = fopen("in.txt", "r");
    FILE *prob_out = fopen("out.txt", "w");

    unsigned tests = 0, size;

    fscanf(prob_in, "%u", &tests);
    for (unsigned cntTest = 0 ; cntTest < tests ; cntTest++){
        bool pos = true;
        unsigned index;

        fscanf(prob_in, "%u", &size);

        realloc_arrays(size);

        get_perms(prob_in, size);

        for (unsigned nr = 1; nr <= size ; nr++){
            reset_count(size);
            get_r_and_count(size);
            //print_r_and_count(prob_out, size);

            index = get_index(nr,size);
            if ( count[index] == find_max_count(size) ){
                outPerm[index] = nr;
            }
            else{
                pos = false;
                break;
            }
        }
        if ( pos ){
            fprintf(prob_out, "Yes\n");
        }
        else{
            fprintf(prob_out, "No\n");
        }
    }
}
