#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Values
    int a = 2;
    int b = 5;

    std::cout << std::min(a, b) << std::endl;
    std::cout << std::max(a, b) << std::endl;

    auto min_max = std::minmax(a, b);

    std::cout << min_max.first << " " << min_max.second << std::endl;

    // Ranges
    std::vector<int> v = {5, 7, 2, 9, 1, 3, 0, 4, 6};

    auto min_elem = std::min_element(v.begin(), v.end());
    std::cout << "Min: " << *min_elem << std::endl;
    
    auto max_elem = std::max_element(v.begin(), v.end());
    std::cout << "Max: " << *max_elem << std::endl;

    auto min_max_elem = std::minmax_element(v.begin(), v.end());

    std::cout << "Min: " << *min_max_elem.first << std::endl;
    std::cout << "Max: " << *min_max_elem.second << std::endl;
}