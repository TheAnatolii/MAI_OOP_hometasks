#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>
#include <deque>

template <typename T, size_t max_count = 500000>
class Allocator
{
private:
    std::deque<T> _used_blocks;
    typename std::deque<T>::iterator _free_blocks;
    // uint64_t _free_count;

public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    Allocator() : _used_blocks(max_count)
    {
        _free_blocks = _used_blocks.begin();
    }

    ~Allocator() = default;

    T *allocate(size_t n)
    {
        T *result = nullptr;
        if (_used_blocks.end() != _free_blocks)
        {
            result = &(*_free_blocks);
        }
        else
        {
            std::cout << "allocator: No memory exception :-)" << std::endl;
        }
        return result;
    }

    void deallocate(T *pointer, size_t)
    {
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p)
    {
        p->~T();
    }
};

template <class T, class U>
constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return true;
}

template <typename T, typename U, size_t BLOCK_COUNT>
constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return false;
}
