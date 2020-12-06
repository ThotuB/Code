#include <iostream>

using namespace std;

int main(){
    int *arr = new int[44];
    cout << (sizeof(*arr)/sizeof(arr[0]));
}