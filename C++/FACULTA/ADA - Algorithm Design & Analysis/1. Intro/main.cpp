#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

int* read_arr(ifstream &in, unsigned &size){
    in >> size;
    int *Arr = new int[size];

    for (unsigned i = 0 ; i < size ; i++){
        in >> Arr[i];
    }

    return Arr;
}

unsigned count_triplet_sum_slow(int *Arr, unsigned size, int value){
    unsigned count = 0;
    unsigned plm = 0;

    for (unsigned i = 0 ; i < size-2 ; i++ ){
        for (unsigned j = i+1 ; j < size-1 ; j++ ){
            for (unsigned k = j+1 ; k < size ; k++ ){
                if ( Arr[i] + Arr[j] + Arr[k] == value ){
                    //cout << "(" << Arr[i] << ", " << Arr[j] << ", " << Arr[k] << ")";
                    count++;
                }
            }
        }
    }

    return count;
}

unsigned count_triplet_sum_fast(int *Arr, unsigned size, int value){
    unsigned count = 0;

    sort(Arr, Arr + size);

    for (unsigned i = 0 ; i < size-1 ; i++ ){
        int left = i + 1;
        int right = size - 1;

        while ( left < right ){
            if ( Arr[left] + Arr[i] + Arr[right] == value ){
                //cout << "(" << Arr[left] << ", " << Arr[i] << ", " << Arr[right] << ")";
                count++;
            }   

            if ( Arr[left] + Arr[i] + Arr[right] < value ){
                left += 1;
            }
            else {
                right -= 1;
            }
        }
    }

    return count;
}

int main(){
    ifstream fin("source.txt");
    unsigned size;
    int *Arr = read_arr(fin, size);

    clock_t timeStart = clock();
    cout << "Fast: " << count_triplet_sum_fast(Arr, size, 0) << " - time: ";
    clock_t timeStop = clock();

    cout << ((double) (timeStop - timeStart)) * 1000 / CLOCKS_PER_SEC << '\n';
    
    // timeStart = clock();
    // cout << "Slow: " << count_triplet_sum_slow(Arr, size, 0) << " - time: ";
    // timeStop = clock();

    cout << ((double) (timeStop - timeStart)) * 1000 / CLOCKS_PER_SEC << '\n';
}

///         FAST        SLOW
//    10:   ~0          ~0
//  1000:   3           423
//  2000:   12          3,330
//  3000:   31          11,341
//  4000:   50          26,565
//  5000:   77          -
// 10000:   310         -
// 15000:   678         -
// 20000:   1192        -
// 30000:   2659
// 40000:   4812
// 50000:   7566