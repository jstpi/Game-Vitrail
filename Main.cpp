#include "Glass.h"
#include <iostream>
#include <vector>

int main() {
    Glass glass(6, 6);
    std::cout << glass << std::endl;

    std::vector<char> v(6, 'O');
    std::cout << glass.constructCol(v, 0) << std::endl;

    std::cout << glass.isComplete(0) << std::endl;
    std::cout << glass.isInConstruction(0) << std::endl;

    std::cout << glass << std::endl;
}