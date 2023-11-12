#include "mass.hpp"

mass::mass()
{
    size = 10;
    lst = new Figure *[size];
    for (int i = 0; i != size; ++i)
        lst[i] = nullptr;
}

mass::mass(int lnght)
{
    size = lnght;
    lst = new Figure *[size];
    for (int i = 0; i != size; ++i)
        lst[i] = nullptr;
}

mass::~mass()
{
    for (int i = 0; i < size; ++i)
    {
        delete lst[i];
    }
    delete[] lst;
    size = 0;
}

Figure *mass::operator[](int index)
{
    return lst[index];
}

void mass::delete_fig(int index)
{
    delete lst[index];
    lst[index] = nullptr;
}

void mass::change(int index, Figure *other)
{
    if (lst[index] != nullptr)
        delete lst[index];
    lst[index] = other;
}

double mass::all_surfaces()
{
    double sm = 0;
    for (int i = 0; i < size; ++i)
    {
        sm += (double)*lst[i];
    }
    return sm;
}