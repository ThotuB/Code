#include <iostream>
#include <vector>

using namespace std;

enum Color {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

std::string getColorName(Color c) {
    switch (c) {
        case Color::RED:
            return "Red";
        case Color::GREEN:
            return "Green";
    }
}

int main() {
    Color c;
    std::cout << c; // 0

    c = (Color)4;

    std::cout << c; // 4

    std::cout << getColorName(c); // (empty)

    c = Color::GREEN;

    std::cout << c; // 1

    std::cout << getColorName(c); // Green
}