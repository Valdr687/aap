#include "lecture_ecriture.h"

//////////////////////////////// Gestion des paramètres ///////////////////////////////

// Lit les arguments de ligne de commande pour extraire les fichiers d'entrée et de sortie
// Retourne 0 en cas de succès, -1 en cas d'erreur
// Utilisation : 
//   char *entree = NULL, *sortie = NULL;
//   if (parametres_lecture_ecriture(argc, argv, &entree, &sortie) == -1) return 0;
int parametres_lecture_ecriture(int ArgumentCount, char **ArgumentList, char **entree, char **sortie)
{
    char OptionsValides[2][3] = {"-i", "-o"};

    if (ArgumentCount > 5) // Teste si on a un nombre d'argument possible, sinon sortie
    {
        erreur_arguments(ArgumentCount - 1, 4);
        return -1;
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
            return -1;
        }
        else
        {
            validites[i] = validite;
        }
    }

    // Extraction des paramètres

    for (i = 0; i < ArgumentCount - 1; i++)
    {
        if (validites[i] == 1) // Option est -i
        {
            if (validites[i + 1] == -1)
            {
                *entree = ArgumentList[i + 1];
            }
        }
        if (validites[i] == 2) // Option est -o
        {
            if (validites[i + 1] == -1)
            {
                *sortie = ArgumentList[i + 1];
            }
        }
    }

    return 0;
}

// Lit les arguments de ligne de commande pour l'exercice 2 (avec options -start et -goal)
// Retourne 0 en cas de succès, -1 en cas d'erreur
// Utilisation :
//   char *entree = NULL, *start = NULL, *goal = NULL;
//   if (parametres_exo2(argc, argv, &entree, &start, &goal) == -1) return 0;
int parametres_exo2(int ArgumentCount, char **ArgumentList, char **entree, char **start, char **goal)
{
    char OptionsValides[4][7] = {"-i","-start","-goal"};

    if (ArgumentCount > 7) // Teste si on a un nombre d'argument possible, sinon sortie
    {
        erreur_arguments(ArgumentCount - 1, 6);
        return -1;
    }

    // Vérification des arguments

    int i;
    int validites[7] = {0};

    for (i = 1; i < ArgumentCount; i++)
    {
        int validite = est_option_valide_exo2(ArgumentList[i], OptionsValides);
        if (validite == 0)
        {
            erreur_option_exo2(ArgumentList[i]);
            return -1;
        }
        else
        {
            validites[i] = validite;
        }
    }

    // Extraction des paramètres

    for (i = 0; i < ArgumentCount - 1; i++)
    {
        if (validites[i] == 1) // Option est -i
        {
            if (validites[i + 1] == -1)
            {
                *entree = ArgumentList[i + 1];
            }
        }
        if (validites[i] == 2) // Option est -start
        {
            if (validites[i + 1] == -1)
            {
                *start = ArgumentList[i + 1];
            }
        }
        if (validites[i] == 3) // Option est -goal
        {
            if (validites[i + 1] == -1)
            {
                *goal = ArgumentList[i + 1];
            }
        }
    }
    return 0;
}

// Lit les arguments de ligne de commande pour l'exercice 3 (uniquement option -i)
// Retourne 0 en cas de succès, -1 en cas d'erreur
// Utilisation :
//   char *entree = NULL;
//   if (parametres_exo3(argc, argv, &entree) == -1) return 0;
int parametres_exo3(int ArgumentCount, char **ArgumentList, char **entree)
{
    char OptionsValides[1][3] = {"-i"};

    if (ArgumentCount > 3) // Teste si on a un nombre d'argument possible, sinon sortie
    {
        erreur_arguments(ArgumentCount - 1, 2);
        return -1;
    }

    // Vérification des arguments

    int i;
    int validites[3] = {0};

    for (i = 1; i < ArgumentCount; i++)
    {
        int validite = est_option_valide(ArgumentList[i], OptionsValides);
        if (validite == 0)
        {
            erreur_option_exo3(ArgumentList[i]);
            return -1;
        }
        else
        {
            validites[i] = validite;
        }
    }

    // Extraction des paramètres

    for (i = 0; i < ArgumentCount - 1; i++)
    {
        if (validites[i] == 1) // Option est -i
        {
            if (validites[i + 1] == -1)
            {
                *entree = ArgumentList[i + 1];
            }
        }
    }
    return 0;
}

// Affiche une erreur si un argument n'est pas reconnu ou est en doublon lors de la lecture des fichiers et l'écriture (exo 1 et 3)
void erreur_option(char *option)
{
    printf("Argument non reconnu ou en doublon: %s \n", option);
    printf("Utilisation : \n     ./fichier [-i <fichier_graphe>] [-o <fichier-dot>] \n Arguments : \n     -i <fichier_graphe> : le fichier graphe à lire \n     -o <fichier_dot> : le fichier dot à produire\n");
}

// Affiche une erreur si un argument n'est pas reconnu ou est en doublon lors des paramètres de l'exo 2
void erreur_option_exo2(char *option)
{
    printf("Argument non reconnu ou en doublon: %s \n", option);
    printf("Utilisation : \n     ./fichier [-start <sommet>] [-goal <sommet>] [-i <fichier_graphe>] \n Arguments : \n     -i <fichier_graphe> : le fichier graphe à lire \n     -start <sommet> : le sommet de départ \n     -goal <sommet> : le sommet d'arrivée\n");
}

// Affiche une erreur si un argument n'est pas reconnu ou est en doublon lors de l'exercice 3
void erreur_option_exo3(char *option)
{
    printf("Argument non reconnu ou en doublon: %s \n", option);
    printf("Utilisation : \n     ./fichier [-i <fichier_graphe>] \n Arguments : \n     -i <fichier_graphe> : le fichier graphe à lire\n");
}

// Affiche une erreur s'il y a trop d'arguments
void erreur_arguments(int RealArgumentCount, int max_arguments)
{
    printf("Trop d'arguments ont été entrés : maximum %d, reçus %d\n", max_arguments, RealArgumentCount);
}

// Teste si une option est valide et utilisée une unique fois
// Retourne 1 pour -i, 2 pour -o, 0 pour option invalide, -1 si ce n'est pas une option
// Utilisation :
//   char OptionsValides[2][3] = {"-i", "-o"};
//   int validite = est_option_valide(argv[i], OptionsValides);
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

// Teste si une option est valide et utilisée une unique fois pour l'exercice 2
// Retourne 1 pour -i, 2 pour -start, 3 pour -goal, 0 pour option invalide, -1 si ce n'est pas une option
// Utilisation :
//   char OptionsValides[3][7] = {"-i", "-start", "-goal"};
//   int validite = est_option_valide_exo2(argv[i], OptionsValides);
int est_option_valide_exo2(char *option, char OptionsValides[][7])
{
    if (option[0] == '-') // est une option
    {
        if (strcmp(option, OptionsValides[0]) == 0)
        {
            strcpy(OptionsValides[0], ""); // un argument ne peut pas être vide
            return 1;                      // 1 pour -i
        }
        if (strcmp(option, OptionsValides[1]) == 0)
        {
            strcpy(OptionsValides[1], "");
            return 2; // 2 pour -start
        }
        if (strcmp(option, OptionsValides[2]) == 0)
        {
            strcpy(OptionsValides[2], "");
            return 3; // 3 pour -goal
        }
        else
        {
            return 0;
        }
    }
    return -1;
}

/////////////////////////////// Lecture dans un fichier ///////////////////////////////

// Lit un graphe depuis un fichier et le stocke en liste d'adjacences
// Le fichier doit commencer par la taille et optionnellement les noms des sommets
// Retourne un graphe avec size=-1 en cas d'erreur
// Utilisation :
//   t_type type;
//   char **sommets = NULL;
//   t_graph_list graphe = list_lecture("graphe.txt", &type, &sommets);
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

// Lit un graphe depuis le terminal (stdin) et le stocke en liste d'adjacences
// Demande interactivement la taille, le type et les arêtes du graphe
// Utilisation :
//   t_type type;
//   char **sommets = NULL;
//   t_graph_list graphe = list_lecture_trmnl(&type, &sommets);
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

// Lit un graphe depuis un fichier et le stocke en matrice d'adjacences
// Le fichier doit commencer par la taille et optionnellement les noms des sommets
// Retourne NULL en cas d'erreur
// Utilisation :
//   t_type type;
//   char **sommets = NULL;
//   t_graph_mat *graphe = mat_lecture("graphe.txt", &type, &sommets);
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

// Lit un graphe depuis le terminal (stdin) et le stocke en matrice d'adjacences
// Demande interactivement la taille, le type et les arêtes du graphe
// Utilisation :
//   t_type type;
//   char **sommets = NULL;
//   t_graph_mat *graphe = mat_lecture_trmnl(&type, &sommets);
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

// Écrit un graphe (liste d'adjacences) au format DOT dans un fichier
// Le fichier peut ensuite être visualisé avec Graphviz
// Utilisation :
//   graph_list_ecriture_dot(&graphe, type, sommets, "output.dot");
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

// Écrit un graphe (matrice d'adjacences) au format DOT dans un fichier
// Le fichier peut ensuite être visualisé avec Graphviz
// Utilisation :
//   graph_mat_ecriture_dot(graphe, type, sommets, "output.dot");
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

// Affiche un graphe (liste d'adjacences) au format DOT sur le terminal (stdout)
// Utilisation :
//   graph_list_ecriture_dot_trml(&graphe, type, sommets);
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

// Affiche un graphe (matrice d'adjacences) au format DOT sur le terminal (stdout)
// Utilisation :
//   graph_mat_ecriture_dot_trml(graphe, type, sommets);
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