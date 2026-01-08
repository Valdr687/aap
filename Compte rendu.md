# Compte rendu

BOUBLIL Mathilde, BOYER Nina, CASANOVA Thomas

## Introduction

Ce compte rendu a pour objet le fil d'AAP de 2025-2026. Le but de ce projet était d’implémenter les graphes sous forme de matrice d’adjacence avec
allocation dynamique, et sous forme de listes d’adjacence. Les graphes utilisés pouvaient avoir des sommets avec des nombres ou du texte.

Ce fil rouge était décomposé en trois parties :

1) Lecture d'un graphe dans un fichier et écriture au format DOT
2) Recherche d'un chemin dans un graphe
3) Recherche de composantes fortement connexe

## Organisation des programmes

Les programmes sont organisés de la manière suivante :

```txt
.
├── fonctions/
│   ├── base_fil_rouge.c
│   ├── base_fil_rouge.h
│   ├── base.c
│   ├── base.h
│   ├── lecture_ecriture.c
│   └── lecture_ecriture.h
├── graphes/
│   ├── noms/
│   │   └── ...
│   └── numéros/
│       └── ...
├── Makefile
├── exo1_mat.c
├── exo1_list.c
├── exo2_mat.c
├── exo2_list.c
├── exo3_mat.c
├── exo3_list.c
└── README.md
```

## Structures de données manipulées

### Structure des fichiers de test

### Implémentation des données

## Fonctionnement des programmes

### Exercice 1

Exercice 1 : Conversion d’un graphe au format DOT

Ce programme est organisé de la façon suivante :
Lecture des arguments
Lecture du graphe dans un fichier ou la console
Ecriture dans un fichier DOT ou la console
Lecture des arguments

Pour valider les arguments on en distingue deux types :
les options (-i, -o, -start, -go)
les paramètres (la valeur associée à l’option)

Ces arguments ne pouvant exister qu’en nombre limité le programme affiche une erreur s’il en a trop (plus que 4 dans le 1, plus de 6 dans le 2…).

Les options valides sont stockées dans un tableau de façon à pouvoir les comparer aux options rentrées, et ce sont les options que l’on valide en premier :
Pour chaque argument :
on regarde si c’est une option (si option[0] == '-')
Si cette option existe dans le tableau alors elle est valide et on sait à quoi elle correspond et on la supprime dans le tableau pour éviter les doublons
Sinon on affiche le message d’erreur
sinon on la considère non valide (validité = 0)
Pour chaque argument on regarde sa validité
Si sa validité est non nulle et la validité de l’argument suivant oui (s’il existe) alors c’est un paramètre (chemin du fichier à lire par exemple)
Si la validité du sommet suivant n’est pas nulle c’est qu’il n’y a pas de fichier à lire ou dans lequel écrire, on utilisera le terminal

#### Lecture du fichier
 
Le programme prend en charge deux modes de lecture : depuis un fichier ou depuis le terminal (stdin).

**Lecture depuis un fichier :**

La lecture se déroule en plusieurs étapes :

1. **Détection des caractéristiques** : La fonction `caracteristiques_graphe()` analyse la première ligne du fichier pour déterminer :
   - La taille du graphe (nombre de sommets)
   - Le type de sommets (INT pour des nombres, STR pour du texte)

2. **Création de la structure** : Selon le type de représentation (matrice ou liste), on initialise la structure de données avec `graph_mat_new(taille)` ou `graph_list_new(taille)`.

3. **Allocation des sommets** : Si le type est STR, on alloue un tableau de chaînes de caractères pour stocker les noms des sommets.

4. **Lecture ligne par ligne** :
   - On saute la première ligne (déjà lue pour les caractéristiques)
   - Pour les graphes de type STR : on lit d'abord tous les noms des sommets (une ligne par sommet)
   - Ensuite, on lit les arêtes : chaque ligne contient deux sommets séparés par un espace
   - La fonction `division()` découpe chaque ligne en deux parties (sommet source et sommet destination)
   - Pour les graphes STR, `rang_par_valeur()` convertit les noms en indices numériques
   - L'arête est ajoutée avec `graph_mat_add_edge()` ou `graph_list_add_edge()`

5. **Fermeture du fichier** : Le fichier est fermé et le graphe construit est retourné.

**Lecture depuis le terminal :**

Si aucun fichier d'entrée n'est spécifié, le programme lit depuis stdin :
- Demande interactive du nombre de sommets
- Demande du type (0 pour INT, 1 pour STR)
- Lecture des noms des sommets si type STR
- Lecture des arêtes jusqu'à EOF (Ctrl+D sur Linux, Ctrl+Z sur Windows)

#### Écriture au format DOT

Le programme écrit le graphe au format DOT, compatible avec l'outil de visualisation Graphviz. L'écriture peut se faire dans un fichier ou sur la sortie standard.

**Processus d'écriture :**

1. **Ouverture** : Si un fichier de sortie est spécifié (option `-o`), on l'ouvre en écriture. Sinon, on écrit sur stdout.

2. **En-tête DOT** : On écrit `digraph G {` pour indiquer le début d'un graphe orienté.

3. **Parcours du graphe** :
   - **Pour une matrice** : On parcourt la matrice d'adjacence. Pour chaque case `[i][j]` égale à 1, on écrit `i -> j;` (ou avec les noms si type STR).
   - **Pour une liste** : On parcourt chaque liste d'adjacence. Pour chaque voisin dans la liste, on écrit l'arête correspondante.
   - Les arêtes sont formatées selon le type :
     - Type INT : `0 -> 1;`
     - Type STR : `SommetA -> SommetB;`

4. **Fermeture** : On termine par `}` et on ferme le fichier.

Le format DOT produit peut ensuite être converti en image avec des outils comme `dot -Tpng fichier.dot -o graphe.png`.

### Exercice 2

### Exercice 3

## Choix effectués par rapport au sujet

## Performances

## Organisation

## Difficultés rencontrées et aspects non traités

### Difficultés

La première erreur que nous avons

## Conversion

Le programme vérifie que les options soient valides mais ne vérifie pas les noms des fichiers, en effet cela n'a pas d'importance sur Linux.

## Erreurs rencontrées

Cascade de test : else if teste toujours donc erreur
utilisition de fichiers.h

1) Compilation multiple
2) Plus aisé pour les makefiles
3) Violations ODR (One Definition Rule)
4) Mais marche pour un cas simple comme ici

## Remarque

pas d'argument considère entre et sortie vide

## Bibliographie et outils

### Outils

- Pour générer l'arbre du dossier : [tree.nathanfriend.com](https://tree.nathanfriend.com/)
- Pour coder de façon collaborative : Git et Github
