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