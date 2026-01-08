#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "./fonctions/base_fil_rouge.h"
#include "./fonctions/lecture_ecriture.h"
#include "./fonctions/base.h"

#define N 20000

t_vertex order[N];

int kosaraju_1_recur(t_graph_mat *g, t_vertex x, t_bool marking[], t_vertex order[], int step);
void kosaraju_1(t_graph_mat *g);
t_bool kosaraju_2_recur(t_graph_mat *g, t_vertex x, t_bool marking[], t_type type, char **sommets);
void kosaraju_2(t_graph_mat *g, t_type type, char **sommets);
void g_order(t_graph_mat *g);
void enum_cfc_kosaraju(t_graph_mat *g, t_type type, char **sommets);

int main(int ArgumentCount, char **ArgumentList)
{

    char *entree = NULL;
    // Extraction des paramètres
    int erreur = parametres_exo3(ArgumentCount, ArgumentList, &entree);
    if (erreur == -1)
    {
        return 0;
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
    kosaraju_1(graphe);
    enum_cfc_kosaraju(graphe, type, sommets);

    // Libération de la mémoire
    if (type == STR)
    {
        sommets_free(sommets, graphe->size);
    }
    graph_free(graphe);

    return 0;
}

int kosaraju_1_recur(t_graph_mat *g, t_vertex x, t_bool marking[], t_vertex order[], int step)
{
    marking[x] = 1;
    for (int y = 0; y < g->size; y++)
    { // sur chaque sommet du graphe …
        if (g->m[x][y] && !marking[y])
        {
            // … on parcourt la boucle seulement si on n'est pas encore passé par le sommet y
            step = kosaraju_1_recur(g, y, marking, order, step);
            // printf("%d\n", step);
        }
    }
    order[step] = x; // ordre suffixe
    return step + 1; // étape finale du parcours actuel
}

void kosaraju_1(t_graph_mat *g)
{ // sert d'initialisation de toutes les variables nécéssaires dans la fonction récursive
    t_bool marking[N] = {0};
    // t_vertex order[N];
    int step = 0;
    for (t_vertex x = 0; x < g->size; x++)
    {
        if (!marking[x])
        {
            step = kosaraju_1_recur(g, x, marking, order, step);
        }
    }
}

t_bool kosaraju_2_recur(t_graph_mat *g, t_vertex x, t_bool marking[], t_type type, char **sommets)
{
    /* recherche d'une nouvelle CFC --> retourne faux si on est déjà passé par le sommet x
        retourne vrai s'il y a une nouvelle CFC
    */
    if (marking[x])
    { /* est-ce que x appartient déjà à une CFC ?
         si oui, on retourne 0, car on a déjà exploré cette CFC*/
        return 0;
    }
    else
    {
        marking[x] = 1; // si non, on marque le sommet comme exploré
        if (type == STR)
            printf("%s ", sommets[x]);
        else
            printf("%d ", x);
        for (t_vertex y = 0; y < g->size; y++)
        {
            if (g->m[x][y])
                kosaraju_2_recur(g, y, marking, type, sommets);
        }
        return 1;
    }
}

void kosaraju_2(t_graph_mat *g, t_type type, char **sommets)
{
    t_bool marking[N] = {0}; // initialisation de tous les marquages à 0
    int inv_order[N];        // tableau qui stocke l'ordre suffixe inverse
    t_vertex x;
    int nb_scc = 0; // nb de CFC trouvées
    for (int i = 0; i < g->size; i++)
        inv_order[i] = order[g->size - 1 - i];
    for (x = 0; x < g->size; x++)
    {
        if (kosaraju_2_recur(g, inv_order[x], marking, type, sommets))
        {
            nb_scc++;
            printf("\n");
        }
    }
    printf("%d composante(s) fortement connexe(s) trouvée(s)\n", nb_scc);
}

void enum_cfc_kosaraju(t_graph_mat *g, t_type type, char **sommets)
{
    t_bool marking[N] = {0};
    int inv_order[N];
    t_vertex x;
    int nb_scc = 0;
    kosaraju_1(g);
    t_graph_mat *g_inv = graph_inverse(g);
    for (int i = 0; i < g->size; i++)
        inv_order[i] = order[g->size - 1 - i];
    for (x = 0; x < g->size; x++)
        if (kosaraju_2_recur(g_inv, inv_order[x], marking, type, sommets))
        {
            nb_scc++;
            printf("\n");
        }
    printf("%d CFC trouvée(s)\n", nb_scc);
    graph_free(g_inv);
}