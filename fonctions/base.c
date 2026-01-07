#include "base.h"

// TODO : Description
char **division(char *t)
{
    int i = 0;
    size_t taille = strlen(t);
    char **result = malloc(2 * sizeof(char *));
    assert(result != NULL);

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
    assert(result != NULL);
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

// Retourne le type du graphe (INT ou STR) et la taille du graphe en fonction du fichier
t_type caracteristiques_graphe(char *chemin, int * taille) {
    t_type type;

    // Vérification que le fichier ne soit pas nul

    FILE *fichier_à_lire = fopen(chemin, "r");
    if (fichier_à_lire == NULL)
    {
        *taille = -1;
        return type;
    }
    char tampon[MAX_LEN];

    // Lecture de la première ligne
    fgets(tampon, sizeof(tampon), fichier_à_lire);

    // Division
    char **chaine_divisee = division(tampon);
    sscanf(chaine_divisee[0], "%d", taille);

    if (strcmp(chaine_divisee[1], "") != 0)
    {
        type = STR;
    }
    else
    {
        type = INT;
    }

    // Libération de la mémoire allouée par division
    free(chaine_divisee[0]);
    if (chaine_divisee[1][0] != '\0')  // Si non vide ""
        free(chaine_divisee[1]);
    free(chaine_divisee);

    fclose(fichier_à_lire);

    return type;
}