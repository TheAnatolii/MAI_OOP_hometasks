#include "five.hpp"

bool Five::operator==(const Five &other)
{
    if (_size != other._size)
    {
        return false;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        if (_num[i] != other._num[i])
        {
            return false;
        }
    }
    return true;
}

bool Five::operator<(const Five &other)
{
    if (_size < other._size)
    {
        return true;
    }

    if (_size > other._size)
    {
        return false;
    }

    for (size_t i = _size - 1; i < _size; --i)
    {
        if (_num[i] > other._num[i])
        {
            return false;
        }
        if (_num[i] < other._num[i])
        {
            return true;
        }
    }
    return false;
}

bool Five::operator>(const Five &other)
{
    if (_size > other._size)
    {
        return true;
    }
    if (_size < other._size)
    {
        return false;
    }

    for (size_t i = _size - 1; i < _size; --i)
    {
        if (_num[i] > other._num[i])
            return true;
        if (other._num[i] > _num[i])
            return false;
    }

    return false;
}