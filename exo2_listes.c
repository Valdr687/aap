// EXO 2 LISTES

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "./fonctions/lecture_ecriture.h"
#include "./fonctions/base.h"
#include "./fonctions/base_fil_rouge.h"

#define MAX_READ_LINE 100

// prototypes
void recherche_recur(t_graph_list g, t_vertex x, t_vertex y, char ***sommets, t_type *type);
t_bool recherche_recur_f(t_graph_list g, t_vertex x, t_vertex y, t_bool *marking, t_stack *stack);

//////// main ////////
int main(int ArgumentCount, char **ArgumentList)
{
  char *entree = NULL;
  char *start_str = NULL;
  char *goal_str = NULL;

  // Extraction des paramètres
  int erreur = parametres_exo2(ArgumentCount, ArgumentList, &entree, &start_str, &goal_str);
  if (erreur == -1)
  {
    return 0;
  }

  // Lecture du graphe
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

  // Détermination des sommets start et goal
  t_vertex start, goal;

  if (start_str == NULL || goal_str == NULL)
  {
    printf("Les arguments -start et -goal sont obligatoires.\n");
    return 0;
  }

  if (type == INT)
  {
    sscanf(start_str, "%d", &start);
    sscanf(goal_str, "%d", &goal);
  }
  else
  {
    start = rang_par_valeur(start_str, sommets, graphe.size);
    goal = rang_par_valeur(goal_str, sommets, graphe.size);
    if (start == -1 || goal == -1)
    {
      printf("Sommet non trouvé dans le graphe.\n");
      return 0;
    }
  }

  // Recherche du chemin
  recherche_recur(graphe, start, goal, &sommets, &type);
  printf("\n");

  // Libération de la mémoire
  if (type == STR)
  {
    sommets_free(sommets, graphe.size);
  }
  graph_list_free(&graphe);

  return 0;
}

//////// Graphes ////////

// Parcours récursif
// fonction principale non récursive
void recherche_recur(t_graph_list g, t_vertex x, t_vertex y, char ***sommets, t_type *type)
{
  // g graphe de n = g.size sommets, x sommet de départ, y sommet d'arrivée
  t_bool marking[g.size]; // tableau de booléens pour marquer les sommets, initialement toutes cellules marquées FAUX
  // Initialisation du tableau marking à 0 (FALSE)
  for (int i = 0; i < g.size; i++)
  {
    marking[i] = 0;
  }

  t_stack *pstack = stack_new(); // pile de sommets initialement vide

  recherche_recur_f(g, x, y, marking, pstack); // appel à fc° récursive

  // affichage du chemin trouvé (s'il y en a un)
  if (stack_is_empty(pstack))
  {
    if (*type == INT)
    {
      printf("Pas de chemin de %d à %d\n", x, y);
    }
    else
    {
      printf("Pas de chemin de %s à %s\n", (*sommets)[x], (*sommets)[y]);
    }
  }
  else
  {
    if (*type == STR)
    {
      printf("%s", (*sommets)[stack_pop(pstack)]);
      while (!stack_is_empty(pstack))
      {
        printf(" -> %s", (*sommets)[stack_pop(pstack)]);
      }
    }
    else
    {
      printf("%d", stack_pop(pstack));
      while (!stack_is_empty(pstack))
      {
        printf(" -> %d", stack_pop(pstack));
      }
    }
  }
}
// fonction auxiliaire récursive
t_bool recherche_recur_f(t_graph_list g, t_vertex x, t_vertex y, t_bool *marking, t_stack *pstack)
{
  // renvoie un booléen indiquant si le sommet cible a été trouvé

  t_vertex w;           // un sommet de g
  t_bool trouve;        // booléen qui vaut 1 si le sommet cible y a été trouvé, 0 sinon
  t_list *pliste = g.l; // tableau de listes chaînées (=description du graphe)
  t_list pl;            // à actualiser comme liste des successeurs d'un sommet
  t_node *lc;           // curseur de liste

  if (x == y)
  {
    stack_push(x, pstack); // on empile x sur la pile pstack
    return 1;              // on retourne VRAI
  }
  else
  {
    if (marking[x] == 0)
    {
      marking[x] = 1; // on marque le sommet x
      // parcours de la liste des successeurs de x :
      pl = pliste[x]; // on actualise pl comme liste des successeurs de x
      lc = list_cursor_new(pl);

      while (!list_cursor_at_end(lc))
      {              // parcours de la liste pl
        w = lc->val; // w : sommet successeur de x, valeur du maillon pointé par lc
        trouve = recherche_recur_f(g, w, y, marking, pstack);
        if (trouve == 1)
        {
          stack_push(x, pstack); // on empile x
          return 1;              // on retourne VRAI
        }
        lc = list_cursor_next(lc);
      }
    }
    return 0;
  }
}
