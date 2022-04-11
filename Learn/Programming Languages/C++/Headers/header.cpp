#include "header.hpp"
#include <iostream>

using namespace header_namespace;

HeaderClass::HeaderClass() {
    std::cout << "HeaderClass::HeaderClass()" << std::endl;
}

HeaderClass::~HeaderClass() {
    std::cout << "HeaderClass::~HeaderClass()" << std::endl;
}