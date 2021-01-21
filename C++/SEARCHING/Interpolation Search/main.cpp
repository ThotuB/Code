#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("../source.txt");

unsigned steps = 0;

void read(unsigned Arr[], unsigned size){
    for (unsigned i = 0 ; i < size ; i++){
        fin >> Arr[i];
    }
}

void write(unsigned Arr[], unsigned size){
    for (unsigned i = 0 ; i < size ; i++){
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int interpolation_search(unsigned Arr[], unsigned size, unsigned nr){
    long long unsigned mid, left, right;
    left = 0; right = size - 1;

    if ( Arr[left] >= nr ){
        return -1;
    }

    do{
        steps++;
        mid = left + (right - left) * (nr - Arr[left]) / (Arr[right] - Arr[left]);
        //printf("%llu - %llu - %llu\n", left, mid, right);
        if ( nr > Arr[mid] ){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }while ( (left <= right) && (Arr[mid] != nr) && (Arr[left] != Arr[right]) && (Arr[left] <= nr) && (nr <= Arr[right]) );

    if ( nr == Arr[mid] ){
        return mid;
    }
    return -1;
}

int main(){
    unsigned Arr[13];
    read(Arr, 13);
    //write(Arr, 13);

    cout << interpolation_search(Arr, 13, 10) << "\n";
    cout << steps << "\n";

    return 0;
}
