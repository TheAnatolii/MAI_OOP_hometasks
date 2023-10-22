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