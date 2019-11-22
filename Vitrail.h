#ifndef VITRE_H
#define VITRE_H

#include "Couleur.h"
#include <vector>
#include <iostream>

class Vitrail {
    char** vitres;
    int cols;
    int rangs;

    public:
        Vitrail(int cols, int rangs);
        char** getVitres() const {return vitres;}
        int getCols() const {return cols;}
        int getRangs() const {return rangs;}
        int construireVitrail(std::vector<char> vitres, int col);
        bool estComplete(int colonne);
        bool estEnConstruction(int colonne);
        ~Vitrail() {
            delete[] vitres;
        }
};

std::ostream& operator<<(std::ostream& os, const Vitrail& v);

#endif // VITRE_H