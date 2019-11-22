#include "Lots.h"
#include "Couleur.h"
#include <iostream>

Lots::Lots(): lots(5, std::vector<char>(4, 'x')) {
    std::vector<std::vector<char>>::iterator it;
    for (it = lots.begin(); it != lots.end(); it++){
        std::vector<char>::iterator it2;
        for (it2 = (*it).begin(); it2 != (*it).end(); it2++){
            *it2 = static_cast<char>(getCouleurAleatoire());
        }
    }
}

void Lots::reset(){
    std::vector<std::vector<char>>::iterator it;
    for (it = lots.begin(); it != lots.end(); it++){
        std::vector<char>::iterator it2;
        for (it2 = (*it).begin(); it2 != (*it).end(); it2++){
            *it2 = static_cast<char>(getCouleurAleatoire());
        }
    }
    surplus.clear();
}

std::vector<char> Lots::ramasseVitre(char couleur, int numeroLot){
    auto selectIt = lots.begin()+numeroLot; 
    std::vector<char> ret;
    std::vector<char>::iterator it; 
    if(numeroLot<0){
        for (it = surplus.begin(); it != surplus.end(); it++){
            if (*it == couleur){
                ret.push_back(*it);
                it=surplus.erase(it);
                it--;
            }     
        }
    }
    else if (numeroLot>=0 && numeroLot<lots.size()){
        for (it = (*selectIt).begin(); it != (*selectIt).end(); it++){
            if (*it == couleur){
                ret.push_back(*it);
            }
            else{
                surplus.push_back(*it);
            }
            *it=static_cast<char>(Couleur::vide);
        }
    }
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Lots& l){
    std::vector<std::vector<char>> lots = l.getLots();
    std::vector<char> surplus = l.getSurplus();
    std::string output("");
    int i = 0;
    for (auto it2 = lots.rbegin()->begin(); it2 != lots.rbegin()->end(); i++, it2++) {
        for (auto it = lots.rbegin(); it != lots.rend(); it++) {
            output += (*it)[i];
            output += " ";
        }
        output += "\n";
    }
    int colNum = lots.size()-1;
    for (auto itColNum = lots.begin(); itColNum != lots.end(); itColNum++, colNum--) {
        output += std::to_string(colNum);
        output += " ";
    }
    output += "\nSurplus: \n";
    output += "[";
    for(auto it = surplus.begin(); it != surplus.end(); it++) {
        output += *it;
    }
    output += "]\n";
    os << output;
    return os;
}
