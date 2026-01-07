#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

#include "base_fil_rouge.h"
#include "base.h"

// Fonctions de lecture de graphes
t_graph_list list_lecture(char *chemin, t_type *type, char ***sommets);
t_graph_mat *mat_lecture(char *chemin, t_type *type, char ***sommets);

#endif // LECTURE_ECRITURE_H
