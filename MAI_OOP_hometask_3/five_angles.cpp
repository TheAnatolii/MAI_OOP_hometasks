#include "five_angles.hpp"
#include <string>
#include <vector>
#include <cmath>

five_angles::five_angles()
    : x_coordinates{0.0, 0.0, 0.0, 0.0, 0.0}, y_coordinates{0.0, 0.0, 0.0, 0.0, 0.0}, surface(0), mid_dot_x(0), mid_dot_y(0)
{
}

five_angles::five_angles(std::vector<double> &x, std::vector<double> &y)
{
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