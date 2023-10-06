# Лабораторная работа 2. Классы
## Автор: Головенко Анатолий, группа М8О-212Б-22, вариант 6

Используя в качестве образца класс Array (см. ниже), реализовать динамические контейнеры с использова- нием динамического массива.
- Каждый класс должен быть разделен на интерфейс и реализацию.
- Самостоятельно определить необходимые типы, поля и дополнительные методы.
- Реализовать генерацию исключений в конструкторах и методах при необходимости (использовать стандартные исключения).
- Реализовать арифметические операции: сложение, вычитание, копирование
- Реализовать операции сравнения: (больше, меньше, равно).
- Арифметические операции с присваиванием должны быть реализованы как методы класса.

Создать класс Five для работы с беззнаковыми целыми пятиричными числами, используя для представления числа массив из элементов типа unsigned char, каждый элемент которого является пятеричной цифрой. Младшая цифра имеет меньший индекс (единицы — в нулевом элементе массива).

## Программы

### five.hpp
```
#include <string>

class Five
{
private:
    unsigned char *_num;
    size_t _size;
    void _resize();

public:
    Five();
    Five(const size_t &n, unsigned char t = 0);
    Five(const std::initializer_list<unsigned char> &t);
    Five(const std::string &t);
    Five(const Five &other);
    Five(Five &&other) noexcept;
    virtual ~Five() noexcept;

    unsigned char *get_value();
    size_t get_size();
    std::string get_value_string();

    bool operator==(const Five &other);
    bool operator<(const Five &other);
    bool operator>(const Five &other);

    Five &operator=(const Five &other);
    Five operator+(const Five &other);
    Five operator-(const Five &other);
};

```

### five_constructors.cpp
```
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

```

### five_algebra_operators.cpp
```
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
```

### five_bool_operators.cpp
```
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

```

### five_gets.cpp
```
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
```

### seven_private.cpp
```
#include "five.hpp"

void Five::_resize()
{
    unsigned char *resized = new unsigned char[_size]{};

    for (size_t i = 0; i < _size; ++i)
    {
        resized[i] = _num[i];
    }
    delete _num;
    _num = resized;
}
```

### tests.cpp
```
#include <gtest/gtest.h>
#include "five.hpp"

TEST(Constructors, test)
{
    Five test = Five();
    EXPECT_EQ(test.get_value_string(), "\0");
    EXPECT_EQ(test.get_size(), 0);
}

TEST(Constructors, n_t)
{
    Five test = Five(3, '1');
    EXPECT_EQ(test.get_value_string(), "111");
    EXPECT_EQ(test.get_size(), 3);
}

TEST(Constructors, n_and_t_bad_wrong_digit)
{
    EXPECT_ANY_THROW(Five num = Five(10, '9'));
}

TEST(Constructors, n_and_t_bad_letter)
{
    EXPECT_ANY_THROW(Five num = Five(10, 'b'));
}

TEST(Constructors, initializer_list_not_empty)
{
    Five num = Five({'1', '2'});
    EXPECT_EQ(num.get_size(), 2);
    EXPECT_EQ(num.get_value_string(), "12");
}

TEST(Constructors, initializer_list_empty)
{
    Five num = Five({});
    EXPECT_EQ(num.get_size(), 0);
    EXPECT_EQ(num.get_value_string(), "");
}

TEST(Constructors, initializer_list_exception)
{
    EXPECT_ANY_THROW(Five num = Five({'a', '2'}));
}

TEST(Constructors, initializer_another_exception)
{
    EXPECT_ANY_THROW(Five num = Five({'7', '2'}));
}

TEST(Constructors, string_filled)
{
    Five num = Five("12");
    EXPECT_EQ(num.get_value_string(), "12");
    EXPECT_EQ(num.get_size(), 2);
}

TEST(Constructors, string_empty)
{
    Five num = Five("");
    EXPECT_EQ(num.get_value_string(), "");
    EXPECT_EQ(num.get_size(), 0);
}

TEST(Constructors, string_exception)
{
    EXPECT_ANY_THROW(Five num = Five("a2"));
}

TEST(Constructors, string_another_exception)
{
    EXPECT_ANY_THROW(Five num = Five("72"));
}

TEST(Constructors, copy)
{
    Five num = Five("12");
    Five num2 = Five(num);
    num = Five("34");
    EXPECT_EQ(num2.get_value_string(), "12");
    EXPECT_EQ(num.get_value_string(), "34");
}

TEST(Constructors, rvalue_copy)
{
    Five num = Five(Five("12"));
    EXPECT_EQ(num.get_value_string(), "12");
}

// Operators testing

TEST(Operators, sum_normal)
{
    Five num = Five("12");
    Five num2 = Five("12");
    EXPECT_EQ((num + num2).get_value_string(), "24");
}

TEST(Operators, sum_overboard)
{
    Five num = Five("14");
    Five num2 = Five("12");
    EXPECT_EQ((num + num2).get_value_string(), "31");
}

TEST(Operators, sum_changeable_size)
{
    Five num = Five("3");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "12");
}

TEST(Operators, sum_zero)
{
    Five num = Five("0");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "4");
}

TEST(Operators, sum_empty)
{
    Five num = Five("");
    Five num2 = Five("4");
    EXPECT_EQ((num + num2).get_value_string(), "4");
}

TEST(Operators, sub_normal)
{
    Five num = Five("24");
    Five num2 = Five("12");
    EXPECT_EQ((num - num2).get_value_string(), "12");
}

TEST(Operators, sub_with_transfer)
{
    Five num = Five("21");
    Five num2 = Five("12");
    EXPECT_EQ((num - num2).get_value_string(), "4");
}

TEST(Operators, sub_uneven_transfer)
{
    Five num = Five("12000");
    Five num2 = Five("1");
    EXPECT_EQ((num - num2).get_value_string(), "11444");
}

TEST(Operators, sub_exception)
{
    Five num = Five("12000");
    Five num2 = Five("1");
    EXPECT_ANY_THROW(num2 - num);
}

TEST(Operators, sub_uneven_transfer_2)
{
    Five num = Five("12000");
    Five num2 = Five("111");
    EXPECT_EQ((num - num2).get_value_string(), "11334");
}

TEST(Operators, sub_uneven_transfer_3)
{
    Five num = Five("12000");
    Five num2 = Five("110");
    EXPECT_EQ((num - num2).get_value_string(), "11340");
}

TEST(Operators, sub_zero)
{
    Five num = Five("12000");
    Five num2 = Five("0");
    EXPECT_EQ((num - num2).get_value_string(), "12000");
}

TEST(Operators, sub_empty)
{
    Five num = Five("12000");
    Five num2 = Five("");
    EXPECT_EQ((num - num2).get_value_string(), "12000");
}

TEST(Operators, assignment)
{
    Five num;
    num = Five("12");
    EXPECT_EQ(num.get_value_string(), "12");
}

TEST(Operators, comparison)
{
    Five num = Five("12");
    Five num2 = Five("11");
    EXPECT_TRUE(num > num2);
    EXPECT_FALSE(num < num2);
    EXPECT_TRUE(num2 < num);
    EXPECT_FALSE(num2 > num);
}

TEST(Operators, equality)
{
    Five num = Five("12");
    Five num2 = num;
    EXPECT_TRUE(num == num2);
    EXPECT_FALSE(num > num);
}

```