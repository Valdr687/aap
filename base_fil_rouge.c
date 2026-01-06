#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_READ_LINE 100

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

// Graphe par liste d'adjacence (défini dans le sujet)
typedef struct {
  int size; // Taille
  t_list * l; // Contenu (tableau de listes chaînées)
} t_graph_list; 

// Graphe par matrice d'adjacence (défini dans le sujet)
typedef struct {
  int size; // Taille
  t_bool ** m; // Contenu (tableau à 2 dimensions)
} t_graph_mat;


//////// Graphes ////////
t_graph_mat * graph_new(int size);
t_graph_list graph_list_new(int size);
void graph_add_edge(t_graph_mat * g, t_vertex u, t_vertex v);
t_graph_mat * graph_inverse(t_graph_mat * g);
t_graph_list * graph_inverse_list(t_graph_list *g);
void graph_free(t_graph_mat * g);
void graph_list_free(t_graph_list * g);


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



//////// main ////////
// int main() {
//   printf("Hello world!\n");
  
//   return 0;
// }


//////// Graphes ////////

//////// Liste d'adjacences ////////

// Créer un graphe sous forme de liste d'adjacences
// Utilisation : t_graph_list graphe = creer_graphe_liste(); 
t_graph_list creer_graphe_liste() {
  t_list l = list_new();
  t_graph_list graphe = {0,l};

  return graphe;
}

// Rajouter un sommet à un graphe représenté par une liste d'adjacence
// Utilisation : ajouter_sommet_liste(t_graph_list * graphe, t_list connection); // Avec connection représentant toutes les connections du sommet rajouté
void ajouter_sommet_liste(t_graph_list * graphe, t_list connection) {

}

//////// Matrices d'adjacences ////////

// Crée une nouvelle matrice vide
t_graph_mat * graph_new(int size){
	t_graph_mat * g = malloc(sizeof(*g));
	assert(g != NULL);
  g->size = size;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      g -> m[i][j] = 0;
  return g;

}

// Ajoute une arrête entre deux sommets
void graph_add_edge(t_graph_mat * g, t_vertex u, t_vertex v){
  assert(u>=0 && u< g->size);
  assert(v>=0 && v< g->size);
  g->m[u][v] = 1;
}

// Calcule le graphe inverse
t_graph_mat * graph_inverse(t_graph_mat * g){
  t_graph_mat * g_inv = graph_new(g->size);
  for (int i = 0; i< g->size; i++)
    for (int j = 0; j < g->size; j++)
      if (g->m[i][j]) g_inv -> m[j][i] = 1;

  return g_inv;
}

t_graph_list * graph_inverse_list(t_graph_list * g)
{
  t_graph_list * g_inv = malloc(sizeof(t_graph_list));
  assert(g_inv != NULL);

  *g_inv = graph_list_new(g->size); // initialisation de *g_inv

  for (t_vertex u = 0; u < g->size; u++)
  {
    t_node *lc = list_cursor_new(g->l[u]);
    while (!list_cursor_at_end(lc))
    {
      t_vertex v = list_cursor_get_val(lc);
      g_inv->l[v] = list_add_head(u, g_inv->l[v]); // on inverse le sens entre u et v
      lc = list_cursor_next(lc);
    }
  }

  return g_inv;
}


void graph_free(t_graph_mat * g){
  free(g);
}

t_graph_list graph_list_new(int size) {
  t_graph_list g;

  g.size = size;
  g.l = malloc(size * sizeof(t_list));
  assert(g.l != NULL);

  for (int i = 0; i < size; i++)
    g.l[i] = list_new();   // empty adjacency list

  return g;
}

void graph_list_free(t_graph_list * g) {
  for (int i = 0; i < g->size; i++)
    g->l[i] = list_free(g->l[i]);

  free(g->l);
  g->l = NULL;
  g->size = 0;
}


//////// Piles ////////

// Crée une nouvelle pile vide
// Utilisation : t_stack * ps = stack_new();
t_stack * stack_new() {
  t_stack * ps = malloc(sizeof(*ps));
  assert(ps != NULL);
  *ps = list_new();
  return ps;
}

// Affiche tout le contenu d'une pile (pour le débogage seulement)
void stack_show(t_stack * ps) {
  list_show(*ps);
}

// Retourne 1 si la pile *ps est vide, 0 sinon
int stack_is_empty(t_stack * ps) {
  return list_is_empty(*ps);
}

// Empile la valeur e en haut de la pile *ps
void stack_push(t_vertex e, t_stack * ps) {
  *ps = list_add_head(e, *ps);
}

// Dépile et retourne la valeur en haut de la pile *ps
t_vertex stack_pop(t_stack * ps) {
  t_vertex res = stack_top(ps);
  *ps = list_remove_head(*ps);
  return res;
}

// Retourne la valeur en haut de la pile *ps sans la dépiler
t_vertex stack_top(t_stack * ps) {
  assert(!list_is_empty(*ps));
  return list_get_first_val(*ps);
}



//////// Listes chaînées ////////

// Crée une nouvelle liste chaînée
// Utilisation : t_list l = list_new();
t_list list_new() {
  return NULL;
}

// Ajoute un maillon avec la valeur e au début de la liste l
t_list list_add_head(t_vertex e, t_list l) {
  t_node * n = malloc(sizeof(t_node));
  assert(n != NULL);
  n->val = e;
  n->p_next = l;
  return n;
}

// Retourne 1 si la liste l est vide, 0 sinon
int list_is_empty(t_list l) {
  return l == NULL;
}

// Affiche la liste l
void list_show(t_list l) {
  t_node * n = l;
  int i = 0;
  while (n != NULL) {
    printf("Maillon %d, valeur = %d\n", i++, n->val);
    n = n->p_next;
  }
}

// Retourne la valeur du premier maillon de la liste l
t_vertex list_get_first_val(t_list l) {
  assert(l != NULL);
  return l->val;
}

// Retire le premier maillon de la liste l et retourne la nouvelle tête
// Utilisation : l = list_remove_head(l);
t_list list_remove_head(t_list l) {
  t_list l2;
  assert(l != NULL);
  l2 = l->p_next;
  free(l);
  return l2;
}

// Libère la liste l de la mémoire (maillon par maillon)
// Utilisation : l = list_free(l);
t_list list_free(t_list l) {
  t_node * n = l, * nNext;
  while (n != NULL) {
    nNext = n->p_next;
    free(n);
    n = nNext;
  }
  return NULL;
}

// Retourne un curseur de liste pour parcourir l
// Utilisation : t_node * lc = list_cursor_new(l);
// Remarque : en fait, un curseur est aussi une liste chaînée !
t_node * list_cursor_new(t_list l) {
  return l;
}

// Retourne 1 si la fin de la liste a été atteinte
// Remarque : la fin d'une liste (NULL) est la même chose qu'une liste vide !
int list_cursor_at_end(t_node * lc) {
  return list_is_empty(lc);
}

// Retourne la valeur du maillon actuellement pointé par lc
// Remarque : ça revient en fait à prendre la valeur du premier maillon de lc !
int list_cursor_get_val(t_node * lc) {
  return list_get_first_val(lc);
}

// Avance le curseur vers le maillon suivant
// Utilisation : lc = list_cursor_next(lc);
t_node * list_cursor_next(t_node * lc) {
  assert(lc != NULL);
  return lc->p_next;
}

