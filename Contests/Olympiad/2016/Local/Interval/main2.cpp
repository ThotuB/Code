// Greedy Version
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using uint = unsigned;

bool IsPrime(uint n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (uint i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

uint PrimesInInterval(uint a, uint b) {
    uint count = 0;
    for (uint i = a; i <= b; ++i) {
        if ( IsPrime(i) ) {
            count++;
        }
    }
    return count;
}

float ApproxPrimesLessThan(uint n) {
    return (float) n / log(n);
}

float ApproxPrimesInInterval(uint a, uint b) {
    return ApproxPrimesLessThan(b) - ApproxPrimesLessThan(a - 1);
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    uint n;
    vector<uint> boundries;

    fin >> n;
    for (uint i = 0; i < n ; ++i) {
        uint boundry;
        fin >> boundry;
        boundries.push_back(boundry);
    }

    uint left = 0, right = 0;
    float maxApproxPrimes = 0.0;

    for (uint i = 0; i < boundries.size() - 1; ++i) {
        uint a = min(boundries[i], boundries[i + 1]);
        uint b = max(boundries[i], boundries[i + 1]);

        float approxPrimes = ApproxPrimesInInterval(a, b);
        if ( approxPrimes > maxApproxPrimes ) {
            maxApproxPrimes = approxPrimes;
            left = a;
            right = b;
        }
    }

    cout << PrimesInInterval(left, right) << endl;

    return 0;
}