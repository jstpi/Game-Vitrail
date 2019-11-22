#include "Vitrail.h"
#include "Lots.h"
#include "Couleur.h"
#include "Joueur.h"
#include <iostream>
#include <vector>

int main() {
    Vitrail v(7, 6);
    Joueur j("Bob", &v);
    std::cout << j;
}