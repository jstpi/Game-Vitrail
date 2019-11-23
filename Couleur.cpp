/**
 * @file Couleur.cpp
 *
 * @brief Methodes pour manipuler les couleurs.
 *
 * @author Jeremie St-Pierre (8628942), Frederik Lafleche (8616081)
 */

#include "Couleur.h"
#include <experimental/random>

Couleur getCouleurAleatoire() {
    int x = std::experimental::randint(0, 4);
    switch (x)
    {
    case 0:
        return Couleur::bleu;
        break;
    case 1:
        return Couleur::gris;
        break;
    case 2:
        return Couleur::orange;
        break;
    case 3:
        return Couleur::rose;
        break;
    default:
        return Couleur::jaune;
        break;
    }
}

Couleur getCouleurParChoix(int couleurChoix){
    switch (couleurChoix)
    {
    case 1:
        return Couleur::bleu;
        break;
    case 2:
        return Couleur::gris;
        break;
    case 3:
        return Couleur::orange;
        break;
    case 4:
        return Couleur::rose;
        break;
    default:
        return Couleur::jaune;
        break;
    }
}