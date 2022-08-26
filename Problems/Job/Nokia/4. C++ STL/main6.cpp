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
    std::vector<int> arrCopy;

    // copy odd
    std::copy_if(arr.begin(), arr.end(), std::back_inserter(arrCopy), [](int nr) { return nr % 2 == 1; });
    print(arrCopy);

    // replace odd
    // std::replace_if(arr.begin(), arr.end(), [](int nr) { return nr % 2 == 1; }, 0);

    // remove number greater than 4
    std::remove_if(arr.begin(), arr.end(), [](int nr) { return nr > 4; });

    print(arr);
}