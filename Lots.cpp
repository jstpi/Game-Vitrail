/**
 * @file Lots.cpp
 *
 * @brief Methodes pour construire et manipuler (ramasser les vitres) des lots.
 *
 * @author Jeremie St-Pierre (8628942), Frederik Lafleche (8616081)
 */

#include "Lots.h"
#include "Couleur.h"
#include <iostream>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const Lots& l){
    char** lots = l.getLots();
    int cols = l.getCols();
    int rangs = l.getRangs();
    std::vector<char> surplus = l.getSurplus();
    std::string colorOut;
    std::string colOut;
    std::string surplusOut;
    colorOut += "\nLots: \n";
    for (int j = 0; j < rangs; j++) {
        for (int i = cols-1; i >= 0; i--) {
            colorOut += lots[i][j];
            colorOut += " ";
        }
        colorOut += "\n";
    }
    for (int i = cols-1; i >= 0; i--) {
        colOut += std::to_string(i);
        colOut += " ";
    }
    colOut += "\n";    

    surplusOut += "\nSurplus: \n";
    surplusOut += "[";
    for(auto it = surplus.begin(); it != surplus.end(); it++) {
        surplusOut += *it;
    }
    surplusOut+= "]\n";
    os << colorOut << colOut << surplusOut;
    return os;
}

bool isNone(char color) {
    return (color == static_cast<char>(Couleur::vide));
}

Lots::Lots(int cols, int rangs): lots(new char*[cols]), cols(cols), rangs(rangs) {
    for (int i = 0; i < Lots::cols; i++) {
        Lots::lots[i] = new char[Lots::rangs];         
        for(int j = 0; j < Lots::rangs; j++) {
            Lots::lots[i][j]=static_cast<char>(getCouleurAleatoire());
        }
    }
}

void Lots::reset(){
    for (int i = 0; i < Lots::cols; i++) {      
        for(int j = 0; j < Lots::rangs; j++){
            Lots::lots[i][j]=static_cast<char>(getCouleurAleatoire());
        }
    }
}

std::vector<char> Lots::ramasseVitre(char couleur, int numeroLot){
    std::vector<char> ret;
    std::vector<char>::iterator it; 
    if(numeroLot<0){
        if (Lots::surplus.size()==0){
            throw std::invalid_argument("!! Le surplus est vide; le tour reste le meme !!");
        }

        for (it = surplus.begin(); it != surplus.end(); it++){
            if (*it == couleur){
                ret.push_back(*it);
                it=surplus.erase(it);
                it--;
            }     
        }
        if (ret.size() == 0) {
            throw std::invalid_argument("!! La couleur specifie n'est pas presente dans le surplus; le tour reste le meme !!");
        }
    }
    else if (numeroLot>=0 && numeroLot<Lots::cols){
        if (Lots::lots[numeroLot][0]==static_cast<char>(Couleur::vide)){
            throw std::invalid_argument("!! Le lot a deja ete selectionne; le tour reste le meme !!");
        }
        for (int i=0; i<Lots::rangs; i++){
            if(Lots::lots[numeroLot][i]==couleur){
                ret.push_back(couleur);
                Lots::lots[numeroLot][i] = static_cast<char>(Couleur::vide);
            }
            else{
                surplus.push_back(Lots::lots[numeroLot][i]);
                Lots::lots[numeroLot][i] = static_cast<char>(Couleur::vide);
            }
        }
        
    }
    return ret;
}

bool Lots::isLotsEmpty(){
    for (int i = 0; i < Lots::cols; i++){
        char* begin = Lots::lots[i];
        char* end = Lots::lots[i]+Lots::rangs;
        char* couleur = std::find_if_not(begin, end, isNone);
        if (couleur != end) {
            return false;
        }
    }
    return true;
}
