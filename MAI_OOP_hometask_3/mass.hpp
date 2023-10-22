#include "figure.hpp"

class mass
{
private:
    Figure **lst;
    int size;

public:
    mass();
    ~mass();
    mass(int lnght);

    void delete_fig(int index);
    Figure *operator[](int index);
    void change(int index, Figure *other);
    double all_surfaces();
    int get_size()
    {
        return size;
    }
};