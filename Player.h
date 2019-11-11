#include<string>

class Player {
    std::string name;
    int score;
    int pPos;
    // pointeur a vitrail;

    // La classe doit avoir un opérateur de pré-incrémentation -- ainsi qu’un opérateur
    // -=(int) permettant de déplacer le vitrier vers la droite. Si vous essayer de déplacer le 
    // vitrier en dehors des colonnes, une exception de type std::out_of_range doit être
    // lancée. Elle doit aussi avoir l’opérateur ~ permettant de remettre le vitrier à l’extrême
    // gauche.
    // Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    // console de l’état d’un joueur comme suit : 
};