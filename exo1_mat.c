#include <stdio.h>
#include <string.h>
#include "./fonctions/lecture_ecriture.h"

void erreur_option(char *option);
void erreur_arguments(int ArgumentCount);
int est_option_valide(char *option, char OptionsValides[][3]);

int main(int ArgumentCount, char **ArgumentList)
{
    char OptionsValides[2][3] = {"-i", "-o"};

    char *entree = NULL;
    char *sortie = NULL;

    if (ArgumentCount > 5) // Teste si on a un nombre d'argument possible, sinon sortie
    {
        erreur_arguments(ArgumentCount - 1);
        return 0;
    }

    // Vérification des arguments

    int i;
    int validites[4] = {0};

    for (i = 1; i < ArgumentCount; i++)
    {
        int validite = est_option_valide(ArgumentList[i], OptionsValides);
        if (validite == 0)
        {
            erreur_option(ArgumentList[i]);
            return 0;
        }
        else
        {
            validites[i] = validite;
        }
    }

    // Extraction des paramètres

    for (i=0; i < ArgumentCount - 1; i++)
    {
        if (validites[i] == 1) // Option est -i
        {
            if (validites[i + 1] == -1)
            {
                entree = ArgumentList[i + 1];
            }
        }
        if (validites[i] == 2) // Option est -o
        {
            if (validites[i + 1] == -1)
            {
                sortie = ArgumentList[i + 1];
            }
        }
    }

    // Lecture

    t_type type;
    char **sommets = NULL;
    t_graph_mat *graphe;
    
    if (entree != NULL) // Depuis un fichier
    {
        graphe = mat_lecture(entree, &type, &sommets);
        if (graphe->size == -1)
        {
            printf("Le fichier est vide ou n'existe pas.\n");
            return 0;
        }
    }
    else // Lecture depuis le terminal (stdin)
    {
        graphe = mat_lecture_trmnl(&type, &sommets);
    }

    // Ecriture

    // Dans un fichier

    if (sortie != NULL)
    {
        graph_mat_ecriture_dot(graphe, type, sommets, sortie);
    }
    else // Vers le terminal (stdout)
    {
        graph_mat_ecriture_dot_trml(graphe, type, sommets);
    }
    
    // Libération de la mémoire
    if (type == STR && sommets != NULL)
    {
        for (int i = 0; i < graphe->size; i++)
        {
            free(sommets[i]);
        }
        free(sommets);
    }
    
    return 0;
}

// Affiche une erreur si un argument n'est pas reconnu ou est en doublon
void erreur_option(char *option)
{
    printf("Argument non reconnu ou en doublon: %s \n", option);
    printf("Utilisation : \n     ./fil_rouge_1 [-i <fichier_graphe>] [-o <fichier-dot>] \n Arguments : \n     -i <fichier_graphe> : le fichier graphe à lire \n     -o <fichier_dot> : le fichier dot à produire\n");
}

// Affiche une erreur s'il y a trop d'arguments
void erreur_arguments(int RealArgumentCount)
{
    printf("Trop d'arguments ont été entrés : maximum 4, reçus %d\n", RealArgumentCount);
}

// Teste si une option est valide et utilisée une unique fois
int est_option_valide(char *option, char OptionsValides[][3])
{
    if (option[0] == '-') // est une option
    {
        if (strcmp(option, OptionsValides[0]) == 0)
        {
            strcpy(OptionsValides[0], ""); // un argument ne peut pas être vide
            return 1;                      // 1 pour input
        }
        if (strcmp(option, OptionsValides[1]) == 0)
        {
            strcpy(OptionsValides[1], "");
            return 2; // 2 pour output
        }
        else
        {
            return 0;
        }
    }
    return -1;
}