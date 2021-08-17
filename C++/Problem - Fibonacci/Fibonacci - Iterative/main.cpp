#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

/// EFICIENCY & COMPLEXITY
clock_t tic, toc;
long long unsigned steps = 0;

long long unsigned fibonacci(unsigned n) {
    long long unsigned fib[2] = {0, 1};

    if (n > 1) {
        for (unsigned i = 1; i < n; i++) {
            steps++;

            long long sum = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = sum;
        }
    } else {
        return fib[n];
    }
    return fib[1];
}

int main() {
    unsigned iter;

    cout << "iter: ";
    cin >> iter;

    tic = clock();
    cout << "Fibonacci [" << iter << "] = " << fibonacci(iter) << "\n";
    toc = clock();

    cout << " -Time: " << toc - tic << "ms\n";
    cout << " -Steps: " << steps;
}
