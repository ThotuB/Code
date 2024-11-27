#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

int main() {
    std::array<int, 4> arr = {4, 6, 8, 1};

    auto minElemIterator = std::min_element(arr.begin(), arr.end());
    auto maxElemIterator = std::max_element(arr.begin(), arr.end());

    std::cout << "Min element: " << *minElemIterator << std::endl;
    std::cout << "Max element: " << *maxElemIterator << std::endl;
    std:: cout << "Distance: " << std::distance(minElemIterator, maxElemIterator) << std::endl;

    auto minmaxElemIteratorPair = std::minmax_element(arr.begin(), arr.end());

    std::cout << "Min element: " << *minmaxElemIteratorPair.first << std::endl;
    std::cout << "Max element: " << *minmaxElemIteratorPair.second << std::endl;

    std::cout << "Accumulate sum: " << std::accumulate(arr.begin(), arr.end(), 0) << std::endl;
    std::cout << "Accumulate product: " << std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<int>()) << std::endl;
    std::cout << "Accumulate sum of squares: " << std::accumulate(arr.begin(), arr.end(), 0, [](int acc, int nr) { return acc + nr * nr; }) << std::endl;
}