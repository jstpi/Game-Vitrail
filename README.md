# Jeu Vitrail
Project pour le cours CSI2772 de l'Université d'Ottawa. Ce project est une implémentation en c++ d'une version du jeu vitrail. Ce jeu est affiché dans le terminal.

## Instruction

### Context
Le but du jeu est de d'accumuler le plus le point possible en complétant des colonnes dans sont plan de vitrine.

### Pièces de jeu
* Plan

`
Plan: 
R R G G G R R 
R R B G J R R 
R R B G J R R 
R B B J J B R 
R B B J J B R 
6 5 4 3 2 1 0
`

* Lots
* Surplus:


## Membre du projet
* Jérémie St-Pierre (8628942)
* Frederik Laflèche (8616081)

## Exécuter le jeu (g++)
> g++ Vitrail.cpp Couleur.cpp Lots.cpp projetCSI2772.cpp -o main
> ./main

## Source
### .h
* Couleur.h
* Joueur.h
* Lots.h
* Vitrail.h
### .cpp
* Couleur.cpp
* Lots.cpp
* Vitrail.cpp
* projetCSI2772.cpp
### autre
* output.txt (exemple de sortie)

