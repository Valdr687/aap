#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_fil_rouge.c"
#define MAX_LEN 100

// Types
typedef enum
{
    INT,
    STR
} t_type;

char **division(char *t);
char *slice(char *str, size_t start, size_t end);

// Lecture dans un fichier
t_graph_list lecture(char *chemin)
{
    t_graph_list graphe = creer_graphe_liste();

    FILE *fichier_à_lire = fopen(chemin, "r");

    // Vérification que le fichier ne soit pas nul
    if (fichier_à_lire==NULL) {
        perror("Impossible d'ouvrir le fichier");
        graphe.size = -1;
        return graphe;
    }

    // Détecter taille et type de sommet (nombre ou texte)

    // Lecture du fichier
    int vrai_nombre_ligne = 0; // Numéro actuel de la ligne lue sans les sauts
    char tampon[MAX_LEN];

    int taille;
    t_type type;

    while (fgets(tampon, sizeof(tampon), fichier_à_lire) != NULL)
    {
        printf("%s", tampon);
        if (vrai_nombre_ligne == 0)
        {
            // Division
            char **chaine_divisee = division(tampon);
            sscanf(chaine_divisee[0], "%d", &taille);

            if (chaine_divisee[1] != "") 
            {
                type = STR;
            }

            printf("Taille = %d et le type %d",taille,type);
        }

        if (tampon[1] != '\0')
        {
            vrai_nombre_ligne++;
        }
    }

    fclose(fichier_à_lire);
    return graphe;
}

// Ecriture dans un fichier .dot

// Fonctions briques

// TODO : Description

char **division(char *t)
{
    int i;
    size_t taille = strlen(t);
    char **result = malloc(2 * sizeof(char*));

    for (i; i < taille; i++)
    {
        if (t[i] == ' ' || t[i] == '\t')
        {
            result[0] = slice(t, 0, i);
            result[1] = slice(t, i + 1, taille - 1); // On enlève le \n à la fin

            return result;
        }
    }

    result[0] = slice(t, 0, taille - 1);
    result[1] = "";
    
    return result;
}

// TODO : Description
char *slice(char *str, size_t start, size_t end)
{
    if (end < start) end = start;
    size_t len = end - start;
    char *result = malloc(len + 1);
    memcpy(result, str + start, len);
    result[len] = '\0';
    return result;
}