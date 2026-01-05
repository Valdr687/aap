#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "base_fil_rouge.h"

#define N 100

t_vertex order[N];

int kosaraju_1_recur(t_graph_mat * g, t_vertex x, t_bool marking[], t_vertex order[], int step);
void kosaraju_1(t_graph_mat *g);
t_bool kosaraju_2_recur(t_graph_mat *g, t_vertex x, t_bool marking[]);
void kosaraju_2(t_graph_mat *g);
void g_order(t_graph_mat *g);
void enum_cfc_kosaraju(t_graph_mat * g);

/* int main(){
    t_graph_mat * g = graph_new(4);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0,2);
    graph_add_edge(g, 2,1);
    graph_add_edge(g, 2,3);
    graph_add_edge(g, 3,2);
    for (int i = 0; i< g->size; i++)
    {
        for (int j = 0; j < g->size; j++)
        {
            printf("%d ", g->m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    enum_cfc_kosaraju(g);
    graph_free(g);
    return 0;
} */

int kosaraju_1_recur(t_graph_mat * g, t_vertex x, t_bool marking[], t_vertex order[], int step){
    marking[x] = 1;
    for (int y = 0; y < g->size; y++)
        { // sur chaque sommet du graphe …
        if (g->m[x][y] && !marking[y])
        {
            // … on parcourt la boucle seulement si on n'est pas encore passé par le sommet y
            step = kosaraju_1_recur(g,y,marking, order, step);
            //printf("%d\n", step);
        }
    }
    order[step] = x; //ordre suffixe
    return step+1; // étape finale du parcours actuel
}

void kosaraju_1(t_graph_mat *g){ // sert d'initialisation de toutes les variables nécéssaires dans la fonction récursive
    t_bool marking[N] = {0};
    //t_vertex order[N];
    int step = 0;
    for (t_vertex x = 0; x < g->size; x++)
    {
        if (!marking[x])
        {
            kosaraju_1_recur(g, x, marking, order, step);
        }
    }
}

t_bool kosaraju_2_recur(t_graph_mat *g, t_vertex x, t_bool marking[]){
    /* recherche d'une nouvelle CFC --> retourne faux si on est déjà passé par le sommet x
        retourne vrai s'il y a une nouvelle CFC
    */
    if (marking[x]){ /* est-ce que x appartient déjà à une CFC ?
                        si oui, on retourne 0, car on a déjà exploré cette CFC*/
        return 0;
    } else {
        marking[x] = 1; // si non, on marque le sommet comme exploré
        printf("%d ", x);
        for (t_vertex y = 0; y < g->size; y++)
        {
            if (g->m[x][y])
                kosaraju_2_recur(g, y, marking);
        }
        return 1;
    }
}

void kosaraju_2(t_graph_mat *g){
    t_bool marking[N] = {0}; // initialisation de tous les marquages à 0
    int inv_order[N]; // tableau qui stocke l'ordre suffixe inverse
    t_vertex x;
    int nb_scc = 0; //nb de CFC trouvées
    for (x = 0; x < g->size; x++)
        inv_order[(g->size -1) - order[x]] = x;
    for (x = 0; x < g->size; x++)
    {
        if (kosaraju_2_recur(g, inv_order[x], marking))
        {
            nb_scc ++;
            printf("\n");
        }
    }
    printf("%d composante(s) fortement connexe(s) trouvée(s)\n", nb_scc);
}

void enum_cfc_kosaraju(t_graph_mat * g){
    t_bool marking[N] = {0};
    int inv_order[N];
    t_vertex x;
    int nb_scc = 0;
    kosaraju_1(g);
    t_graph_mat * g_inv = graph_inverse(g);
    for (x = 0; x < g->size; x++)
        inv_order[(g->size -1) - order[x]] = x;
    for (x = 0; x < g->size; x++)
        if (kosaraju_2_recur(g, inv_order[x], marking))
        {
            nb_scc ++;
            printf("\n");
        }
    printf("%d CFC trouvée(s)\n", nb_scc);
}
