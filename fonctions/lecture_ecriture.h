#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

#include "base_fil_rouge.h"
#include "base.h"

// Fonctions de lecture de graphes
t_graph_list list_lecture(char *chemin, t_type *type, char ***sommets);
t_graph_list list_lecture_trmnl(t_type *type, char ***sommets);
void graph_list_ecriture_dot(t_graph_list *g, t_type type, char **sommets, char *chemin);
void graph_list_ecriture_dot_trml(t_graph_list *g, t_type type, char **sommets);

// Version matrice d'adjacences
t_graph_mat *mat_lecture(char *chemin, t_type *type, char ***sommets);
t_graph_mat *mat_lecture_trmnl(t_type *type, char ***sommets);
void graph_mat_ecriture_dot(t_graph_mat *g, t_type type, char **sommets, char *chemin);
void graph_mat_ecriture_dot_trml(t_graph_mat *g, t_type type, char **sommets);

#endif // LECTURE_ECRITURE_H
