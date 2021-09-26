#include <iostream>

using namespace std;

void print(const int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    print((const int[]){1,2,3,4,5}, 5);
    
    return 0;
}