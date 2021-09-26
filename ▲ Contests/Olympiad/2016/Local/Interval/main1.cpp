#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
using uint = unsigned;

struct Interval {
    uint boundry;
    uint nrPrimes;
    uint index;

    friend ostream& operator << (ostream& os, const Interval& pb) {
        return os << pb.boundry << " " << pb.nrPrimes << " " << pb.index;
    }
};

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

vector<uint> SortIntervals(vector<Interval>& intervals) {
    vector<uint> mapping = vector<uint>(intervals.size());

    sort(intervals.begin(), intervals.end(), [&mapping](const Interval& a, const Interval& b) {
        if ( a.boundry < b.boundry ) {
            return true;
        }
        return false;
    });

    for (uint i = 0; i < intervals.size(); ++i) {
        mapping[intervals[i].index] = i;
    }

    return mapping;
}

uint MostPrimesInIntervals(vector<Interval>& intervals) {
    SortIntervals(intervals);

    for (uint i = 1; i < intervals.size(); ++i) {
        uint primes = PrimesInInterval(intervals[i-1].boundry, intervals[i].boundry);
        intervals[i].nrPrimes = primes + intervals[i-1].nrPrimes;
    }

    // uint maxPrimes = 0;


    return 0;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    uint n;
    vector<Interval> intervals; 

    fin >> n;
    for (uint i = 0; i < n ; ++i) {
        uint boundry;
        fin >> boundry;
        intervals.push_back({boundry, 0, i});
    }

    cout << MostPrimesInIntervals(intervals) << endl;

    return 0;
}