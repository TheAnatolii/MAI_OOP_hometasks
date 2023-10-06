#include "five.hpp"

Five &Five::operator=(const Five &other)
{
    _size = other._size;
    _num = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _num[i] = other._num[i];
    }

    return *this;
}

Five Five::operator+(const Five &other)
{
    bool longer = _size >= other._size;
    size_t maxSize, minSize;

    if (longer)
    {
        maxSize = _size;
        minSize = other._size;
    }
    else
    {
        maxSize = other._size;
        minSize = _size;
    }

    Five result = Five(maxSize);

    int ost = 0, ans, num1, num2, sum;
    for (size_t i = 0; i < minSize; ++i)
    {
        num1 = _num[i] - 48;
        num2 = other._num[i] - 48;
        sum = num1 + num2 + ost;
        ost = sum / 5;
        ans = sum % 5;
        result._num[i] = ans + 48;
    }

    for (size_t i = minSize; i < maxSize; ++i)
    {
        num1 = longer ? _num[i] - 48 : other._num[i] - 48;
        sum = num1 + ost;
        ost = sum / 5;
        ans = sum % 5;
        result._num[i] = ans + 48;
    }

    if (ost != 0)
    {
        ++result._size;
        result._resize();
        result._num[maxSize] = ost + 48;
    }

    return result;
}

Five Five::operator-(const Five &other)
{
    if (other._size > _size)
    {
        throw std::invalid_argument("The result will be negative!\n");
    }

    Five answer = Five(*this);

    for (size_t i = other._size - 1; i < other._size; --i)
    {
        answer._num[i] = _num[i] - other._num[i] + '0';

        if (answer._num[i] < '0')
        {
            answer._num[i] += 5;

            size_t index = i + 1;
            while (index < answer._size and answer._num[index] == '0')
            {
                answer._num[index] = '4';
                index++;
            }

            if (index == answer._size)
            {
                throw std::invalid_argument("The result will be negative!\n");
            }

            answer._num[index]--;
            if (index + 1 == answer._size && answer._num[index] == '0')
            {
                --answer._size;
                answer._resize();
            }
        }
    }
    return answer;
}