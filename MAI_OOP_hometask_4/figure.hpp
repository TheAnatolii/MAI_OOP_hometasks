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