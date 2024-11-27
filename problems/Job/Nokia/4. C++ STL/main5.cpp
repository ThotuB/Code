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

    // partition even and odd
    // std::partition(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; });

    // stable partition even and odd
    std::stable_partition(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; });

    print(arr);
}