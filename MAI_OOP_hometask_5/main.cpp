#include <iostream>
#include "vector.hpp"
#include "allocator.hpp"

int main()
{
    Vector<int> p(5, 1);
    p.resize(7);
    p.push_back(4);

    std::cout << ((p.begin() + 1 == p.end()) ? 10 : -10) << std::endl;

    for (auto &elem : p)
    {
        std::cout << elem << std::endl;
    }
}