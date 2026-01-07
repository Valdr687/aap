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

// Fonction briques
char **division(char *t);
char *slice(char *str, size_t start, size_t end);
int rang_par_valeur(char *s, char **t, int taille);

/////////////////////////////// Lecture dans un fichier ///////////////////////////////

// Version liste d'adjacences
t_graph_list list_lecture(char *chemin)
{

    FILE *fichier_à_lire = fopen(chemin, "r");

    // Vérification que le fichier ne soit pas nul
    if (fichier_à_lire == NULL)
    {
        t_graph_list graphe = graph_list_new(-1);
        return graphe;
    }

    // Détecter taille et type de sommet (nombre ou texte)

    // Lecture du fichier
    char tampon[MAX_LEN];
    int taille;
    t_type type;

    // Lecture de la première ligne
    fgets(tampon, sizeof(tampon), fichier_à_lire);

    // Division
    char **chaine_divisee = division(tampon);
    sscanf(chaine_divisee[0], "%d", &taille);

    if (chaine_divisee[1] != "")
    {
        type = STR;
    }
    else
    {
        type = INT;
    }
    t_graph_list graphe = graph_list_new(taille);

    printf("Taille = %d et le type %d \n", taille, type);
    char **sommets = malloc(taille * sizeof(char *)); // Déclaration en amont pour éviter une erreur
    int sommet_lu = 0;                                // Numéro du sommet lu
    while (fgets(tampon, sizeof(tampon), fichier_à_lire) != NULL)
    {
        if (tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (type == STR && sommet_lu < taille)
            {
                sommets[sommet_lu] = strdup(slice(tampon, 0, strlen(tampon) - 1));
                sommet_lu++;
            }
            if (type == INT)
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);
                sscanf(chaine_divisee[0], "%d", &sommet0);
                sscanf(chaine_divisee[1], "%d", &sommet1);

                graph_list_add_edge(&graphe, sommet0, sommet1);
            }
            else
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);

                sommet0 = rang_par_valeur(chaine_divisee[0], sommets, taille);
                sommet1 = rang_par_valeur(chaine_divisee[1], sommets, taille);

                graph_list_add_edge(&graphe, sommet0, sommet1);
            }
        }
    }
    fclose(fichier_à_lire);
    return graphe;
}

// Version matrice d'adjacences
t_graph_mat *mat_lecture(char *chemin)
{

    FILE *fichier_à_lire = fopen(chemin, "r");

    // Vérification que le fichier ne soit pas nul
    if (fichier_à_lire == NULL)
    {
        t_graph_mat *graphe = graph_mat_new(-1);
        return graphe;
    }

    // Détecter taille et type de sommet (nombre ou texte)

    // Lecture du fichier
    char tampon[MAX_LEN];
    int taille;
    t_type type;

    // Lecture de la première ligne
    fgets(tampon, sizeof(tampon), fichier_à_lire);

    // Division
    char **chaine_divisee = division(tampon);
    sscanf(chaine_divisee[0], "%d", &taille);

    if (chaine_divisee[1] != "")
    {
        type = STR;
    }
    else
    {
        type = INT;
    }
    t_graph_mat *graphe = graph_mat_new(taille);

    printf("Taille = %d et le type %d \n", taille, type);
    char **sommets = malloc(taille * sizeof(char *)); // Déclaration en amont pour éviter une erreur
    int sommet_lu = 0;                                // Numéro du sommet lu
    while (fgets(tampon, sizeof(tampon), fichier_à_lire) != NULL)
    {
        if (tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (type == STR && sommet_lu < taille)
            {
                sommets[sommet_lu] = strdup(slice(tampon, 0, strlen(tampon) - 1));
                sommet_lu++;
            }
            if (type == INT)
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);
                sscanf(chaine_divisee[0], "%d", &sommet0);
                sscanf(chaine_divisee[1], "%d", &sommet1);

                graph_mat_add_edge(graphe, sommet0, sommet1);
            }
            else
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);

                sommet0 = rang_par_valeur(chaine_divisee[0], sommets, taille);
                sommet1 = rang_par_valeur(chaine_divisee[1], sommets, taille);

                graph_mat_add_edge(graphe, sommet0, sommet1);
            }
        }
    }
    fclose(fichier_à_lire);
    return graphe;
}
/////////////////////////////// Ecriture dans un fichier .dot ///////////////////////////////

// Fonctions briques

// TODO : Description
char **division(char *t)
{
    int i = 0;
    size_t taille = strlen(t);
    char **result = malloc(2 * sizeof(char *));

    for (i; i < taille; i++)
    {
        printf("%c \n", t[i]);
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
    if (end < start)
        end = start;
    size_t len = end - start;
    char *result = malloc(len + 1);
    memcpy(result, str + start, len);
    result[len] = '\0';
    return result;
}

// Retourne l'indice d'une chaîne dans un tableau de chaînes, -1 si non trouvée
// Utilisation : int rang = rang_par_valeur(chaine, tableau_de_chaines, taille_tableau);
int rang_par_valeur(char *s, char **t, int taille)
{
    int i = 0;
    for (i; i < taille; i++)
    {
        if (strcmp(s, t[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}