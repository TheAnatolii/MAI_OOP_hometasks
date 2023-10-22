# Лабораторная работа 2. Классы
## Автор: Головенко Анатолий, группа М8О-212Б-22, вариант 6

Разработать программу на языке C++ согласно варианту задания. Программа на C++ должна собираться с помощью системы сборки CMake. Программа должна получать данные из стандартного ввода (std::cin) и выводить данные в стандартный вывод (std::cout).
Необходимо зарегистрироваться на GitHub и создать репозитарий для задания лабораторных работ.
Преподавателю необходимо предъявить ссылку на публичный репозиторий на Github. Необходимо реализовать функцию согласно варианту задания. Функция должна быть помещена в отдельный файл.

Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения.
Все классы должны поддерживать набор общих методов:
1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через перегрузку оператора << для std::ostream;
3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для std::istream
4. Вычисление площади фигуры через перегрузку оператора приведения к типу double;

Создать программу, которая позволяет:
- Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
- Сохранять созданные фигуры в динамический массив (по аналогии с предыдущей лабораторной работой Array) указатели на фигуру (Figure*)
- Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и сравнения (==)
- Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр и площадь.
- Необходимо уметь вычислять общую площадь фигур в массиве. •Удалять из массива фигуру по индексу;

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
    five_angles.cpp
    six_angles.cpp
    eight_angles.cpp
    mass.cpp
)

add_executable(
    tests 
    tests.cpp
    five_angles.cpp
    six_angles.cpp
    eight_angles.cpp
    mass.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
```

###eight_angles.hpp
```cpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>

class eight_angles : public Figure
{

public:
    eight_angles();
    eight_angles(std::vector<double> &x, std::vector<double> &y);
    ~eight_angles();

    bool operator==(eight_angles &other) const;
    eight_angles &operator=(eight_angles &other);
    eight_angles &operator=(eight_angles &&other);

    friend std::ostream &operator<<(std::ostream &os, const eight_angles &p);
    friend std::istream &operator>>(std::istream &is, eight_angles &p);

public:
    double Square() const override
    {
        return surface;
    }

    point mid_dot() const override
    {
        point dot;
        dot.x = mid_dot_x;
        dot.y = mid_dot_y;
        return dot;
    }

    operator double() const override
    {
        return surface;
    }

private:
    std::vector<double> x_coordinates;
    std::vector<double> y_coordinates;
    double mid_dot_x;
    double mid_dot_y;
    double surface;
};

inline std::ostream &operator<<(std::ostream &os, const eight_angles &p)
{
    for (int i = 0; i < 8; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.x_coordinates[i] << ", " << p.y_coordinates[i] << ")\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream &is, eight_angles &p)
{
    double x, y;
    std::vector<double> x_c(8), y_c(8);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> x;
        std::cout << "y : ";
        is >> y;
        x_c[i] = x;
        y_c[i] = y;
    }

    p = eight_angles(x_c, y_c);
    return is;
}
```

### eight_angles.cpp
```cpp
#include "eight_angles.hpp"
#include <string>
#include <vector>
#include <cmath>

eight_angles::eight_angles()
    : x_coordinates({0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}),
      y_coordinates({0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}), surface(0), mid_dot_x(0), mid_dot_y(0)
{
}

eight_angles::eight_angles(std::vector<double> &x, std::vector<double> &y)
    : mid_dot_x(0), mid_dot_y(0)
{
    if (x_coordinates.size() != 8)
    {
        x_coordinates.resize(8);
    }

    if (y_coordinates.size() != 8)
    {
        y_coordinates.resize(8);
    }

    for (int i = 0; i < 8; ++i)
    {
        x_coordinates[i] = x[i];
        y_coordinates[i] = y[i];
        mid_dot_x += x[i];
        mid_dot_y += y[i];
    }

    mid_dot_x /= 8;
    mid_dot_y /= 8;

    double length = std::sqrt(std::pow(x[0] - x[1], 2) + std::pow(y[0] - y[1], 2));
    surface = 2 * length * length * (sqrt(2) + 1);
}

eight_angles::~eight_angles()
{
    x_coordinates = {};
    y_coordinates = {};
    mid_dot_x = 0;
    mid_dot_y = 0;
    surface = 0;
}

bool eight_angles::operator==(eight_angles &other) const
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

eight_angles &eight_angles::operator=(eight_angles &other)
{
    x_coordinates = other.x_coordinates;
    y_coordinates = other.y_coordinates;
    mid_dot_x = other.mid_dot_x;
    mid_dot_y = other.mid_dot_y;
    surface = other.surface;
    return *this;
}

eight_angles &eight_angles::operator=(eight_angles &&other)
{
    x_coordinates = std::move(other.x_coordinates);
    y_coordinates = std::move(other.y_coordinates);
    mid_dot_x = std::move(other.mid_dot_x);
    mid_dot_y = std::move(other.mid_dot_y);
    surface = std::move(other.surface);
    return *this;
}
```

### figure.hpp
```cpp
#pragma once

#include <string>
#include <utility>

struct point
{
    double x, y;
};

class Figure
{
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual double Square() const = 0;
    virtual point mid_dot() const = 0;
    virtual operator double() const = 0;
};
```

### five_angles.hpp
```cpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>

class five_angles : public Figure
{

public:
    five_angles();
    five_angles(std::vector<double> &x, std::vector<double> &y);
    ~five_angles();

    bool operator==(five_angles &other) const;
    five_angles &operator=(five_angles &other);
    five_angles &operator=(five_angles &&other);

    friend std::ostream &operator<<(std::ostream &os, const five_angles &p);
    friend std::istream &operator>>(std::istream &is, five_angles &p);

public:
    double Square() const override
    {
        return surface;
    }

    point mid_dot() const override
    {
        point dot;
        dot.x = mid_dot_x;
        dot.y = mid_dot_y;
        return dot;
    }

    operator double() const override
    {
        return surface;
    }

private:
    std::vector<double> x_coordinates;
    std::vector<double> y_coordinates;
    double mid_dot_x;
    double mid_dot_y;
    double surface;
};

inline std::ostream &operator<<(std::ostream &os, const five_angles &p)
{
    for (int i = 0; i < 5; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.x_coordinates[i] << ", " << p.y_coordinates[i] << ")\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream &is, five_angles &p)
{
    double x, y;
    std::vector<double> x_c(5), y_c(5);
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> x;
        std::cout << "y : ";
        is >> y;
        x_c[i] = x;
        y_c[i] = y;
    }

    p = five_angles(x_c, y_c);
    return is;
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
```cpp
#include "figure.hpp"

class mass
{
private:
    Figure **lst;
    int size;

public:
    mass();
    ~mass();
    mass(int lnght);

    void delete_fig(int index);
    Figure *operator[](int index);
    void change(int index, Figure *other);
    double all_surfaces();
    int get_size()
    {
        return size;
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
```cpp
#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>

class six_angles : public Figure
{

public:
    six_angles();
    six_angles(std::vector<double> &x, std::vector<double> &y);
    ~six_angles();

    bool operator==(six_angles &other) const;
    six_angles &operator=(six_angles &other);
    six_angles &operator=(six_angles &&other);

    friend std::ostream &operator<<(std::ostream &os, const six_angles &p);
    friend std::istream &operator>>(std::istream &is, six_angles &p);

public:
    double Square() const override
    {
        return surface;
    }

    point mid_dot() const override
    {
        point dot;
        dot.x = mid_dot_x;
        dot.y = mid_dot_y;
        return dot;
    }

    operator double() const override
    {
        return surface;
    }

private:
    std::vector<double> x_coordinates;
    std::vector<double> y_coordinates;
    double mid_dot_x;
    double mid_dot_y;
    double surface;
};

inline std::ostream &operator<<(std::ostream &os, const six_angles &p)
{
    for (int i = 0; i < 6; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.x_coordinates[i] << ", " << p.y_coordinates[i] << ")\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream &is, six_angles &p)
{
    double x, y;
    std::vector<double> x_c(6), y_c(6);
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> x;
        std::cout << "y : ";
        is >> y;
        x_c[i] = x;
        y_c[i] = y;
    }

    p = six_angles(x_c, y_c);
    return is;
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

TEST(five_angles, empty_constructor)
{
    five_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(five_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    five_angles p(x, y);

    point dot;
    dot.x = 1.8, dot.y = 1.8;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(five_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    five_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/* #####################*/

TEST(six_angles, empty)
{
    six_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(six_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    six_angles p(x, y);

    point dot;
    dot.x = 2, dot.y = 2;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(six_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    six_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/*######################################*/

TEST(eight_angles, empty)
{
    eight_angles p;
    point dot;
    dot.x = 0, dot.y = 0;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Square(), 0);
}

TEST(eight_angles, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    eight_angles p(x, y);

    point dot;
    dot.x = 1.875, dot.y = 1.875;
    point time = p.mid_dot();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(eight_angles, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    eight_angles p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}

/*#############################*/

TEST(mass, empty)
{
    mass a;

    for (int i = 0; i != 10; ++i)
        EXPECT_EQ(a[i], nullptr);
}

TEST(mass, size_conrtuctor)
{
    mass a(15);

    EXPECT_EQ(a.get_size(), 15);

    for (int i = 0; i != 15; ++i)
        EXPECT_EQ(a[i], nullptr);
}
```