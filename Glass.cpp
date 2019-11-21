#include "Glass.h"
#include "Color.h"

#include <experimental/random>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>

std::ostream& operator<<(std::ostream& os, const Glass& dt) {
    std::vector<std::vector<char>> glasses = dt.getGlasses();
    std::string output("");
    int i = 0;
    for (auto it2 = glasses.rbegin()->begin(); it2 != glasses.rbegin()->end(); i++, it2++) {
        for (auto it = glasses.rbegin(); it != glasses.rend(); it++) {
            output += (*it)[i];
            output += " ";
        }
        output += "\n";
    }
    int colNum = glasses.size()-1;
    for (auto itColNum = glasses.begin(); itColNum != glasses.end(); itColNum++, colNum--) {
        output += std::to_string(colNum);
        output += " ";
    }
    output += "\n";
    os << output;
    return os;
}

Color Glass::getRandomColor() {
    int x = std::experimental::randint(0, 4);
    switch (x)
    {
    case 0:
        return Color::blue;
        break;
    case 1:
        return Color::gray;
        break;
    case 2:
        return Color::orange;
        break;
    case 3:
        return Color::pink;
        break;
    default:
        return Color::yellow;
        break;
    }
}

Glass::Glass(int numCol, int numGl): glasses(numCol, std::vector<char>(0)) {
    for (auto it = glasses.begin(); it != glasses.end(); it++) {
        int h = std::experimental::randint(0, numGl-1);
        Color color1 = getRandomColor();
        Color color2 = getRandomColor();
        for (int i = 0; i < numGl; i++) {
            if (h > 0) {
                it->push_back(static_cast<char>(color1));
            }
            else {
                it->push_back(static_cast<char>(color2));
            }
            h--;
        }
    }
    // for (auto it3 = glasses.begin(); it3 < glasses.end(); it3++) {
    //      for (auto it4 = it3->begin(); it4 < it3->end(); it4++) {
    //          std::cout << *it4;
    //      }
    //      std::cout << std::endl;
    // }
}

int Glass::constructCol(std::vector<char> glasses, int col) {
    int countNotPlacedGlasses = 0;
    if (isComplete(col)) {
        throw std::invalid_argument("column already complete");
    }
    else {
        auto itGlass = Glass::glasses[col].begin();
        auto itConstruct = glasses.begin();
        for (; itGlass != Glass::glasses[col].end() && itConstruct != glasses.end(); itGlass++, itConstruct++) {
            if (*itGlass == *itConstruct) {
                *itGlass = 'x';
            }
            else {
                countNotPlacedGlasses++;
            }
        }
    }
    return countNotPlacedGlasses;
}

bool Glass::isComplete(int col) {
    bool isComplete = true;
    for (auto it = Glass::glasses[col].begin(); it != Glass::glasses[col].end() && isComplete; it++) {
        if (*it != 'x') {
            isComplete = false;
        }
    }
    return isComplete;
}

bool Glass::isInConstruction(int col) {
    bool isInConstruction = false;
    for (auto it = Glass::glasses[col].begin(); it != Glass::glasses[col].end() && !isInConstruction; it++) {
        if (*it == 'x') {
            isInConstruction = true;
        }
    }
    return isInConstruction;
}