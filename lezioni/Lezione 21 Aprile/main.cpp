#include <iostream>
#include "ellisse.hpp"

int main() {

    Ellisse el1(0.0, 0.0, 3.0, 5.6);

    std::cout << el1.toString() << std::endl;

    return 0;
}