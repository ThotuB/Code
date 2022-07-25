#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> filteredNums;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(filteredNums), [](int num) {
        return num % 2 == 0;
    });
    
    int factor = 3;
    std::for_each(filteredNums.begin(), filteredNums.end(), [&factor](int &n) {
        n *= factor;
    });

    for (auto n : filteredNums) {
        std::cout << n << " ";
    }

    // calculate sum
    int sum = 0;
    std::for_each(filteredNums.begin(), filteredNums.end(), [&sum](int n) {
        sum += n;
    });

    std::cout << std::endl << "Sum: " << sum << std::endl;
}