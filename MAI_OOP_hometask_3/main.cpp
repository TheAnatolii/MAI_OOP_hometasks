#include <iostream>
#include "figure.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"
#include "mass.hpp"

int main()
{
    // five_angles p = five_angles();

    std::vector<double> five_x{0,
                               sqrt(6250 + 1250 * sqrt(5)),
                               -sqrt(6250 + 1250 * sqrt(5)),
                               25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2,
                               -25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2};
    std::vector<double> five_y{100,
                               -25 + 25 * sqrt(5),
                               -25 + 25 * sqrt(5),
                               -25 * sqrt(5) - 25,
                               -25 * sqrt(5) - 25};

    std::vector<double> six_x{2,
                              1,
                              -1,
                              -2,
                              -1,
                              1};
    std::vector<double> six_y{0,
                              sqrt(3),
                              sqrt(3),
                              0,
                              -sqrt(3),
                              -sqrt(3)};

    std::vector<double> eight_x{sqrt(2),
                                1,
                                0,
                                -1,
                                -sqrt(2),
                                -1,
                                0,
                                1};

    std::vector<double> eight_y{0,
                                1,
                                sqrt(2),
                                1,
                                0,
                                -1,
                                -sqrt(2),
                                -1};

    five_angles p = five_angles(five_x, five_y);
    six_angles h = six_angles(six_x, six_y);
    eight_angles l = eight_angles(eight_x, eight_y);

    // std::cin >> p;
    // std::cout << p;
    // point k = h.mid_dot();
    // std::cout << k.x << " " << k.y;
    // std::cout << (double)l;

    mass q = mass(3);
    q.change(0, &p);
    q.change(1, &h);
    q.change(2, &l);

    for (int i = 0; i < 3; ++i)
    {
        const Figure *fig = q[i];
        if (q[i] == nullptr)
        {
            std::cout << "The figure has been deleted" << std::endl;
        }
        else if (typeid(p) == typeid(*fig))
        {
            std::cout << *(five_angles *)q[i];
        }
        else if (typeid(h) == typeid(*fig))
        {
            std::cout << *(six_angles *)q[i];
        }
        else if (typeid(l) == typeid(*fig))
        {
            std::cout << *(eight_angles *)q[i];
        }
    }

    std::cout << "\n\n";

    five_angles ex = five_angles();
    ex = p;
    std::cout << ex;
}