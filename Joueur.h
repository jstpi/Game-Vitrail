#ifndef JOUEUR_H
#define JOUEUR_H

#include "Vitrail.h"
#include <string>
#include <iostream>

class Joueur{
    std::string name;
    int points;
    int position;
    Vitrail *vitrail;

    public:
        Joueur(std::string name, Vitrail* vitrail): name(name), points(0), position(vitrail->getCols()-1), vitrail(vitrail){}
        Joueur& operator-=(int x){
            if (position - x < 0) {
                throw std::out_of_range("Exterieur du vitrail");
            }
            position -= x;
            return *this;
        }
        Joueur& operator--() {
            return *this-=1;
        }
        Joueur& operator~() {
            position = vitrail->getCols()-1;
            return *this;
        }
        std::string getName() const {return name;}
        int getPoints() const {return points;}
        int getPosition() const {return position;}
        Vitrail* getVitrail() const {return vitrail;}
};

std::ostream& operator<<(std::ostream& os, const Joueur& j) {
    std::string outJoueur = j.getName() + " : " + std::to_string(j.getPoints()) + " points \n";
    outJoueur += "Vitrier a la position " + std::to_string(j.getPosition()) + ".\n";
    outJoueur += "Plan : \n";
    return os << outJoueur << *(j.getVitrail());
};

#endif // JOUEUR_H