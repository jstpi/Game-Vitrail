#include "Vitrail.h"
#include "Lots.h"
#include "Couleur.h"
#include "Joueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

bool valideColLot(Lots& lots, int colLots) {
    return colLots >= -1 && colLots < lots.getCols();
}

bool valideCouleurChoix(int couleurChoix) {
    return couleurChoix > 0 && couleurChoix < 6;
}

bool valideColVitrail(Vitrail& vitrail, int colVitrail) {
    return colVitrail >= 0 && colVitrail < vitrail.getCols();
}

bool valideChoix(int choixJeu) {
    return choixJeu > 0 && choixJeu < 3;
}

int main() {
    std::string nom1;
    std::cout << "Premier joueur, entrez votre nom: ";
    std::cin >> nom1;
    std::cout << std::endl;

    Vitrail vitrail1(7, 5);
    Joueur joueur1(nom1, &vitrail1);

    std::string nom2;
    std::cout << "Deuxieme joueur, entrez votre nom: ";
    std::cin >> nom2;
    std::cout << std::endl;

    Vitrail vitrail2(7, 5);
    Joueur joueur2(nom2, &vitrail2);

    Lots lots(5, 4);

    bool tour(true);
    while(true) {
        if (tour) { std::cout << "Au tour du premier joueur." << std::endl << joueur1; }
        else { std::cout << "Au tour du second joueur." << std::endl << joueur2; }
        std::cout << lots;

        int colLots(-2);
        int choixCouleur(0);
        int colVitrail(-1);
        int choixJeu(0);

        while (!valideChoix(choixJeu)) {
            while (std::cout << "Entrez votre choix (1=poser vitre, 2=deplacer vitrier au debut): " && !(std::cin >> choixJeu)) {
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                std::cout << "Input invalide; entrez de nouveau." << std::endl;
            }
        }

        if (choixJeu == 1) {
            while (!valideColLot(lots, colLots)) {
                while (std::cout << "Entrez l'index du lots (surplus: -1): " && !(std::cin >> colLots)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "Input invalide; entrez de nouveau." << std::endl;
                }
            }
            while (!valideCouleurChoix(choixCouleur)) {
                while (std::cout << "Choisissez votre couleur (1=Bleu, 2=Gris, 3=Orange, 4=Rose, 5=Jaune): " && !(std::cin >> choixCouleur)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "Input invalide; entrez de nouveau." << std::endl;
                }
            }
            while (!valideColVitrail(vitrail1, colVitrail)) {
                while (std::cout << "Entrez l'index du vitrail: " && !(std::cin >> colVitrail)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "Input invalide; entrez de nouveau." << std::endl;
                }
            }
            try {
                Couleur couleur(getCouleurParChoix(choixCouleur));
                if (tour) {
                    joueur1-=(joueur1.getPosition()-colVitrail);
                    std::vector<char> vecteurLots(lots.ramasseVitre(static_cast<char>(couleur), colLots));
                    int perte = vitrail1.construireVitrail(vecteurLots, colVitrail);
                    
                    joueur1.removePoints(perte);
                    if (vitrail1.estComplete(colVitrail)) {
                        joueur1.addPoints(3);
                        for (int i = colVitrail-1; i >= 0; i--){
                            if (vitrail1.estEnConstruction(i)){
                                joueur1.addPoints(1);
                            }
                        }
                    }
                    
                    std::cout << joueur1;
                    std::cout << lots;
                    tour = !tour;
                }
                else {
                    joueur2-=(joueur2.getPosition()-colVitrail);
                    std::vector<char> vecteurLots(lots.ramasseVitre(static_cast<char>(couleur), colLots));
                    int perte = vitrail2.construireVitrail(vecteurLots, colVitrail);

                    joueur2.removePoints(perte);
                    if (vitrail2.estComplete(colVitrail)) {
                        joueur2.addPoints(3);
                        for (int i = colVitrail-1; i >= 0; i--){
                            if (vitrail2.estEnConstruction(i)){
                                joueur2.addPoints(1);
                            }
                        }
                    }

                    std::cout << joueur2;
                    std::cout << lots;
                    tour = !tour;
                }
            }
            catch(std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            catch(std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
        }
        else {
            if (tour) { ~joueur1; }
            else { ~joueur2; }
            tour = !tour;
        }
    }
}