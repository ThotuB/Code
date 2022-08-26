#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {5, 7, 2, 9, 1, 3, 0, 4, 6};

    std::cout << "Find element: " << *std::find(v.begin(), v.end(), 2) << std::endl;

    std::cout << "Find if: " << *std::find_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) << std::endl;
    std::cout << "Find if not: " << *std::find_if_not(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) << std::endl;

    std::cout << "Find end: " << *std::find_end(v.begin(), v.end(), v.begin(), v.end()) << std::endl;
    std::cout << "Find first of: " << *std::find_first_of(v.begin(), v.end(), v.begin(), v.end()) << std::endl;

    std::cout << "Adjacent find: " << *std::adjacent_find(v.begin(), v.end()) << std::endl;
}