#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void print(const std::vector<int>& vec) {
    for (auto nr : vec) {
        std::cout << nr << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {4, 6, 3, 8, 1};
    
    // rotate array
    std::rotate(arr.begin(), arr.begin() + 1, arr.end());

    // reverse copy
    std::vector<int> arrCopy;
    std::reverse_copy(arr.begin(), arr.end(), std::back_inserter(arrCopy));
    print(arrCopy);

    // generate array from index
    std::vector<int> arrGen(6);
    std::generate(arrGen.begin(), arrGen.end(), [n = 0]() mutable { return n++; });
    print(arrGen);
    
    // transform square
    std::vector<int> arrSquare(arr.size());
    std::transform(arr.begin(), arr.end(), arrSquare.begin(), [](int nr) { return nr * nr; });
    print(arrSquare);

    // transform square root
    std::vector<int> arrSqrt(arr.size());
    std::transform(arr.begin(), arr.end(), arrSqrt.begin(), [](int nr) { return sqrt(nr); });
    print(arrSqrt);
}