#ifndef JSON_PRINTER_HPP_
#define JSON_PRINTER_HPP_

#include <iostream>

namespace json {

class Printer {
public:
    Printer() {
        std::cout << "Printer constructor\n";
    }
};

} // namespace json

#endif