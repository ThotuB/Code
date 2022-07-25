#include <iostream>
#include <vector>

int main() {
    std::vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    for (int i = 0; i < 32; ++i) {
        std::cout << "Size: " << v.size() << "\tCapacity: " << v.capacity() << '\n';
        v.push_back(i);
    }
}