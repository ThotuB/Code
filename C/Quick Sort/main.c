#include <stdio.h>
#include <stdlib.h>

int compare(int nr1, int nr2) {
    if (nr1 > nr2) {
        return 1;
    } else if (nr1 == nr2) {
        return 0;
    } else {
        return -1;
    }
}

int arrAscending(const void *el1, const void *el2) {
    int nr1 = *(int *)el1;
    int nr2 = *(int *)el2;
    return compare(nr1, nr2);
}

void printArray(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
}

int main() {
    /// ~        qsort( *ptr/array, length(# of elems), size(bytes), sortFunction )
    int tab[] = {1, 7, 3, 5, 0, 2, 4, 9, 6, 8};
    qsort(tab, 10, sizeof(tab[0]), arrAscending);
    printArray(tab, 10);

    return 0;
}
