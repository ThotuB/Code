#include <iostream>
#include <vector>
#include <functional>
#include <chrono>

using namespace std;
using uint32 = unsigned;
using uint64 = unsigned long long; 

uint64 Fibonacci_Recursive(uint32 n) {
    if (n <= 1) {
        return n;
    }
    return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2);
}

uint64 Fibonacci_Recursive_Dynamic(uint32 n){
    vector<uint64> fib_list = {0, 1};

    function<uint64(uint32)> Fib = [&fib_list, &Fib](uint32 n) {
        if ( n < fib_list.size() ) {
            return fib_list[n];
        }

        uint64 fib_n = Fib(n-1) + Fib(n-2);
        fib_list.push_back(fib_n);
        
        return fib_n;
    };
    
    return Fib(n);
}

uint64 Fibonacci_Iterative(uint32 n){
    uint64 *fib_arr = new uint64[n+1];
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (uint32 i = 2 ; i <= n ; i++){
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }

    return fib_arr[n];
}

uint64 Fibonacci_Iterative_Space_Efficient(uint32 n){
    uint64 fib_arr[] = {0, 1};

    for (uint32 i = 2 ; i <= n ; i++){
        uint64 temp = fib_arr[0] + fib_arr[1];
        fib_arr[0] = fib_arr[1];
        fib_arr[1] = temp;
    }

    if ( n == 0 ) {
        return fib_arr[0];
    }
    return fib_arr[1];
}

uint64 Comb(uint32 n, uint32 r) {
    if(r > n - r) r = n - r;
    uint64 ans = 1;

    for(uint32 i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

uint64 Fibonacci_Iterative_Combinations(uint32 n){
    n--;
    uint64 fib = 0;

    for (uint32 k = 0 ; k <= n/2 + 1 ; k++){
        fib += Comb(n - k, k);
    }

    return fib;
}

void Time_Function(function<uint64(uint32)> func, uint32 n, uint32 iter){

    auto start = chrono::high_resolution_clock::now();
    for (uint32 i = 0 ; i < iter ; i++){
        func(n);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}

int main() {
    uint32 n = 50;
    uint32 iter = 1000000;

    cout << "Fibonacci_Recursive_Dynamic: ";
    Time_Function(Fibonacci_Recursive_Dynamic, n, iter);
    cout << "Fibonacci_Iterative: ";
    Time_Function(Fibonacci_Iterative, n, iter);
    cout << "Fibonacci_Iterative_Space_Efficient: ";
    Time_Function(Fibonacci_Iterative_Space_Efficient, n, iter);
    cout << "Fibonacci_Iterative_Combinations: ";
    Time_Function(Fibonacci_Iterative_Combinations, n, iter);
}