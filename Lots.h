/**
 * @file Lots.h
 *
 * @brief Classe Lots contenant les lots et les surplus.
 *
 * @author Jeremie St-Pierre (8628942), Frederik Lafleche (8616081)
 */

#ifndef LOTS_H
#define LOTS_H

#include <vector>
#include <iostream>

class Lots {
    char** lots;
    int cols;
    int rangs;
    std::vector<char> surplus;

    public:
        Lots(int cols, int rangs);
        void reset();
        std::vector<char> ramasseVitre(char couleur, int numeroLot);
        char** getLots() const {return lots;}
        int getCols() const{return cols;}
        int getRangs() const{return rangs;}
        bool isTaken(int);
        bool isLotsEmpty();
        std::vector<char> getSurplus() const {return surplus;}
        ~Lots() {
            delete[] lots;
        }

};

std::ostream& operator<<(std::ostream& os, const Lots& l);

#endif // LOTS_H