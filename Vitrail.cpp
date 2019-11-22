#include "Vitrail.h"
#include "Couleur.h"

#include <experimental/random>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>

std::ostream& operator<<(std::ostream& os, const Vitrail& v) {
    char** vitres = v.getVitres();
    int cols = v.getCols();
    int rangs = v.getRangs();
    std::string colorOut;
    std::string colOut;
    for (int j = 0; j < rangs; j++) {
        for (int i = cols-1; i >= 0; i--) {
            colorOut += vitres[i][j];
            colorOut += " ";
        }
        colorOut += "\n";
    }
    for (int i = cols-1; i >= 0; i--) {
        colOut += std::to_string(i);
        colOut += " ";
    }
    colOut += "\n";
    os << colorOut << colOut;
    return os;
}

bool isNone(char color) {
    return (color == static_cast<char>(Couleur::complet));
}

Vitrail::Vitrail(int cols, int rangs): vitres(new char*[cols]), cols(cols), rangs(rangs) {
    for (int i = 0; i < Vitrail::cols; i++) {
        Vitrail::vitres[i] = new char[Vitrail::rangs];
        int h = std::experimental::randint(0, Vitrail::rangs-1);
        char couleur1 = static_cast<char>(getCouleurAleatoire());
        char couleur2 = static_cast<char>(getCouleurAleatoire());
        for (int j = 0; j < Vitrail::rangs; j++, h--) {
            if (h > 0) {
                Vitrail::vitres[i][j] = couleur1;
            }
            else {
                Vitrail::vitres[i][j] = couleur2;
            }
        }
    }
}

int Vitrail::construireVitrail(std::vector<char> vitres, int colonne) {
    int vitreNonPlaces = 0;
    if (estComplete(colonne)) {
        throw std::invalid_argument("colonne dejas complete");
    }
    else {
        auto it = vitres.begin();
        for (auto it = vitres.begin(); it != vitres.end(); it++) {
            char* begin = Vitrail::vitres[colonne];
            char* end = Vitrail::vitres[colonne]+Vitrail::rangs;
            char* couleur = std::find(begin, end, *it);
            if (couleur != end) {
                *couleur = static_cast<char>(Couleur::complet);
            }
            else {
                vitreNonPlaces++;
            }
        }
    }
    return vitreNonPlaces;
}

bool Vitrail::estComplete(int colonne) {
    char* begin = Vitrail::vitres[colonne];
    char* end = Vitrail::vitres[colonne]+Vitrail::rangs;
    char* couleur = std::find_if_not(begin, end, isNone);
    if (couleur != end) {
        return false;
    }
    else {
        return true;
    }
}

bool Vitrail::estEnConstruction(int colonne) {
    char* begin = Vitrail::vitres[colonne];
    char* end = Vitrail::vitres[colonne]+Vitrail::rangs;
    char* couleur = std::find_if(begin, end, isNone);
    if (couleur != end) {
        return true;
    }
    else {
        return false;
    }
}