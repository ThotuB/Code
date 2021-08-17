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

int linear_search(unsigned Arr[], unsigned size, unsigned nr) {
    for (unsigned i = 0; i < size; i++) {
        steps++;
        if (Arr[i] == nr) {
            return i;
        }
    }
    return -1;
}

int main() {
    unsigned Arr[13];
    read(Arr, 13);
    //write(Arr, 13);

    cout << linear_search(Arr, 13, 16) << "\n";
    cout << steps << "\n";

    return 0;
}