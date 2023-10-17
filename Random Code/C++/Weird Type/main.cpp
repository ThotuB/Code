#include <memory>

struct SomeStruct {
    int a;
    int b;
    int c;
};

int main() {
    // normal pointer array of normal pointers
    auto arrPtr = new SomeStruct*[10];
    for (int i = 0; i < 10; i++) {
        arrPtr[i] = new SomeStruct[10];
    }

    for (int i = 0; i < 10; i++) {
        delete[] arrPtr[i];
    }
    delete[] arrPtr;

    // smart pointer array of normal pointers
    auto arrSmartPtr = std::make_unique<SomeStruct*[]>(10);
    for (int i = 0; i < 10; i++) {
        arrSmartPtr[i] = new SomeStruct[10];
    }

    // smart pointer array of smart pointers
    auto arrSmartSmartPtr = std::make_unique<std::unique_ptr<SomeStruct[]>[]>(10);
    for (int i = 0; i < 10; i++) {
        arrSmartSmartPtr[i] = std::make_unique<SomeStruct[]>(10);
    }
}