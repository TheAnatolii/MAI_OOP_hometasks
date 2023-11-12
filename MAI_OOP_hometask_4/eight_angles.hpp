#pragma once
#include <iostream>
#include "figure.hpp"
#include <vector>
#include <cmath>
#include "functions.hpp"

template <typename T>
class Eight_Angles : public Figure
{

public:
    std::vector<std::pair<T, T>> coordinates;
    double size;

    Eight_Angles()
        : size(8), coordinates({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}})
    {
    }

    Eight_Angles(std::vector<std::pair<T, T>> cord)
        : size(8), coordinates(cord)
    {
    }
    ~Eight_Angles()
    {
        size = 0;
        coordinates = {};
    }

    Eight_Angles<T> &operator=(const Eight_Angles<T> &other);
    Eight_Angles<T> &operator=(Eight_Angles<T> &&other);

    operator double() const override;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Eight_Angles<T> &p)
{
    for (int i = 0; i < 8; ++i)
    {
        os << "Координаты точки " << i + 1 << ": (" << p.coordinates[i].first << ", " << p.coordinates[i].second << ")\n";
    }
    return os;
}

template <typename T>
inline std::istream &operator>>(std::istream &is, Eight_Angles<T> &p)
{

    for (int i = 0; i < 8; ++i)
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
inline bool operator==(const Eight_Angles<T> &fst, const Eight_Angles<T> &snd)
{
    for (int i = 0; i != 6; ++i)
    {
        if (fst.coordinates[i] != snd.coordinates[i])
            return false;
    }
    return true;
}

template <typename T>
Eight_Angles<T> &Eight_Angles<T>::operator=(const Eight_Angles<T> &other)
{
    coordinates = other.coordinates;
    size = other.size;
    return *this;
}

template <typename T>
Eight_Angles<T> &Eight_Angles<T>::operator=(Eight_Angles<T> &&other)
{
    coordinates = std::move(other.coordinates);
    size = std::move(other.size);
    return *this;
}

template <typename T>
Eight_Angles<T>::operator double() const
{
    return surface<Eight_Angles<T>, T>(*this);
}
