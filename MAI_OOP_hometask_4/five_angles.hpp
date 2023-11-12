#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Five_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Five_Angles()
        : size(5), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Five_Angles(std::vector<std::pair<T, T>> cord)
        : size(5), coordinates(cord)
    {
    }
    ~Five_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Five_Angles<T> &operator=(const Five_Angles<T> &other);
    Five_Angles<T> &operator=(Five_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Five_Angles<T> &p)
{
    for (int i = 0; i < 5; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Five_Angles<T> &p)
{

    for (int i = 0; i < 5; ++i)
    {
        // std::cout << "Введите координаты точки " << i + 1 << ":\n";
        // std::cout << "x : ";
        is >> p.coordinates[i].first;
        // std::cout << "y : ";
        is >> p.coordinates[i].second;
    }
    return is;
}

template <typename T>
inline bool operator==(const Five_Angles<T> &fst, const Five_Angles<T> &snd)
{
    for (int i = 0; i != 5; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
inline Five_Angles<T> &Five_Angles<T>::operator=(const Five_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
inline Five_Angles<T> &Five_Angles<T>::operator=(Five_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
inline Five_Angles<T>::operator double() const
{
    return surface<Five_Angles<T>, T>(*this);
}
