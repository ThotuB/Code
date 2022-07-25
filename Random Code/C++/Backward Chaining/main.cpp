#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

template <typename T>
class List {
private:
    std::vector<T> items;

public:
    List(std::initializer_list<T> list)
        : items(list)
    {}

    void add(T item) {
        items.push_back(item);
    }

    T& operator[](int index) {
        if (index < 0) {
            return items[items.size() + index];
        }
        if (index >= items.size()) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

};

class IF {
private:
    std::string conditional;
    std::string action;

public:
    IF(std::string conditional, std::string action)
        : conditional(conditional), action(action) {}

    void apply() {

    }

    std::string antecedent() {
        return conditional;
    }

    std::string consequent() {
        return action;
    }

    friend std::ostream& operator<<(std::ostream& os, const IF& iff) {
        os << "IF(" << iff.conditional << ", " << iff.action << ")";
        return os;
    }
};

template <typename T>
class RuleExpression : public List<T> {

};

template <typename T>
class AND : public RuleExpression<T> {

};

template <typename T>
class OR : public RuleExpression<T> {

};

template <typename T>
class NOT : public RuleExpression<T> {

};

template <typename T>
class THEN : List<T> {

}; 


int main() {
    List<int> list = {1, 2, 3, 4, 5};

    std::cout << list[-1] << std::endl;
}