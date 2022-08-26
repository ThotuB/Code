#include <iostream>
#include <functional>
#include <vector>

int sortNormal(int nr1, int nr2) {
    return nr1 > nr2;
}

int sortByLastDigit(int nr1, int nr2) {
    return nr1 % 10 > nr2 % 10;
}

int digitSum(int nr) {
    int sum = 0;
    for (; nr > 0; nr /= 10) {
        sum += nr % 10;
    }
    return sum;
}

int sortByDigitSum(int nr1, int nr2) {
    return digitSum(nr1) > digitSum(nr2);
}

class Data {
public:
    Data(std::vector<int>& data) : data_(data) {}

    void sortNormal(bool ascending) {
        if (ascending) {
            bubble([](int a, int b) -> int { return a > b; });
        } else {
            bubble([](int a, int b) -> int { return a < b; });
        }
    }

    void sortByLastDigit(bool ascending) {
        if (ascending) {
            bubble([](int a, int b) -> int { return a % 10 > b % 10; });
        } else {
            bubble([](int a, int b) -> int { return a % 10 < b % 10; });
        }
    }

    void sortBySum() {
        bubble([](int a, int b) -> int { 
            auto sumDigit = [](int nr) -> int {
                int sum = 0;
                for (; nr > 0; nr /= 10) {
                    sum += nr % 10;
                }
                return sum;
            };
            return sumDigit(a) > sumDigit(b); 
        });
    }

    void print() {
        for (auto& nr : data_) {
            std::cout << nr << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> data_;

    void bubble(std::function<int (int, int)> compare) {
        int arrSize = data_.size();

        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize - i - 1; j++) {
                if (compare(data_[j], data_[j + 1])) {
                    std::swap(data_[j], data_[j + 1]);
                }
            }
        }
    }
};

int main() {
    std::vector<int> data = { 244, 57, 78, 331, 9, 212, 6 };

    Data d(data);
    d.sortNormal(true);
    d.print();
    d.sortNormal(false);
    d.print();
    d.sortByLastDigit(true);
    d.print();
    d.sortByLastDigit(false);
    d.print();

    return 0;
}