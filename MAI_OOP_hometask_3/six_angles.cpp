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