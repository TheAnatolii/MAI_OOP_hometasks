#include <iostream>
#include "functions.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::cout << solver(input);
    return 0;
}
