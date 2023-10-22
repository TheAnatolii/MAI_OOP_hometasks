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