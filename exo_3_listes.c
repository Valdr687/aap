#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "./fonctions/base_fil_rouge.h"
#include "./fonctions/lecture_ecriture.h"
#include "./fonctions/base.h"

#define N 100

t_vertex order[N];

void kosaraju_1_recur_list(t_graph_list * g, t_vertex x, t_bool marking[], t_vertex order[], int * step);
void kosaraju_1_list(t_graph_list *g);
t_bool kosaraju_2_recur_list(t_graph_list *g, t_vertex x, t_bool marking[], t_type type, char **sommets);
void g_order_list(t_graph_list *g);
void enum_cfc_kosaraju_list(t_graph_list * g, t_type type, char **sommets);

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

    kosaraju_1_list(&graphe);
    enum_cfc_kosaraju_list(&graphe, type, sommets);

    // Libération de la mémoire
    if (type == STR)
    {
        sommets_free(sommets, graphe.size);
    }
    graph_list_free(&graphe);

    return 0;
}

void kosaraju_1_recur_list(t_graph_list * g, t_vertex x, t_bool marking[], t_vertex order[], int * step){
    t_vertex y;
    t_node * lc = list_cursor_new(g->l[x]);
    if (marking[x]) return; // si le sommet a déjà été visité, on ne continue pas dans le programme
    marking[x] = 1;

    while (!list_cursor_at_end(lc))
    {
        y = list_cursor_get_val(lc);
        if (!marking[y])
        {
            kosaraju_1_recur_list(g, y, marking, order, step);
        }
        lc = list_cursor_next(lc);
    }
    order[*step] = x;
    (*step)++;
}

void kosaraju_1_list(t_graph_list *g){
    t_bool marking[N] = {0};
    int step = 0;
    for (t_vertex x = 0; x < g->size; x++)
        if (!marking[x])
            kosaraju_1_recur_list(g, x, marking, order, &step);

    printf("Suffix order:\n");
    for (int i = 0; i < step; i++)
        printf("%d ", order[i]);
    printf("\n");

}

t_bool kosaraju_2_recur_list(t_graph_list *g, t_vertex x, t_bool marking[], t_type type, char **sommets){
    if (marking[x])
        return 0;
    marking[x] = 1;
    if (type == STR)
        printf("%s ", sommets[x]);
    else
        printf("%d ", x);
    t_node *lc = list_cursor_new(g->l[x]);  // head of adjacency list
    while (!list_cursor_at_end(lc)) {
        t_vertex y = list_cursor_get_val(lc);
        kosaraju_2_recur_list(g, y, marking, type, sommets);
        lc = list_cursor_next(lc);
    }
    return 1;
}

void kosaraju_2_list(t_graph_list *g, t_type type, char **sommets){
    t_bool marking[N] = {0};
    int inv_order[N];
    t_vertex x;
    t_graph_list * g_inv = graph_inverse_list(g);
    int nb_scc = 0;
    for (int i = 0; i<g->size; i++)
        inv_order[i] = order[g->size-1-i];
    for (x = 0; x < g->size; x++)
        if (kosaraju_2_recur_list(g_inv, inv_order[x], marking, type, sommets))
        {
            nb_scc++;
            printf("\n");
        }
    printf("%d composante(s) fortement connexe(s) trouvée(s)\n", nb_scc);
}

void enum_cfc_kosaraju_list(t_graph_list * g, t_type type, char **sommets)
{
    t_bool marking[N] = {0};
    int inv_order[N];
    int nb_scc = 0;

    kosaraju_1_list(g); // parcours en profondeur dans le graphe original
    printf("\n");
    t_graph_list * g_inv = graph_inverse_list(g); // construction du graphe inverse

    for (int i = 0; i < g->size; i++) //ordre suffice inverse
        inv_order[i] = order[g->size - 1 - i];

    for (t_vertex x = 0; x < g->size; x++) // parcours en profondeur dans le graphe inverse
    {
        if (kosaraju_2_recur_list(g_inv, inv_order[x], marking, type, sommets))
        {
            nb_scc++;
            printf("\n");
        }
    }

    printf("%d CFC trouvée(s)\n", nb_scc);

    graph_list_free(g_inv);
    free(g_inv);
}
