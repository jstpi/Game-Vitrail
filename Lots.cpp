#include "Lots.h"
#include "Couleur.h"
#include <iostream>

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
        for(int j = 0; i< Lots::rangs; j++){
            Lots::lots[i][j]=static_cast<char>(getCouleurAleatoire());
        }
    }
    surplus.clear();
}

std::vector<char> Lots::ramasseVitre(char couleur, int numeroLot){
    std::vector<char> ret;
    std::vector<char>::iterator it; 
    if(numeroLot<0){
        if (Lots::surplus.size()==0){
            throw std::invalid_argument("Le surplus est vide.");
        }

        for (it = surplus.begin(); it != surplus.end(); it++){
            if (*it == couleur){
                ret.push_back(*it);
                it=surplus.erase(it);
                it--;
            }     
        }
        if (ret.size() == 0) {
            throw std::invalid_argument("La couleur specifie n'est pas presente dans le surplus.");
        }
    }
    else if (numeroLot>=0 && numeroLot<Lots::cols){
        if (Lots::lots[numeroLot][0]==static_cast<char>(Couleur::vide)){
            throw std::invalid_argument("Le lot a deja ete selectionne.");
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
