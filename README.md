# Jeu Vitrail
Project pour le cours CSI2772 de l'Université d'Ottawa. Ce project est une implémentation en c++ d'une version du jeu: Vitrail. Ce jeu est affiché dans le terminal.

## Instruction du jeu

### Context
Le but du jeu est d'accumuler le plus de point possible en complétant des colonnes dans son plan de vitrine.

### Pièces de jeu
* **Plan**: 7 colonnes de couleurs uniques pour chaque joueur à compléter

```
(ex)
R R G G G R R 
R R B G J R R 
R R B G J R R 
R B B J J B R 
R B B J J B R 
6 5 4 3 2 1 0
```

* **Lots**: 5 colonnes de couleurs partagées aux 2 joueurs pour appliquer à la complétion du plan

```
(ex)
G O O J O 
R J R B J 
R R G B B 
R J B G B 
4 3 2 1 0 
```

* **Surplus**: liste de couleurs restant partagée aux 2 joueurs pour appliquer à la complétion du plan
```
(ex)
[JBB]
```

### Flot de jeu
Chaque joueur débute avec leur propre plan à compléter et ont ensuite un ensemble de lots partagés. Le jeu se déroule par la suite en séquence de tours. Voici l'exemple d'un tour:

-> le joueur peut agir sur le plan de la colonne 6 -> 0
```
--> Au tour du premier joueur.

JER : 0 points 
Vitrier a la position 6.
```

-> le joueur a son propre plan, mais partage les lots et le surplus avec son adversaire
```
Plan: 
R R G G G R R 
R R B G J R R 
R R B G J R R 
R B B J J B R 
R B B J J B R 
6 5 4 3 2 1 0 

Lots: 
G O O J O 
R J R B J 
R R G B B 
R J B G B 
4 3 2 1 0 

Surplus: 
[]
```

-> le joueur choisit de poser des vitres
```
(1) Action: 
Entrez votre choix (1:poser vitre, 2:deplacer vitrier): 1
```

-> pour poser des vitres, une colonne du lot doit être utilisée; la colonne 1 (J B B G) fut choisie
```
(2) Poser Vitre: 
Entrez l'index du lots (-1:surplus, x:lot): 1
```

-> une seule couleur à la fois peut être appliqué; la couleur grise (G) fut choisie
```
Choisissez votre couleur (1:Bleu, 2:Gris, 3:Orange, 4:Rose, 5:Jaune): 2
```

-> avec la position à 6, le joueur peut choisir une colonne d'index 6 -> 0 pour appliquer la couleur à compléter; la colonne 4 fut choisie
```
Entrez l'index du vitrail (x:vitrail): 4
```

-> sous ce choix d'action, une seule couleur grise fut prise du lot de la colonne 1 pour compléter la couleur grise de plan à la colonne 4

-> cela met le joueur à la position 4, maintenant sous contrainte de faire des actions sur la colonne d'index 4 -> 0 du plan pour son prochain tour

```
JER : 0 points 
Vitrier a la position 4.

Plan: 
R R x G G R R 
R R B G J R R 
R R B G J R R 
R B B J J B R 
R B B J J B R 
6 5 4 3 2 1 0 

Lots: 
G O O . O 
R J R . J 
R R G . B 
R J B . B 
4 3 2 1 0 

Surplus: 
[JBB]
```
* **gagner des points**: 5 points par colonne complétée du plan (complétion indiqué par "x")
* **perdre des points**: -1 point par couleur prise du lot ou du surplus qui ne participe pas à la complétion d'une couleur du plan

## Exécuter le jeu
1. Installer un compilateur [GCC](https://gcc.gnu.org/)
2. Télécharger ce code source
3. Executer ces commandes dans le fichier du projet:
```
> g++ Vitrail.cpp Couleur.cpp Lots.cpp projetCSI2772.cpp -o main
> ./main
```

## Membre du projet
* Jérémie St-Pierre
* Frederik Laflèche
