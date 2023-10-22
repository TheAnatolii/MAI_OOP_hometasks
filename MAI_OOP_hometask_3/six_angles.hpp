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