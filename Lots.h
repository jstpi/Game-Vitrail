#ifndef LOTS_H
#define LOTS_H

#include <vector>
#include <iostream>

class Lots {
    std::vector<std::vector<char>> lots;
    std::vector<char> surplus;

    public:
        Lots();
        void reset();
        std::vector<char> ramasseVitre(char couleur, int numeroLot);
        std::vector<std::vector<char>> getLots() const {return lots;}
        std::vector<char> getSurplus() const {return surplus;}

};

std::ostream& operator<<(std::ostream& os, const Lots& l);

#endif // LOTS_H