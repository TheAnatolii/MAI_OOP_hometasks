# Лабораторная работа 04. Основы метапрограммирования
## Автор: Головенко Анатолий, группа М8О-212Б-22, вариант 6

Разработать шаблоны классов согласно варианту задания. Параметром шаблона должен
являться скалярный тип данных задающий тип данных для оси координат. Классы должны иметь
только публичные поля. В классах не должно быть методов, только поля. Фигуры являются
фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника. Для
хранения координат фигур необходимо использовать шаблон std::pair (или реализовать свой
шаблон `template <class T> Point` в качестве параметра шаблона должен быть тип для переменных
координат)

Разработать классы согласно варианту задания, классы должны наследоваться от базового
класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор
общих методов:
1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3. Вычисление площади фигуры;
Создать программу, которая позволяет:
• Запрещается использовать сырые указатели
• Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
• Сохранять созданные фигуры в динамический массив (переиспользовать от
предыдущей лабораторной работы) умных указатели на фигуру
(std::smart_ptr<Figure*>)

• Динамический массив должен быть сделан в виде шаблона (параметр шаблона – класс
для хранения в массиве template <class T> Array {...})
• Фигуры должны иметь переопределенные операции копирования, сравнения и
приведение к типу double (вычисление площади)
• Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для
каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
• Необходимо уметь вычислять общую площадь фигур в массиве.
• Удалять из массива фигуру по индексу;

Вариант 6: 5-угольник, 6-угольник, 8-угольник.

## Программы

### CMakeLists.txt
```cpp
cmake_minimum_required(VERSION 3.10)
project(OOP_MAI)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(googletest)

add_executable(
    figure  
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

### eight_angles.hpp
```cpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Eight_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Eight_Angles()
        : size(8), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Eight_Angles(std::vector<std::pair<T, T>> cord)
        : size(8), coordinates(cord)
    {
    }
    ~Eight_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Eight_Angles<T> &operator=(const Eight_Angles<T> &other);
    Eight_Angles<T> &operator=(Eight_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Eight_Angles<T> &p)
{
    for (int i = 0; i < 8; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Eight_Angles<T> &p)
{

    for (int i = 0; i < 8; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> p.coordinates[i].first;
        std::cout << "y : ";
        is >> p.coordinates[i].second;
    }
    return is;
}

template <typename T>
inline bool operator==(const Eight_Angles<T> &fst, const Eight_Angles<T> &snd)
{
    for (int i = 0; i != 6; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
Eight_Angles<T> &Eight_Angles<T>::operator=(const Eight_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
Eight_Angles<T> &Eight_Angles<T>::operator=(Eight_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
Eight_Angles<T>::operator double() const
{
    return surface<Eight_Angles<T>, T>(*this);
}

```

### figure.hpp
```cpp
#pragma once

#include <utility>
#include <string>
#include <utility>

class Figure
{
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual operator double() const = 0;
};
```

### five_angles.hpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Five_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Five_Angles()
        : size(5), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Five_Angles(std::vector<std::pair<T, T>> cord)
        : size(5), coordinates(cord)
    {
    }
    ~Five_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Five_Angles<T> &operator=(const Five_Angles<T> &other);
    Five_Angles<T> &operator=(Five_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Five_Angles<T> &p)
{
    for (int i = 0; i < 5; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Five_Angles<T> &p)
{

    for (int i = 0; i < 5; ++i)
    {
        // std::cout << "Введите координаты точки " << i + 1 << ":\n";
        // std::cout << "x : ";
        is >> p.coordinates[i].first;
        // std::cout << "y : ";
        is >> p.coordinates[i].second;
    }
    return is;
}

template <typename T>
inline bool operator==(const Five_Angles<T> &fst, const Five_Angles<T> &snd)
{
    for (int i = 0; i != 5; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
inline Five_Angles<T> &Five_Angles<T>::operator=(const Five_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
inline Five_Angles<T> &Five_Angles<T>::operator=(Five_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
inline Five_Angles<T>::operator double() const
{
    return surface<Five_Angles<T>, T>(*this);
}

```

### five_angles.cpp
```cpp
#include "five_angles.hpp"
#include <string>
#include <vector>
#include <cmath>

five_angles::five_angles()
    : x_coordinates({0.0, 0.0, 0.0, 0.0, 0.0}), y_coordinates({0.0, 0.0, 0.0, 0.0, 0.0}), surface(0), mid_dot_x(0), mid_dot_y(0)
{
}

five_angles::five_angles(std::vector<double> &x, std::vector<double> &y)
    : mid_dot_x(0), mid_dot_y(0)
{
    if (x_coordinates.size() != 5)
    {
        x_coordinates.resize(5);
    }

    if (y_coordinates.size() != 5)
    {
        y_coordinates.resize(5);
    }

    for (int i = 0; i < 5; ++i)
    {
        x_coordinates[i] = x[i];
        y_coordinates[i] = y[i];
        mid_dot_x += x[i];
        mid_dot_y += y[i];
    }

    mid_dot_x /= 5;
    mid_dot_y /= 5;

    double length = std::sqrt(std::pow(x[0] - x[1], 2) + std::pow(y[0] - y[1], 2));
    surface = 5 * 0.5 * length * (length / 2) * tan(54);
}

five_angles::~five_angles()
{
    x_coordinates = {};
    y_coordinates = {};
    mid_dot_x = 0;
    mid_dot_y = 0;
    surface = 0;
}

bool five_angles::operator==(five_angles &other) const
{
    if (surface != other.surface)
    {
        return false;
    }
    else
    {
        return true;
    }
}

five_angles &five_angles::operator=(five_angles &other)
{
    x_coordinates = other.x_coordinates;
    y_coordinates = other.y_coordinates;
    mid_dot_x = other.mid_dot_x;
    mid_dot_y = other.mid_dot_y;
    surface = other.surface;
    return *this;
}

five_angles &five_angles::operator=(five_angles &&other)
{
    x_coordinates = std::move(other.x_coordinates);
    y_coordinates = std::move(other.y_coordinates);
    mid_dot_x = std::move(other.mid_dot_x);
    mid_dot_y = std::move(other.mid_dot_y);
    surface = std::move(other.surface);
    return *this;
}
```

### main.cpp
```cpp
#include <iostream>
#include "figure.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"
#include "mass.hpp"

int main()
{
    // five_angles p = five_angles();

    std::vector<double> five_x{0,
                               sqrt(6250 + 1250 * sqrt(5)),
                               -sqrt(6250 + 1250 * sqrt(5)),
                               25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2,
                               -25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2};
    std::vector<double> five_y{100,
                               -25 + 25 * sqrt(5),
                               -25 + 25 * sqrt(5),
                               -25 * sqrt(5) - 25,
                               -25 * sqrt(5) - 25};

    std::vector<double> six_x{2,
                              1,
                              -1,
                              -2,
                              -1,
                              1};
    std::vector<double> six_y{0,
                              sqrt(3),
                              sqrt(3),
                              0,
                              -sqrt(3),
                              -sqrt(3)};

    std::vector<double> eight_x{sqrt(2),
                                1,
                                0,
                                -1,
                                -sqrt(2),
                                -1,
                                0,
                                1};

    std::vector<double> eight_y{0,
                                1,
                                sqrt(2),
                                1,
                                0,
                                -1,
                                -sqrt(2),
                                -1};

    five_angles p = five_angles(five_x, five_y);
    six_angles h = six_angles(six_x, six_y);
    eight_angles l = eight_angles(eight_x, eight_y);

    // std::cin >> p;
    // std::cout << p;
    // point k = h.mid_dot();
    // std::cout << k.x << " " << k.y;
    // std::cout << (double)l;

    mass q = mass(3);
    q.change(0, &p);
    q.change(1, &h);
    q.change(2, &l);

    for (int i = 0; i < 3; ++i)
    {
        const Figure *fig = q[i];
        if (q[i] == nullptr)
        {
            std::cout << "The figure has been deleted" << std::endl;
        }
        else if (typeid(p) == typeid(*fig))
        {
            std::cout << *(five_angles *)q[i];
        }
        else if (typeid(h) == typeid(*fig))
        {
            std::cout << *(six_angles *)q[i];
        }
        else if (typeid(l) == typeid(*fig))
        {
            std::cout << *(eight_angles *)q[i];
        }
    }

    std::cout << "\n\n";

    five_angles ex = five_angles();
    ex = p;
    std::cout << ex;
}
```

### mass.hpp
#pragma once
#include <memory>
#include "figure.hpp"
#include "functions.hpp"

template <class T>
class Massive
{
private:
    std::shared_ptr<T[]> lst;
    int size;

public:
    Massive()
    {
        size = 0;
        lst = nullptr;
    }

    ~Massive()
    {
        size = 0;
        lst = nullptr;
    }

    Massive(int lnght)
    {
        size = lnght;
        lst = std::shared_ptr<T[]>(new T[lnght]);
    }

    T &operator[](int index)
    {
        return lst[index];
    }

    double all_surfaces()
    {
        double sm = 0;
        for (int i = 0; i < size; ++i)
        {
            sm += (double)lst[i];
        }
        return sm;
    }
};
```

### mass.cpp
```cpp
#include "mass.hpp"

mass::mass()
{
    size = 10;
    lst = new Figure *[size];
    for (int i = 0; i != size; ++i)
        lst[i] = nullptr;
}

mass::mass(int lnght)
{
    size = lnght;
    lst = new Figure *[size];
    for (int i = 0; i != size; ++i)
        lst[i] = nullptr;
}

mass::~mass()
{
    size = 0;
    delete[] lst;
    lst = nullptr;
}

Figure *mass::operator[](int index)
{
    return lst[index];
}

void mass::delete_fig(int index)
{
    delete lst[index];
    lst[index] = nullptr;
}

void mass::change(int index, Figure *other)
{
    if (lst[index] != nullptr)
        delete lst[index];
    lst[index] = other;
}

double mass::all_surfaces()
{
    double sm = 0;
    for (int i = 0; i < size; ++i)
    {
        sm += (double)*lst[i];
    }
    return sm;
}
```

### six_angles.hpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Six_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Six_Angles()
        : size(6), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Six_Angles(std::vector<std::pair<T, T>> cord)
        : size(6), coordinates(cord)
    {
    }
    ~Six_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Six_Angles<T> &operator=(const Six_Angles<T> &other);
    Six_Angles<T> &operator=(Six_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Six_Angles<T> &p)
{
    for (int i = 0; i < 6; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Six_Angles<T> &p)
{

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> p.coordinates[i].first;
        std::cout << "y : ";
        is >> p.coordinates[i].second;
    }
    return is;
}

template <typename T>
inline bool operator==(const Six_Angles<T> &fst, const Six_Angles<T> &snd)
{
    for (int i = 0; i != 6; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
Six_Angles<T> &Six_Angles<T>::operator=(const Six_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
Six_Angles<T> &Six_Angles<T>::operator=(Six_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
Six_Angles<T>::operator double() const
{
    return surface<Six_Angles<T>, T>(*this);
}

```

### six_angles.cpp
```cpp
#include "six_angles.hpp"
#include <string>
#include <vector>
#include <cmath>

six_angles::six_angles()
    : x_coordinates({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}), y_coordinates({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}), surface(0), mid_dot_x(0), mid_dot_y(0)
{
}

six_angles::six_angles(std::vector<double> &x, std::vector<double> &y)
    : mid_dot_x(0), mid_dot_y(0)
{
    if (x_coordinates.size() != 6)
    {
        x_coordinates.resize(6);
    }

    if (y_coordinates.size() != 6)
    {
        y_coordinates.resize(6);
    }

    for (int i = 0; i < 6; ++i)
    {
        x_coordinates[i] = x[i];
        y_coordinates[i] = y[i];
        mid_dot_x += x[i];
        mid_dot_y += y[i];
    }

    mid_dot_x /= 6;
    mid_dot_y /= 6;

    double length = std::sqrt(std::pow(x[0] - x[1], 2) + std::pow(y[0] - y[1], 2));
    surface = 3 * length * length * sqrt(3) / 2;
}

six_angles::~six_angles()
{
    x_coordinates = {};
    y_coordinates = {};
    mid_dot_x = 0;
    mid_dot_y = 0;
    surface = 0;
}

bool six_angles::operator==(six_angles &other) const
{
    if (surface != other.surface)
    {
        return false;
    }
    else
    {
        return true;
    }
}

six_angles &six_angles::operator=(six_angles &other)
{
    x_coordinates = other.x_coordinates;
    y_coordinates = other.y_coordinates;
    mid_dot_x = other.mid_dot_x;
    mid_dot_y = other.mid_dot_y;
    surface = other.surface;
    return *this;
}

six_angles &six_angles::operator=(six_angles &&other)
{
    x_coordinates = std::move(other.x_coordinates);
    y_coordinates = std::move(other.y_coordinates);
    mid_dot_x = std::move(other.mid_dot_x);
    mid_dot_y = std::move(other.mid_dot_y);
    surface = std::move(other.surface);
    return *this;
}
```

### tests.cpp

```cpp
#include <gtest/gtest.h>
#include "mass.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"
#include "functions.hpp"
#include "figure.hpp"

TEST(Five_Angles, empty_constructor)
{
    Five_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Five_Angles<double>, double>(p);
    double surf = surface<Five_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Five_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> five(5);
    for (int i = 0; i < 5; ++i)
    {
        five[i].first = x[i];
        five[i].second = y[i];
    }
    Five_Angles<double> p(five);

    std::pair<double, double> dot = {1.8, 1.8};
    std::pair<double, double> time = mid_dot<Five_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Five_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> five(5);
    for (int i = 0; i < 5; ++i)
    {
        five[i].first = x[i];
        five[i].second = y[i];
    }
    Five_Angles p1(five), p2(five);
    EXPECT_EQ(p1, p2);
}

// /* #####################*/

TEST(Six_Angles, empty)
{
    Six_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Six_Angles<double>, double>(p);
    double surf = surface<Six_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Six_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 6; ++i)
    {
        six[i].first = x[i];
        six[i].second = y[i];
    }
    Six_Angles p(six);

    std::pair<double, double> dot = {2, 2};
    std::pair<double, double> time = mid_dot<Six_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Six_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 6; ++i)
    {
        six[i].first = x[i];
        six[i].second = y[i];
    }
    Six_Angles<double> p1(six), p2(six);
    EXPECT_EQ(p1, p2);
}

// /*######################################*/

TEST(Eight_Angles, empty)
{
    Eight_Angles<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = mid_dot<Eight_Angles<double>, double>(p);
    double surf = surface<Eight_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(surf, 0);
}

TEST(Eight_Angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> eight(8);
    for (int i = 0; i < 8; ++i)
    {
        eight[i].first = x[i];
        eight[i].second = y[i];
    }
    Eight_Angles<double> p(eight);

    std::pair<double, double> dot = {1.875, 1.875};
    std::pair<double, double> time = mid_dot<Eight_Angles<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Eight_Angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> eight(8);
    for (int i = 0; i < 8; ++i)
    {
        eight[i].first = x[i];
        eight[i].second = y[i];
    }
    Eight_Angles<double> p1(eight), p2(eight);
    EXPECT_EQ(p1, p2);
}

// /*#############################*/

TEST(Array, common_surface)
{
    Massive<Five_Angles<double>> a(2);
    Five_Angles<double> *p1 = new Five_Angles<double>();
    Five_Angles<double> *p2 = new Five_Angles<double>();
    a[0] = *p1;
    a[1] = *p2;
    EXPECT_EQ(a.all_surfaces(), 0.0);
}

```