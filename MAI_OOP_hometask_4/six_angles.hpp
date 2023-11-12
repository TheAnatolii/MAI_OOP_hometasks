#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Six_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Six_Angles()
        : size(6), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Six_Angles(std::vector<std::pair<T, T>> cord)
        : size(6), coordinates(cord)
    {
    }
    ~Six_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Six_Angles<T> &operator=(const Six_Angles<T> &other);
    Six_Angles<T> &operator=(Six_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Six_Angles<T> &p)
{
    for (int i = 0; i < 6; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Six_Angles<T> &p)
{

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Введите координаты точки " << i + 1 << ":\n";
        std::cout << "x : ";
        is >> p.coordinates[i].first;
        std::cout << "y : ";
        is >> p.coordinates[i].second;
    }
    return is;
}

template <typename T>
inline bool operator==(const Six_Angles<T> &fst, const Six_Angles<T> &snd)
{
    for (int i = 0; i != 6; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
Six_Angles<T> &Six_Angles<T>::operator=(const Six_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
Six_Angles<T> &Six_Angles<T>::operator=(Six_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
Six_Angles<T>::operator double() const
{
    return surface<Six_Angles<T>, T>(*this);
}
