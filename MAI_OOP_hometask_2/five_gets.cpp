#include "five.hpp"

unsigned char *Five::get_value()
{
    return _num;
}

std::string Five::get_value_string()
{
    std::string answer = "";
    for (size_t i = _size - 1; i < _size; --i)
    {
        answer += _num[i];
    }
    return answer;
}

size_t Five::get_size()
{
    return _size;
}