#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("../source.txt");

unsigned steps = 0;

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

int binary_search(unsigned Arr[], unsigned left, unsigned right, unsigned nr) {
    steps++;

    unsigned mid = (left + right - 1) / 2;

    if (right == 0) {
        return -1;
    }

    if (nr == Arr[mid]) {
        return mid;
    }

    if (nr < Arr[mid]) {
        return binary_search(Arr, left, mid - 1, nr);
    }
    return binary_search(Arr, mid + 1, right, nr);
}

int main() {
    unsigned Arr[13];
    read(Arr, 13);
    //write(Arr, 13);

    cout << binary_search(Arr, 1, 13, 10) << "\n";
    cout << steps << "\n";

    return 0;
}