#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

#include "base_fil_rouge.h"
#include "base.h"

// Lecture des paramètres
int parametres_lecture_ecriture(int ArgumentCount, char **ArgumentList, char **entree, char **sortie);
int parametres_exo2(int ArgumentCount, char **ArgumentList, char **entree, char **start, char **goal);
int parametres_exo3(int ArgumentCount, char **ArgumentList, char **entree);
void erreur_option(char *option);
void erreur_option_exo2(char *option);
void erreur_option_exo3(char *option);
void erreur_arguments(int RealArgumentCount, int max_arguments);
int est_option_valide(char *option, char OptionsValides[][3]);
int est_option_valide_exo2(char *option, char OptionsValides[][7]);
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
