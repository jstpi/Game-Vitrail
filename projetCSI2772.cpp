/**
 * @file projectCSI2772.cpp
 *
 * @brief Déroulement principale du jeu.
 *
 * @author Jeremie St-Pierre (8628942), Frederik Lafleche (8616081)
 */

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
    std::cout << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "*                           *" << std::endl;
    std::cout << "*        V I T R A I L      *" << std::endl;
    std::cout << "*                           *" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << std::endl;
    std::cout << "------------ Joueurs ------------" << std::endl;
    std::string nom1;
    std::cout << "Premier joueur, entrez votre nom: ";
    std::cin >> nom1;

    Vitrail vitrail1(7, 5);
    Joueur joueur1(nom1, &vitrail1);

    std::string nom2;
    std::cout << "Deuxieme joueur, entrez votre nom: ";
    std::cin >> nom2;
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl;

    Vitrail vitrail2(7, 5);
    Joueur joueur2(nom2, &vitrail2);

    Lots lots(5, 4);

    bool tour(true);
    int countNumReset(0);

    std::cout << "********* Jeu 5 phases **********" << std::endl;
    std::cout << std::endl;

    while(countNumReset < 5) {

        if (lots.isLotsEmpty() && lots.getSurplus().size()==0) {
            lots.reset();
            countNumReset++;
            continue;
        }
        
        std::cout << "~~~~~~~~~~~~~~~~~~~(phase " << countNumReset+1 <<")~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;

        if (tour) { std::cout << "--> Au tour du premier joueur." << std::endl << std::endl << joueur1; }
        else { std::cout << "--> Au tour du second joueur." << std::endl << std::endl << joueur2; }

        std::cout << lots;
        std::cout << std::endl;

        int colLots(-2);
        int choixCouleur(0);
        int colVitrail(-1);
        int choixJeu(0);
        int posPrecJoueur(0);

        std::cout << "(1) Action: " << std::endl;

        while (!valideChoix(choixJeu)) {
            while (std::cout << "Entrez votre choix (1:poser vitre, 2:deplacer vitrier): " && !(std::cin >> choixJeu)) {
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                std::cout << "< Input invalide; entrez de nouveau >" << std::endl;
            }
        }

        std::cout << std::endl;

        if (choixJeu == 1) {

            std::cout << "(2) Poser Vitre: " << std::endl;

            while (!valideColLot(lots, colLots)) {
                while (std::cout << "Entrez l'index du lots (-1:surplus, x:lot): " && !(std::cin >> colLots)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "< Input invalide; entrez de nouveau >" << std::endl;
                }
            }
            while (!valideCouleurChoix(choixCouleur)) {
                while (std::cout << "Choisissez votre couleur (1:Bleu, 2:Gris, 3:Orange, 4:Rose, 5:Jaune): " && !(std::cin >> choixCouleur)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "< Input invalide; entrez de nouveau >" << std::endl;
                }
            }
            while (!valideColVitrail(vitrail1, colVitrail)) {
                while (std::cout << "Entrez l'index du vitrail (x:vitrail): " && !(std::cin >> colVitrail)) {
                    std::cin.clear(); //clear bad input flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    std::cout << "< Input invalide; entrez de nouveau >" << std::endl;
                }
            }
            try {
                Couleur couleur(getCouleurParChoix(choixCouleur));
                if (tour) {
                    posPrecJoueur = joueur1.getPosition();
                    joueur1-=(joueur1.getPosition()-colVitrail);
                    std::vector<char> vecteurLots(lots.ramasseVitre(static_cast<char>(couleur), colLots));
                    int perte = vitrail1.construireVitrail(vecteurLots, colVitrail);
                    
                    joueur1.removePoints(perte);
                    if (perte > 0) { std::cout << std::endl << "- "<< perte <<" points" << std::endl; }
                    if (vitrail1.estComplete(colVitrail)) {
                        joueur1.addPoints(3);
                        std::cout << std::endl << "+ 3 points" << std::endl;
                        for (int i = colVitrail-1; i >= 0; i--){
                            if (vitrail1.estEnConstruction(i)){
                                int pointCol = vitrail1.vitrailCompletParCol(i);
                                std::cout << std::endl << "+ "<< pointCol <<" points de vitrail "<< i << std::endl;
                                joueur1.addPoints(pointCol);
                            }
                        }
                    }
                    
                    std::cout << std::endl;
                    std::cout << joueur1;
                    std::cout << lots;
                    tour = !tour;
                }
                else {
                    posPrecJoueur = joueur2.getPosition();
                    joueur2-=(joueur2.getPosition()-colVitrail);
                    std::vector<char> vecteurLots(lots.ramasseVitre(static_cast<char>(couleur), colLots));
                    int perte = vitrail2.construireVitrail(vecteurLots, colVitrail);

                    joueur2.removePoints(perte);
                    if (perte > 0) { std::cout << std::endl << "- "<< perte <<" points" << std::endl; }
                    if (vitrail2.estComplete(colVitrail)) {
                        joueur2.addPoints(3);
                        std::cout << std::endl << "+ 3 points" << std::endl;
                        for (int i = colVitrail-1; i >= 0; i--){
                            if (vitrail2.estEnConstruction(i)){
                                int pointCol = vitrail2.vitrailCompletParCol(i);
                                std::cout << std::endl << "+ "<< pointCol <<" points de vitrail "<< i << std::endl;
                                joueur2.addPoints(pointCol);
                            }
                        }
                    }

                    std::cout << std::endl;
                    std::cout << joueur2;
                    std::cout << lots;
                    tour = !tour;
                }
            }
            catch(std::invalid_argument& e) {
                std::cout << std::endl;
                std::cout << e.what() << std::endl;
                if (tour) {
                    joueur1.setPosition(posPrecJoueur);
                }
                else {
                    joueur2.setPosition(posPrecJoueur);
                }
            }
            catch(std::out_of_range& e) {
                std::cout << std::endl;
                std::cout << e.what() << std::endl;
            }
        }
        else {

            std::cout << "<-- Deplacement a la position " << vitrail1.getCols()-1 << std::endl;

            if (tour) {
                if (joueur1.getPosition() != vitrail1.getCols()-1) {
                    ~joueur1; 
                    tour = !tour;
                }
                else { 
                    std::cout << "!! Joueur 1 dejas a la position " << vitrail1.getCols()-1 <<"; le tour reste le meme !!" << std::endl;
                }
            }
            else { 
                if (joueur2.getPosition() != vitrail2.getCols()-1) {
                    ~joueur2; 
                    tour = !tour;
                }
                else { 
                    std::cout << "!! Joueur 2 dejas a la position " << vitrail2.getCols()-1 <<"; le tour reste le meme !!" << std::endl;
                }
            }
        }
        std::cout << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "*** Fin du jeu ***" << std::endl;
    std::cout << std::endl;
    std::cout << joueur1.getName() << " : " << joueur1.getPoints() << std::endl;
    std::cout << joueur2.getName() << " : " << joueur2.getPoints() << std::endl;
    std::cout << std::endl;
    if (joueur1.getPoints() > joueur2.getPoints()) {
        std::cout << "*** " << joueur1.getName() << " est le GAGNANT!" << " ***" << std::endl;
    }
    else {
        std::cout << "*** " << joueur2.getName() << " est le GAGNANT!" << " ***" << std::endl;
    }
    std::cout << std::endl;
}