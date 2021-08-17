#include <iostream>

#include "bits.h"

using namespace std;

int main() {
    Bits<5> x(23);
    Bits<5> y(3);

    Bits<6> z = x + y;
    cout << x << "\n"
         << y << "\n"
         << z << '\n';
}