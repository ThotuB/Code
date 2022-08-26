#include <iostream>
#include <algorithm>
#include <vector>

void print(const std::vector<int>& vec) {
    for (auto nr : vec) {
        std::cout << nr << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {2, 4, 6, 3, 8, 5, 1};

    // sort array
    // std::sort(arr.begin(), arr.end());

    // partial sort array
    // std::partial_sort(arr.begin(), arr.begin() + 3, arr.end());

    // nth element
    std::nth_element(arr.begin(), arr.begin() + 3, arr.end());

    print(arr);
}