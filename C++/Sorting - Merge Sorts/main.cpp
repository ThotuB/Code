#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("arr.txt");

void read(unsigned Arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        fin >> Arr[i];
    }
}

void write(unsigned Arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void merge(unsigned Arr[], unsigned left, unsigned mid, unsigned right) {
    const unsigned LSize = mid - left + 1;
    const unsigned RSize = right - mid;
    unsigned LArr[LSize];
    unsigned RArr[RSize];

    // ARRAY COPY
    for (int i = 0; i < LSize; i++)
        LArr[i] = Arr[left + i];
    for (int i = 0; i < RSize; i++)
        RArr[i] = Arr[mid + 1 + i];

    unsigned i = 0, j = 0, k = left;
    while (i < LSize && j < RSize) {
        if (LArr[i] <= RArr[j]) {
            Arr[k] = LArr[i];
            i++;
        } else {
            Arr[k] = RArr[j];
            j++;
        }
        k++;
    }
    while (i < LSize) {
        Arr[k] = LArr[i];
        i++;
        k++;
    }
    while (j < RSize) {
        Arr[k] = RArr[j];
        j++;
        k++;
    }
}

void merge_sort(unsigned Arr[], unsigned left, unsigned right) {
    if (left >= right) {
        return;
    }

    unsigned mid = (left + right) / 2;
    merge_sort(Arr, left, mid);
    merge_sort(Arr, mid + 1, right);
    merge(Arr, left, mid, right);
}

int main() {
    unsigned Arr[15];
    read(Arr, 15);
    write(Arr, 15);

    merge_sort(Arr, 0, 14);
    write(Arr, 15);

    return 0;
}