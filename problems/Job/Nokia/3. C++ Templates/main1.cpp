#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    unsigned size;
    unsigned capacity;
    std::vector<T> data;

public:
    Vector() : size(0), capacity(10) {}
    Vector(const Vector<T>& other)
        : size(other.size), capacity(other.capacity), data(other.data) {}
    Vector(Vector<T>&& other)
        : size(other.size), capacity(other.capacity), data(std::move(other.data)) {}

    Vector<T>& operator=(const Vector<T>& other) {
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other) {
        size = other.size;
        capacity = other.capacity;
        data = std::move(other.data);
        return *this;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            data.resize(capacity);
        }
        data.push_back(value);
        size++;
    }

    void insert(unsigned index, const T& value) {
        if (size == capacity) {
            capacity *= 2;
            data.resize(capacity);
        }
        data.insert(data.begin() + index, value);
        ++size;
    }

    T& operator[](unsigned index) {
        return data[index];
    }
};

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(1, 4);
    std::cout << v[1] << std::endl;
    return 0;
}