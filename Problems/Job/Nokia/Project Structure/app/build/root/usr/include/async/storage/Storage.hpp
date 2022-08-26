#ifndef STORAGE_HPP_
#define STORAGE_HPP_

#include <iostream>

namespace async 
{

namespace storage 
{

class Storage
{
public:
    Storage() {
        std::cout << "Storage constructor\n";
    }
};

} // namespace storage
} // namespace async

#endif