#include "five.hpp"
#include <string>
#include <exception>

Five::Five()
{
    _size = 0;
    _num = new unsigned char[0]{};
}

Five::Five(const size_t &n, unsigned char t)
{
    if (t != 0 and (t < 48 or t > 52))
    {
        throw std::invalid_argument("Your symbol is not in five-digit number system!\n");
    }

    _size = n;
    _num = new unsigned char[n]{};
    std::fill(_num, _num + _size, t);
}

Five::Five(const std::initializer_list<unsigned char> &t)
{
    _size = t.size();
    _num = new unsigned char[_size]{};
    size_t position = _size - 1;
    for (const unsigned char &letter : t)
    {
        if (letter != 0 and (letter < 48 or letter > 52))
        {
            throw std::invalid_argument("Your symbol is not in five-digit number system!\n");
        }
        _num[position--] = letter;
    }
}

Five::Five(const std::string &t)
{
    _size = t.size();
    _num = new unsigned char[_size]{};
    size_t position = _size - 1;
    for (const unsigned char &letter : t)
    {
        if (letter != 0 and (letter < 48 or letter > 52))
        {
            throw std::invalid_argument("Your symbol is not in five-digit number system!\n");
        }
        _num[position--] = letter;
    }
}

Five::Five(const Five &other)
{
    _size = other._size;
    _num = new unsigned char[_size];

    for (size_t i = 0; i != _size; ++i)
    {
        _num[i] = other._num[i];
    }
}

Five::Five(Five &&other) noexcept
{
    _size = other._size;
    _num = new unsigned char[_size];

    for (size_t i = 0; i != _size; ++i)
    {
        _num[i] = other._num[i];
    }

    delete other._num;
    other._size = 0;
}

Five::~Five() noexcept
{
    _size = 0;
    delete _num;
}