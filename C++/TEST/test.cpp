#include <iostream>

using namespace std;

float get_medie(int *Arr, unsigned size){
    float sum = 0;
    for (unsigned i = 0 ; i < size ; i++){
        sum += Arr[i];
    }
    return sum/size;
}

void pasta_medie(int Arr[3][4], unsigned m, unsigned n){
    for (unsigned j = 0 ; j < n ; j++){
        float med = get_medie(Arr[j], m);
        cout << med << ":";
        for (unsigned i = 0 ; i < m ; i++){
            if ( med <= Arr[j][i] ){
                cout << Arr[j][i] << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    int Arr[3][4] = {{1, 3, 5, 7}, {2, 4, 6 ,7}, {2, 2, 4, 8}};

    pasta_medie(Arr, 4, 3);
}