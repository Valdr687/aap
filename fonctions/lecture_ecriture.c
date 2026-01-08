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

    // Sauter la première ligne (taille et type)
    fgets(tampon, sizeof(tampon), fichier_à_lire);

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

t_graph_list list_lecture_trmnl(t_type *type, char ***sommets)
{
    // Demander taille et type de sommet (nombre ou texte)

    int taille = 0;
    int type_int = 0;

    printf("Entrez le nombre de sommets : ");
    scanf("%d", &taille);
    printf("Entrez le type de graphe (0 pour INT, 1 pour STR) : ");
    scanf("%d", &type_int);
    *type = (t_type)type_int;


    // Création du graphe
    t_graph_list graphe = graph_list_new(taille);
    printf("Taille = %d et le type %d \n", taille, *type);

    // Allocation du tableau de sommets si type STR
    if (*type == STR)
    {
        *sommets = malloc(taille * sizeof(char *));
        assert(*sommets != NULL);
        printf("Entrez les noms des sommets (un par ligne) :\n");
    }
    else
    {
        printf("Entrez les arêtes (ex: '0 1'). Terminez par Ctrl+D :\n");
    }

    // Lecture des sommets
    int sommet_lu = 0;
    char tampon[MAX_LEN];

    while (fgets(tampon, sizeof(tampon), stdin) != NULL)
    {
        if (tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (*type == STR && sommet_lu < taille)
            {
                (*sommets)[sommet_lu] = slice(tampon, 0, strlen(tampon) - 1);
                sommet_lu++;
                if (sommet_lu == taille)
                {
                    printf("Noms des sommets enregistrés. Entrez les arêtes (ex: 'Nom1 Nom2') :\n");
                }
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
    // Allocation du tableau de sommets si type STR
    if (*type == STR)
    {
        *sommets = malloc(taille * sizeof(char *));
        assert(*sommets != NULL);
    }

    // Lecture des sommets
    int sommet_lu = 0;
    char tampon[MAX_LEN];

    // Sauter la première ligne (taille et type)
    fgets(tampon, sizeof(tampon), fichier_à_lire);

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

t_graph_mat *mat_lecture_trmnl(t_type *type, char ***sommets)
{
    // Demander taille et type de sommet (nombre ou texte)

    int taille = 0;
    int type_int = 0;

    printf("Entrez le nombre de sommets : ");
    scanf("%d", &taille);
    printf("Entrez le type de graphe (0 pour INT, 1 pour STR) : ");
    scanf("%d", &type_int);
    *type = (t_type)type_int;

    // Création du graphe
    t_graph_mat *graphe = graph_mat_new(taille);
    printf("Taille = %d et le type %d \n", taille, *type);

    // Allocation du tableau de sommets si type STR
    if (*type == STR)
    {
        *sommets = malloc(taille * sizeof(char *));
        assert(*sommets != NULL);
        printf("Entrez les noms des sommets (un par ligne) :\n");
    }
    else
    {
        printf("Entrez les arêtes (ex: '0 1'). Terminez par Ctrl+D (ou Ctrl+Z sous Windows) :\n");
    }

    // Lecture des sommets
    int sommet_lu = 0;
    char tampon[MAX_LEN];

    while (fgets(tampon, sizeof(tampon), stdin) != NULL)
    {
        if (tampon[0] != '\n' && tampon[1] != '\0') // On ne traite pas les lignes vides
        {
            if (*type == STR && sommet_lu < taille)
            {
                (*sommets)[sommet_lu] = slice(tampon, 0, strlen(tampon) - 1);
                sommet_lu++;
                if (sommet_lu == taille)
                {
                    printf("Noms des sommets enregistrés. Entrez les arêtes (ex: 'Nom1 Nom2') :\n");
                }
            }
            else if (*type == INT)
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);
                if (chaine_divisee[0] != NULL && chaine_divisee[1] != NULL)
                {
                    sscanf(chaine_divisee[0], "%d", &sommet0);
                    sscanf(chaine_divisee[1], "%d", &sommet1);

                    graph_mat_add_edge(graphe, sommet0, sommet1);
                }

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1] != NULL)
                {
                    if (chaine_divisee[1][0] != '\0')
                        free(chaine_divisee[1]);
                }
                free(chaine_divisee);
            }
            else
            {
                t_vertex sommet0;
                t_vertex sommet1;

                char **chaine_divisee = division(tampon);

                if (chaine_divisee[0] != NULL && chaine_divisee[1] != NULL)
                {
                    sommet0 = rang_par_valeur(chaine_divisee[0], *sommets, taille);
                    sommet1 = rang_par_valeur(chaine_divisee[1], *sommets, taille);

                    graph_mat_add_edge(graphe, sommet0, sommet1);
                }

                // Libération de la mémoire
                free(chaine_divisee[0]);
                if (chaine_divisee[1] != NULL)
                {
                    if (chaine_divisee[1][0] != '\0')
                        free(chaine_divisee[1]);
                }
                free(chaine_divisee);
            }
        }
    }
    return graphe;
}

/////////////////////////////// Ecriture dans un fichier .dot ///////////////////////////////

void graph_list_ecriture_dot(t_graph_list *g, t_type type, char **sommets, char *chemin)
{
    FILE *fichier_à_écrire = fopen(chemin, "w");

    fprintf(fichier_à_écrire, "digraph G {\n");

    t_vertex sommet_courant;
    for (sommet_courant = 0; sommet_courant < g->size; sommet_courant++)
    {
        // Traitement du maillon courant
        t_node *courant;
        courant = list_cursor_new(g->l[sommet_courant]);
        while (!list_cursor_at_end(courant))
        {
            t_vertex voisin = list_cursor_get_val(courant);
            if (type == INT)
            {
                fprintf(fichier_à_écrire, "%d -> %d;\n", sommet_courant, voisin);
            }
            else if (type == STR)
            {
                fprintf(fichier_à_écrire, "%s -> %s;\n", sommets[sommet_courant], sommets[voisin]);
            }
            courant = list_cursor_next(courant);
        }
    }

    fprintf(fichier_à_écrire, "}\n");

    fclose(fichier_à_écrire);
}

void graph_mat_ecriture_dot(t_graph_mat *g, t_type type, char **sommets, char *chemin)
{
    FILE *fichier_à_écrire = fopen(chemin, "w");

    fprintf(fichier_à_écrire, "digraph G {\n");

    t_vertex sommet_courant;
    for (sommet_courant = 0; sommet_courant < g->size; sommet_courant++)
    {
        t_vertex voisin;
        for (voisin = 0; voisin < g->size; voisin++)
        {
            if (g->m[sommet_courant][voisin] == 1)
            {
                if (type == INT)
                {
                    fprintf(fichier_à_écrire, "%d -> %d;\n", sommet_courant, voisin);
                }
                else if (type == STR)
                {
                    fprintf(fichier_à_écrire, "%s -> %s;\n", sommets[sommet_courant], sommets[voisin]);
                }
            }
        }
    }

    fprintf(fichier_à_écrire, "}\n");

    fclose(fichier_à_écrire);
}

void graph_list_ecriture_dot_trml(t_graph_list *g, t_type type, char **sommets)
{

    printf("digraph G {\n");

    t_vertex sommet_courant;
    for (sommet_courant = 0; sommet_courant < g->size; sommet_courant++)
    {
        // Traitement du maillon courant
        t_node *courant;
        courant = list_cursor_new(g->l[sommet_courant]);
        while (!list_cursor_at_end(courant))
        {
            t_vertex voisin = list_cursor_get_val(courant);
            if (type == INT)
            {
                printf("%d -> %d;\n", sommet_courant, voisin);
            }
            else if (type == STR)
            {
                printf("%s -> %s;\n", sommets[sommet_courant], sommets[voisin]);
            }
            courant = list_cursor_next(courant);
        }
    }

    printf("}\n");
}

void graph_mat_ecriture_dot_trml(t_graph_mat *g, t_type type, char **sommets)
{
    printf("digraph G {\n");

    t_vertex sommet_courant;
    for (sommet_courant = 0; sommet_courant < g->size; sommet_courant++)
    {
        t_vertex voisin;
        for (voisin = 0; voisin < g->size; voisin++)
        {
            if (g->m[sommet_courant][voisin] == 1)
            {
                if (type == INT)
                {
                    printf("%d -> %d;\n", sommet_courant, voisin);
                }
                else if (type == STR)
                {
                    printf("%s -> %s;\n", sommets[sommet_courant], sommets[voisin]);
                }
            }
        }
    }

    printf("}\n");
}