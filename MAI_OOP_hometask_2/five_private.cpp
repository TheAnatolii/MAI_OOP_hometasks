#include "five.hpp"

void Five::_resize()
{
    unsigned char *resized = new unsigned char[_size]{};

    for (size_t i = 0; i < _size; ++i)
    {
        resized[i] = _num[i];
    }
    delete[] _num;
    _num = resized;
}