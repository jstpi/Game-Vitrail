class Glass {
    public:
        Glass(int numCol, int numGl){}

    // La description du vitrail se fait donc à l’aide d’un tableau 2D de
    // caractères (char**) qui doit être alloué dynamiquement. Chaque colonne du vitrail est
    // initialisée de la facon suivante : 2 couleurs sont choisies au hasard; puis un nombre
    // aléatoire H entre 0 et le nombre de cases dans la colonne est tiré. Les H premières
    // cases de la colonne seront de la première couleur et le reste des cases seront de la
    // seconde couleur (donc il ne peut y avoir que 1 ou 2 couleurs dans une colonne).
    // Cette classe doit aussi avoir les méthodes suivantes :
    // int construireVitrail(std ::vector<char> vitres, int colonne);
    // Les vitres contenues dans le vecteur sont ajoutées à la colonne spécifiée. Les
    // caractères correspondants sont donc remplacés par des x afin de signifier que cette
    // vitre a été installée. La méthode retourne le nombre de vitres qui n’ont pas pu être
    // placées. Si la colonne spécifiée est déjà complétée, cette méthode doit lancer une
    // exception de type std ::invalid_argument.
    // bool estComplete(int colonne);
    // qui retourne vrai si le vitrail de cette colonne a été complétée.
    // bool estEnConstruction(int colonne);
    // qui retourne vrai si au moins une vitre de ce vitrail a été installée.
    // Cette classe doit aussi surcharger l’opérateur d’insertion << permettant l’affichage à la
    // console de l’état des vitraux comme suit : 
};