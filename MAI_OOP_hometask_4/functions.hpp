#pragma once
#include <cmath>
#include <utility>

template <class C, typename T>
std::pair<T, T> mid_dot(C &figure)
{
    int size = figure.size;
    std::pair<T, T> p = {0, 0};

    for (std::pair<T, T> point : figure.coordinates)
    {
        p.first += point.first;
        p.second += point.second;
    }

    p.first /= size;
    p.second /= size;
    return p;
}

template <class C, typename T>
T surface(const C &figure)
{
    T side = std::sqrt(std::pow(figure.coordinates[0].first - figure.coordinates[1].first, 2) + std::pow(figure.coordinates[0].second - figure.coordinates[1].second, 2));
    T perimeter = figure.size * side;
    double angle = 360 / figure.size;
    T apotheme = side * 0.5 * std::tan(90 - 0.5 * angle);
    return perimeter * apotheme / 2;
}