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
    uint maxInterval = 0;

    for (uint i = 0; i < boundries.size() - 1; ++i) {
        uint a = min(boundries[i], boundries[i + 1]);
        uint b = max(boundries[i], boundries[i + 1]);

        uint interval = b - a + 1;
        if (interval > maxInterval) {
            maxInterval = interval;
            left = a;
            right = b;
        }
    }

    cout << PrimesInInterval(left, right) << endl;

    return 0;
}