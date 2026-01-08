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
