#ifndef GLASS_H
#define GLASS_H

#include "Color.h"
#include <vector>
#include <iostream>

class Glass {
    std::vector<std::vector<char>> glasses;

    Color getRandomColor();

    public:
        Glass(int numCol, int numGl);
        std::vector<std::vector<char>> getGlasses() const {return glasses;}
        int constructCol(std::vector<char> glasses, int col);
        bool isComplete(int col);
        bool isInConstruction(int col);
};

std::ostream& operator<<(std::ostream& os, const Glass& dt);

#endif // GLASS_H