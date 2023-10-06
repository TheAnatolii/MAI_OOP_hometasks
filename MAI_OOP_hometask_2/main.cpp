#include <iostream>
#include "five.hpp"

auto main() -> int
{
    try
    {
        std::string val1, val2;
        std::cout << "Enter first number: ";
        std::cin >> val1;
        std::cout << "Enter second number: ";
        std::cin >> val2;

        Five num1 = Five(val1);
        Five num2 = Five(val2);

        char op;
        std::cout << "What operation do you want to perform: ";
        std::cin >> op;

        bool res;
        switch (op)
        {
        case '+':
            std::cout << "Result: " << (num1 + num2).get_value_string() << std::endl;
            break;

        case '-':
            std::cout << "Result: " << (num1 - num2).get_value_string() << std::endl;
            break;

        case '>':
            res = num1 > num2;
            std::cout << "Result: " << res << std::endl;
            break;

        case '<':
            res = num1 < num2;
            std::cout << "Result: " << res << std::endl;
            break;

        case '=':
            res = (num1 == num2);
            std::cout << "Result: " << res << std::endl;
            break;

        default:
            std::cout << "No such operation\n";
            break;
        }
    }
    catch (const std::invalid_argument &ex)
    {
        std::cout << "Invalid argument exception caught: " << ex.what() << std::endl;
    }
    return 0;
}