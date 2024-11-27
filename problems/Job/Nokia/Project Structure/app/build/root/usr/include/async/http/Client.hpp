#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <iostream>

namespace async 
{     
namespace http 
{

class Client
{
public:
    Client() {
        std::cout << "Client constructor\n";
    }
};

} // namespace http
} // namespace async

#endif