#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <iostream>

namespace async {

class Config {
public:
    Config() {
        std::cout << "Config constructor\n";
    }
};

} // namespace async

#endif