#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>

class five_angles : public Figure
{

    friend std::ostream &operator<<(std::ostream &os, const five_angles &p);
    friend std::istream &operator>>(std::istream &is, five_angles &p);

public:
    five_angles();
    ~five_angles();
    five_angles(std::vector<double> &x, std::vector<double> &y);

    bool operator==(five_angles &other) const;

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

    operator double() const
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

    p = five_angles(&x_c, &y_c);
    return is;
}