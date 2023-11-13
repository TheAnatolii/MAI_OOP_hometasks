#pragma once
#include <memory>
#include "figure.hpp"
#include "functions.hpp"

template <class T>
class Massive
{
private:
    std::shared_ptr<T[]> lst;
    int size;

public:
    Massive()
    {
        size = 0;
        lst = nullptr;
    }

    ~Massive()
    {
        size = 0;
        lst = nullptr;
    }

    Massive(int lnght)
    {
        size = lnght;
        lst = std::shared_ptr<T[]>(new T[lnght]);
    }

    T &operator[](int index)
    {
        return lst[index];
    }

    double all_surfaces()
    {
        double sm = 0;
        for (int i = 0; i < size; ++i)
        {
            sm += (double)lst[i];
        }
        return sm;
    }
};