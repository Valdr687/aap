#include <stdio.h>
#include <string.h>
#include "./fonctions/lecture_ecriture.h"

int main(int ArgumentCount, char **ArgumentList)
{
    char *entree = NULL;
    char *sortie = NULL;
    // Extraction des paramètres

    int erreur = parametres_lecture_ecriture(ArgumentCount, ArgumentList, &entree, &sortie);
    if (erreur == -1) {
        return 0;
    }
    // Lecture

    t_type type;
    char **sommets = NULL;
    t_graph_list graphe;
    
    if (entree != NULL) // Depuis un fichier
    {
        graphe = list_lecture(entree, &type, &sommets);
        if (graphe.size == -1)
        {
            printf("Le fichier est vide ou n'existe pas.\n");
            return 0;
        }
    }
    else // Lecture depuis le terminal (stdin)
    {
        graphe = list_lecture_trmnl(&type, &sommets);
    }

    // Ecriture

    // Dans un fichier

    if (sortie != NULL)
    {
        graph_list_ecriture_dot(&graphe, type, sommets, sortie);
    }
    else // Vers le terminal (stdout)
    {
        graph_list_ecriture_dot_trml(&graphe, type, sommets);
    }
    
    // Libération de la mémoire
    if (type == STR)
    {
        sommets_free(sommets, graphe.size);
    }
    
    return 0;
}