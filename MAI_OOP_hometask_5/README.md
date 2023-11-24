# Лабораторная работа 5. Итераторы и аллокаторы
## Автор: Головенко Анатолий, группа М8О-212Б-22, вариант 6
1. Аллокатор
- a. Реализовать свой аллокатор памяти. Проверить что он корректно работает для контейнера std::map.
- b. Аллокатор должен параметризоваться количеством выделяемых за раз элементов.
- c. Освобождение конкретного элемента не предполагается - аллокатор должен освобождать всю память самостоятельно.
2. Контейнер
- a. Реализовать свой контейнер (согласно варианта задания), который по аналогии с контейнерами stl, параметрезуя аллокатором.
3. Итератор
- a. Реализовать итераторы (обычный и const)
- b. Итератор должен соответствовать std::forward_iterator_tag

Прикладной код должен содержать следующие вызовы:
- создание экземпляра std::map с созданным аллокатором
- заполнение 10 элементами, где ключ — это число от 0 до 9, а значение - факториал ключа
- вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
- создание экземпляра своего контейнера для хранения int с собственным vаллокатором – заполнение контейнера и печать его элементов

Вариант 6: Контейнер: Динамические массив, Аллокатор: std::deque

## Программы

### main.cpp
```cpp
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

```

### allocator.hpp
```cpp
#include <iostream>
#include <memory>
#include <utility>
#include <deque>

template <typename T, size_t max_count = 500000>
class Allocator
{
private:
    std::deque<T> _used_blocks;
    typename std::deque<T>::iterator _free_blocks;

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

    template <class U>
    struct rebind
    {
        using other = Allocator<U>;
    };
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

// Allocator<int> a;
// typename std::allocator_traits<Allocator<int>>::rebind_alloc<char>::other b;s
```

### vector.hpp
```cpp
#include <memory>

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
private:
    T *_array;
    size_t _size;
    size_t _capacity;
    Allocator _allocator;
    using alloc_traits = std::allocator_traits<Allocator>;

public:
    using value_type = T;

    class Iterator
    {

    private:
        value_type *_link;

    public:
        friend Vector;

        using difference_type = int;
        using value_type = Vector::value_type;
        using reference = Vector::value_type &;
        using pointer = Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Iterator() : _link(nullptr)
        {
        }

        Iterator(pointer p) : _link(p)
        {
        }

        ~Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator new_one = *this;
            _link -= 1;
            return new_one;
        }

        Iterator operator+(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Iterator operator-(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    class Const_Iterator
    {

    private:
        const value_type *_link;

    public:
        friend Vector;

        using difference_type = int; // в чем меряем расстояние
        using value_type = const Vector::value_type;
        using reference = const Vector::value_type &;
        using pointer = const Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Const_Iterator()
        {
            _link = nullptr;
        }

        Const_Iterator(pointer p) : _link(p)
        {
        }

        ~Const_Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Const_Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Const_Iterator operator++(int)
        {
            Const_Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Const_Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Const_Iterator operator--(int)
        {
            Const_Iterator new_one = *this;
            _link -= 1;
            return new_one;
        }

        Const_Iterator operator+(const int &cnst) const
        {
            Const_Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Const_Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Const_Iterator operator-(const int &cnst) const
        {
            Const_Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Const_Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Const_Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Const_Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    Vector() : _size(0), _capacity(0), _allocator()
    {
    }

    Vector(const size_t &ln, const value_type &elem = T()) : _size(ln), _capacity(ln), _allocator()
    {
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = elem;
        }
    }

    Vector(std::initializer_list<value_type> p) : _size(p.size()), _capacity(p.size()), _allocator()
    {
        _array = alloc_traits::allocate(_allocator, _size);
        size_t i = 0;
        for (const value_type &elem : p)
        {
            _array[i++] = elem;
        }
    }

    Vector(const Vector<value_type, Allocator> &other) : _size(other._size), _capacity(other._capacity),
                                                         _allocator(other._allocator)
    {
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    ~Vector()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i].~T();
        }
        _capacity = 0;
        alloc_traits::deallocate(_allocator, _array, _size);
        _size = 0;
    }

    void resize(size_t ln)
    {
        if (ln > _capacity)
        {
            value_type *_new_array = alloc_traits::allocate(_allocator, _capacity * 2);
            for (size_t i = 0; i < _size; ++i)
            {
                _new_array[i] = _array[i];
            }
            alloc_traits::deallocate(_allocator, _array, _capacity);
            _capacity *= 2;
            _array = _new_array;
            _size = ln;
        }
        else if (ln < _capacity)
        {
            _size = ln;
        }
    }

    const value_type &operator[](size_t index) const
    {
        return _array[index];
    }

    value_type &operator[](size_t index)
    {
        return _array[index];
    }

    void push_back(const value_type &elem)
    {
        if (_size + 1 > _capacity)
        {
            resize(_size + 1);
            _array[_size - 1] = elem;
        }
        else
        {
            _array[++_size - 1] = elem;
        }
    }

    void pop_back()
    {
        resize(_size - 1);
    }

    Vector &operator=(const Vector<value_type, Allocator> &other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    Iterator begin() noexcept
    {
        return Iterator(_array);
    }

    Const_Iterator cbegin() const noexcept
    {
        return Const_Iterator(_array);
    }

    Iterator end()
    {
        return Iterator(_array + _size);
    }

    Const_Iterator cend() const
    {
        return Const_Iterator(_array + _size);
    }

    size_t size()
    {
        return _size;
    }

    size_t capacity()
    {
        return _capacity;
    }
};
```

### tests.cpp
```cpp
#include <iostream>
#include <gtest/gtest.h>
#include "vector.hpp"
#include "allocator.hpp"

TEST(constructors, defaulte)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p;
    EXPECT_EQ(p.size(), 0);
    EXPECT_EQ(p.capacity(), 0);
}

TEST(constructors, size_resize)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    EXPECT_EQ(p.size(), 6);
    EXPECT_EQ(p.capacity(), 6);
    EXPECT_EQ(p[0], 0);
    p.push_back(3);
    EXPECT_EQ(p[p.size() - 1], 3);
}

TEST(constructors, init_lst)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p{1, 2, 3, 4};
    int i = 1;
    for (int &elem : p)
    {
        EXPECT_EQ(elem, i++);
    }
}

TEST(constructors, another_vect)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p{1, 2, 3, 4};
    Vector<int, Allocator<int>> m(p);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_EQ(p[i], m[i]);
    }
}

TEST(constructors, resize)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    p.push_back(3);
    p.pop_back();
    EXPECT_EQ(p[p.size() - 1], 0);
    EXPECT_EQ(p.size(), 6);
    EXPECT_EQ(p.capacity(), 12);
}

TEST(constructors, iters)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    p.push_back(3);
    EXPECT_EQ(p.begin() + 7, p.end());
}

```


### CMakeLists.txt
```cpp
cmake_minimum_required(VERSION 3.10)
project(OOP_MAI)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(googletest)

add_executable(
    vector 
    main.cpp
)

add_executable(
    tests 
    tests.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
```