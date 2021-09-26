#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using uint = unsigned;

void InitCounters(uint nr, set<uint> &digitSet, array<uint, 2> &oddEvenCounter) {
    while (nr > 0) {
        digitSet.insert(nr % 10);
        oddEvenCounter[nr % 2]++;
        nr /= 10;
    }
}

bool IsComplementary(uint num, set<uint> digitSet, array<uint, 2> oddEvenCounter) {
    set<uint> complementDigitSet;
    
    while (num > 0) {
        if (digitSet.find(num % 10) != digitSet.end()) {
            return false;
        }
        complementDigitSet.insert(num % 10);
        oddEvenCounter[num % 2]++;

        num /= 10;
    }

    return (digitSet.size() + complementDigitSet.size() == 10) && (oddEvenCounter[0] == oddEvenCounter[1]);   
}

uint LargestComplementaryNumber(uint nr, vector<uint> nums) {
    uint maxCompl = 0;

    set<uint> nrDigitSet;
    array<uint, 2> oddEvenCounter = {0, 0};
    
    InitCounters(nr, nrDigitSet, oddEvenCounter);

    for (uint num : nums) {
        bool isCompl = IsComplementary(num, nrDigitSet, oddEvenCounter);

        if (isCompl && num > maxCompl) {
            maxCompl = num;
        }
    }

    return maxCompl;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    vector<uint> nums;
    uint nr, num;
    fin >> nr;
    while (fin >> num) {
        nums.push_back(num);
    }

    fout << LargestComplementaryNumber(nr, nums) << endl;

    return 0;
}