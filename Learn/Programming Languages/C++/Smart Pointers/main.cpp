#include <iostream>
#include <memory>

int main() {
    // Unique pointer
    std::unique_ptr<int> uptr1(new int(42));
    std::unique_ptr<int> uptr2(std::move(uptr1));

    std::cout << "GET\n";
    std::cout << "Unique Pointer 1: " << uptr1.get() << '\n';
    std::cout << "Unique Pointer 2: " << uptr2.get() << '\n';

    std::unique_ptr<int> uptr3(new int(125));

    std::cout << "RELEASE\n";
    std::cout << "Unique Pointer: " << uptr3.release() << '\n';
    std::cout << "Unique Pointer: " << uptr3.get() << '\n';

    std::cout << "RESET\n";
    uptr3.reset(new int(42));
    std::cout << "Unique Pointer: " << uptr3.get() << '\n';

    // Shared pointer
    std::shared_ptr<int> sptr1(new int(42));
    std::shared_ptr<int> sptr2(sptr1);

    std::cout << "Shared Pointer 1: " << sptr1.get() << '\n';
    std::cout << "Shared Pointer 2: " << sptr2.get() << '\n';

    std::cout << "Count: " << sptr1.use_count() << '\n';

    // Weak pointer
    std::weak_ptr<int> wptr1(sptr1);
    std::weak_ptr<int> wptr2(sptr2);

    std::cout << "Weak Pointer 1: " << wptr1.lock() << '\n';
    std::cout << "Weak Pointer 2: " << wptr2.lock() << '\n';

    std::cout << "Count: " << sptr1.use_count() << '\n';
}