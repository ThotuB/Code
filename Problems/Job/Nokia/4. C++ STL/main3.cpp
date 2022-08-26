#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <string>

int main() {
    std::array<int, 4> arr = {4, 6, 8, 1};
    std::string str = "the quick brown fox jumps over the lazy dog";

    std::cout << "Count odd: " << std::count_if(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; }) << std::endl;

    std::array<std::string, 3> terms = { "fox", "dog", "bear" };
    for (auto term : terms) {
        std::cout << "Search " << term << ": " << std::search(str.begin(), str.end(), term.begin(), term.end()) - str.begin() << std::endl;
    }
}