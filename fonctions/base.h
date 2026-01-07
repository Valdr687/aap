#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// Types
typedef enum
{
    INT,
    STR
} t_type;

// Fonctions utilitaires
char **division(char *t);
char *slice(char *str, size_t start, size_t end);
int rang_par_valeur(char *s, char **t, int taille);
t_type caracteristiques_graphe(char *chemin, int *taille);

#endif // BASE_H
