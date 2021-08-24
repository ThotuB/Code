#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> A) {
    unordered_map<int, int> mappedA;

    for (int i = 0; i < A.size(); i++) {
        mappedA[A[i]] = 1;
    }

    int missing = 1;
    while (true) {
        if (mappedA.find(missing) == mappedA.end()) {
            return missing;
        }
        missing++;
    }

    return 0;
}

vector<int> read_inputs(string fileName) {
    ifstream file(fileName);

    vector<int> A;
    int nr;
    while ( file >> nr ) {
        A.push_back(nr);
    }

    return A;
}

int main() {
    vector<int> vec = read_inputs("input.txt");
    cout << solution(vec);
}