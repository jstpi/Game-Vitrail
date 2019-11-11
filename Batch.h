class Batch {
    // permettant de contenir les lots de vitres disponible. Elle contient un
    // tableau de 4 par 5 caractères représentant les 5 lots ainsi qu’un
    // std ::vector<char> pour le surplus.
    // La classe doit avoir la méthode permettant de ramasser les vitres d’un lot :
    // vector<char> ramasseVitre(char couleur, int numeroLot);
    // Si le numéro de lot est négatif, cela signifie que les vitres sont ramassées dans le
    // surplus. La méthode retourne toutes les vitres de la couleur spécifiée. Les vitres
    // restantes sont transférées dans le surplus.
    // Il doit aussi y avoir une méthode permettant de recharger les lots en tirant au hasard
    // des couleurs pour chaque lot (avec un surplus vide) :
    // void reset();
    // Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    // console des lots comme suit :
};