#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct graf {
    int costuri[MAX][MAX];
    int nrNoduri;
};

struct graf* setareGraf(int nrNoduri) {
    struct graf* graf = (struct graf*)malloc(sizeof(struct graf));
    graf->nrNoduri = nrNoduri;

    for (int i = 0; i < nrNoduri; i++) {
        for (int j = 0; j < nrNoduri; j++) {
            graf->costuri[i][j] = -1;
        }
    }

    return graf;
}

void printareGraf(struct graf* graf) {
    for (int i = 0; i < graf->nrNoduri; i++) {
        for (int j = 0; j < graf->nrNoduri; j++) {
            printf("%d ", graf->costuri[i][j]);
        }
        printf("\n");
    }
}

void oraseDinCareSePleaca(struct graf* graf) {
    for (int i = 0; i < graf->nrNoduri; i++) {
        int plecare = 0;
        int sosire = 0;
        for (int j = 0; j < graf->nrNoduri; j++) {
            if (graf->costuri[i][j] != -1) {
                plecare++;
            }
            if (graf->costuri[j][i] != -1) {
                sosire++;
            }
        }

        if ( plecare > sosire ){
            printf("%d ", i);
        }
    }
}

void cmld_backtracking(struct graf* graf, int nod, int distantaTotala, bool viz[], int nrViz, int drum[], int distantaMax, int drumLung[])  {  
    viz[nod] = true;
    drum[nrViz] = nod;

    if (nrViz == graf->nrNoduri - 1) {
        if (distantaTotala > distantaMax) {
            distantaMax = distantaTotala;
            for (int i = 0; i < graf->nrNoduri; i++) {
                drumLung[i] = drum[i];
            }
        }
    }
    else {
        for (int i = 0; i < graf->nrNoduri; i++) {
            if (graf->costuri[nod][i] != -1 && !viz[i]) {
                cmld_backtracking(graf, i, distantaTotala + graf->costuri[nod][i], viz, nrViz + 1, drum, distantaMax, drumLung);
                viz[i] = false;
            }
        }
    }

}

void celMaiLungDrum(struct graf* graf) {
    bool viz[MAX];
    for (int i = 0; i < graf->nrNoduri; i++) {
        viz[i] = false;
    }
    int drum[MAX];
    int drumLung[MAX];

    cmld_backtracking(graf, 0, 0, viz, 0, drum, -1, drumLung);
    
    for (int i = 0; i < graf->nrNoduri; i++) {
        printf("%d ", drumLung[i]);
    }
}

int main() {
    struct graf* graf = setareGraf(3);

    graf->costuri[0][1] = 1;
    graf->costuri[0][2] = 3;
    graf->costuri[1][2] = 2;
    graf->costuri[1][0] = 1;
    graf->costuri[2][0] = 1;
    graf->costuri[2][1] = 2;

    printareGraf(graf);

    celMaiLungDrum(graf);

    return 0;
}