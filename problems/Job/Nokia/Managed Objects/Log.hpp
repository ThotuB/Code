#ifndef LOG_HPP_
#define LOG_HPP_

#include <string>

class Log {
public:
    Log();
    ~Log();
    void log(const std::string& message);
};

#endif