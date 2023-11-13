#include <iostream>
#include "figure.hpp"
#include "five_angles.hpp"
#include "six_angles.hpp"
#include "eight_angles.hpp"
#include "mass.hpp"

int main()
{
    // Five_Angles p = Five_Angles();

    // std::vector<double> five_x{0, sqrt(6250 + 1250 * sqrt(5)), -sqrt(6250 + 1250 * sqrt(5)), 25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2};
    // std::vector<double> five_y{100, -25 + 25 * sqrt(5), -25 + 25 * sqrt(5), -25 * sqrt(5) - 25, -25 * sqrt(5) - 25};

    std::vector<double> six_x{2, 1, -1, -2, -1, 1};
    std::vector<double> six_y{0, sqrt(3), sqrt(3), 0, -sqrt(3), -sqrt(3)};

    // std::vector<double> eight_x{sqrt(2), 1, 0, -1, -sqrt(2), -1, 0, 1};
    // std::vector<double> eight_y{0, 1, sqrt(2), 1, 0, -1, -sqrt(2), -1};

    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 5; ++i)
    {
        six[i].first = six_x[i];
        six[i].second = six_y[i];
    }

    // Five_Angles<double> p(five);
    // std::cout << (double)(p);

    Six_Angles<double> p(six);
    std::cout << (double)p;

    //     Five_Angles p = Five_Angles(five_x, five_y);
    //     Eight_Angles h = Eight_Angles(six_x, six_y);
    //     eight_angles l = eight_angles(eight_x, eight_y);

    //     // std::cin >> p;
    //     // std::cout << p;
    //     // point k = h.mid_dot();
    //     // std::cout << k.x << " " << k.y;
    //     // std::cout << (double)l;

    //     mass q = mass(3);
    //     q.change(0, &p);
    //     q.change(1, &h);
    //     q.change(2, &l);

    //     for (int i = 0; i < 3; ++i)
    //     {
    //         const Figure *fig = q[i];
    //         if (q[i] == nullptr)
    //         {
    //             std::cout << "The figure has been deleted" << std::endl;
    //         }
    //         else if (typeid(p) == typeid(*fig))
    //         {
    //             std::cout << *(Five_Angles *)q[i];
    //         }
    //         else if (typeid(h) == typeid(*fig))
    //         {
    //             std::cout << *(Eight_Angles *)q[i];
    //         }
    //         else if (typeid(l) == typeid(*fig))
    //         {
    //             std::cout << *(eight_angles *)q[i];
    //         }
    //     }

    //     std::cout << "\n\n";

    //     Five_Angles ex = Five_Angles();
    //     ex = p;
    //     std::cout << ex;
}