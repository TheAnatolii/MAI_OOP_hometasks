#include <iostream>
#include "vector.hpp"
#include "allocator.hpp"
#include <map>
#include <vector>

int main()
{
    // MAP DOESN'T WORK ON MAP WITH MY OWN ALLOCATOR
    // using alloc_traits = std::allocator_traits<Allocator<std::pair<const int, int>>>;

    // std::map<int, int, alloc_traits> m;
    std::vector<int, Allocator<int>> v;
    for (size_t i = 1; i != 10; ++i)
    {
        v[i] = v[i - 1] * i;
    }

    std::cout << "Here are the elements of a vector: " << std::endl;
    for (size_t i = 0; i != 10; ++i)
    {
        std::cout << i << " " << v[i] << std::endl;
    }
    std::cout << std::endl;
}