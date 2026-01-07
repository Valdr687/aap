#ifndef BASE_FIL_ROUGE_H
#define BASE_FIL_ROUGE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_READ_LINE 100

// Types de base
typedef int t_bool;    // Booléen
typedef int t_vertex;  // Sommet de graphe

// Maillon de liste chaînée
typedef struct node {
  t_vertex val;          // Valeur (sommet)
  struct node * p_next;  // Pointeur vers le maillon suivant
} t_node;

// Liste chaînée (de sommets)
typedef t_node * t_list;

// Pile (de sommets)
typedef t_list t_stack;

// Graphe par liste d'adjacence
typedef struct {
  int size; // Taille
  t_list * l; // Contenu (tableau de listes chaînées)
} t_graph_list; 

// Graphe par matrice d'adjacence
typedef struct {
  int size; // Taille
  t_bool ** m; // Contenu (tableau à 2 dimensions)
} t_graph_mat;


//////// Graphes ////////
t_graph_mat * graph_mat_new(int size);
void graph_mat_add_edge(t_graph_mat * g, t_vertex u, t_vertex v);
t_graph_mat * graph_inverse(t_graph_mat * g);
t_graph_list * graph_inverse_list(t_graph_list *g);
void graph_free(t_graph_mat * g);

t_graph_list graph_list_new(int size);
void graph_list_add_edge(t_graph_list * g, t_vertex u, t_vertex p);
void graph_list_free(t_graph_list *g);

//////// Piles ////////
void stack_show(t_stack * ps);
t_stack * stack_new();
int stack_is_empty(t_stack * ps);
void stack_push(t_vertex e, t_stack * ps);
t_vertex stack_pop(t_stack * ps);
t_vertex stack_top(t_stack * ps);

//////// Listes chaînées ////////
t_list list_new();
t_list list_add_head(t_vertex e, t_list l);
int list_is_empty(t_list l);
void list_show(t_list l);
t_vertex list_get_first_val(t_list l);
t_list list_remove_head(t_list l);
t_list list_free(t_list l);
t_node * list_cursor_new(t_list l);
int list_cursor_at_end(t_node * lc);
int list_cursor_get_val(t_node * lc);
t_node * list_cursor_next(t_node * lc);

#endif // BASE_FIL_ROUGE_H
