#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

int main() {
    std::array<int, 4> arr = {4, 6, 8, 1};

    std::cout << "All odd: " << std::all_of(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; }) << std::endl;
    std::cout << "Any odd: " << std::any_of(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; }) << std::endl;

    std::cout << "Find number: " << std::find(arr.begin(), arr.end(), 8) - arr.begin() << std::endl;
    std::cout << "Find number if: " << std::find_if(arr.begin(), arr.end(), [](int nr) { return nr > 7; }) - arr.begin() << std::endl;
}