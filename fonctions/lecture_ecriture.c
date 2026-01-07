#include "lecture_ecriture.h"

/////////////////////////////// Lecture dans un fichier ///////////////////////////////

// Version liste d'adjacences
t_graph_list list_lecture(char *chemin, t_type *type, char ***sommets)
{
    // Détecter taille et type de sommet (nombre ou texte)

    // Lecture du fichier
    int taille = 0;

    *type = caracteristiques_graphe(chemin, &taille);

    // Vérification que le fichier ne soit pas nul
    if (taille == -1)
    {
        t_graph_list graphe = graph_list_new(-1);
        return graphe;
    }

    // Création du graphe
    t_graph_list graphe = graph_list_new(taille);
    printf("Taille = %d et le type %d \n", taille, *type);

    // Allocation du tableau de sommets si type STR
    if (*type == STR)
    {
        *sommets = malloc(taille * sizeof(char *));
        assert(*sommets != NULL);
    }

    // Lecture des sommets
    FILE *fichier_à_lire = fopen(chemin, "r");

    int sommet_lu = 0;
    char tampon[MAX_LEN];

    while (fgets(tampon, sizeof(tampon), fichier_à_lire) != NULL)
    {
        if (tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (*type == STR && sommet_lu < taille)
            {
                (*sommets)[sommet_lu] = slice(tampon, 0, strlen(tampon) - 1);
                sommet_lu++;
            }
            else if (*type == INT)
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);
                sscanf(chaine_divisee[0], "%d", &sommet0);
                sscanf(chaine_divisee[1], "%d", &sommet1);

                graph_list_add_edge(&graphe, sommet0, sommet1);

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1][0] != '\0')
                    free(chaine_divisee[1]);
                free(chaine_divisee);
            }
            else
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);

                sommet0 = rang_par_valeur(chaine_divisee[0], *sommets, taille);
                sommet1 = rang_par_valeur(chaine_divisee[1], *sommets, taille);

                graph_list_add_edge(&graphe, sommet0, sommet1);

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1][0] != '\0')
                    free(chaine_divisee[1]);
                free(chaine_divisee);
            }
        }
    }
    fclose(fichier_à_lire);
    return graphe;
}

// Version matrice d'adjacences
t_graph_mat *mat_lecture(char *chemin, t_type *type, char ***sommets)
{
    // Détecter taille et type de sommet (nombre ou texte)

    // Lecture du fichier
    int taille = 0;

    *type = caracteristiques_graphe(chemin, &taille);

    // Vérification que le fichier ne soit pas nul
    if (taille == -1)
    {
        t_graph_mat *graphe = graph_mat_new(-1);
        return graphe;
    }

    // Création du graphe
    FILE *fichier_à_lire = fopen(chemin, "r");

    t_graph_mat *graphe = graph_mat_new(taille);
    printf("Taille = %d et le type %d \n", taille, *type);

    // Allocation du tableau de sommets si type STR
    if (*type == STR)
    {
        *sommets = malloc(taille * sizeof(char *));
        assert(*sommets != NULL);
    }

    // Lecture des sommets
    int sommet_lu = 0;
    char tampon[MAX_LEN];

    while (fgets(tampon, sizeof(tampon), fichier_à_lire) != NULL)
    {
        if (tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (*type == STR && sommet_lu < taille)
            {
                (*sommets)[sommet_lu] = slice(tampon, 0, strlen(tampon) - 1);
                sommet_lu++;
            }
            else if (*type == INT)
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);
                sscanf(chaine_divisee[0], "%d", &sommet0);
                sscanf(chaine_divisee[1], "%d", &sommet1);

                graph_mat_add_edge(graphe, sommet0, sommet1);

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1][0] != '\0')
                    free(chaine_divisee[1]);
                free(chaine_divisee);
            }
            else
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);

                sommet0 = rang_par_valeur(chaine_divisee[0], *sommets, taille);
                sommet1 = rang_par_valeur(chaine_divisee[1], *sommets, taille);

                graph_mat_add_edge(graphe, sommet0, sommet1);

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1][0] != '\0')
                    free(chaine_divisee[1]);
                free(chaine_divisee);
            }
        }
    }
    fclose(fichier_à_lire);
    return graphe;
}
/////////////////////////////// Ecriture dans un fichier .dot ///////////////////////////////
