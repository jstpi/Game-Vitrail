#ifndef COLOR_H
#define COLOR_H

enum class Couleur { 
    gris = 'G',
    jaune = 'J',
    bleu = 'B',
    rose = 'R',
    orange = 'O',
    complet = 'x',
    vide = '.'
};

Couleur getCouleurAleatoire();

#endif // COLOR_H