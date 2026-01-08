# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

# Répertoires
FONCTIONS_DIR = fonctions

# Fichiers sources des fonctions
FONCTIONS_SRC = $(FONCTIONS_DIR)/base.c \
                $(FONCTIONS_DIR)/base_fil_rouge.c \
                $(FONCTIONS_DIR)/lecture_ecriture.c

# Fichiers objets des fonctions
FONCTIONS_OBJ = $(FONCTIONS_SRC:.c=.o)

# Headers
HEADERS = $(FONCTIONS_DIR)/base.h \
          $(FONCTIONS_DIR)/base_fil_rouge.h \
          $(FONCTIONS_DIR)/lecture_ecriture.h

# Exécutables
EXECUTABLES = exo1_list exo1_mat exo2_listes exo2_matrices exo3_listes exo3_matrices

# Règle par défaut
all: $(EXECUTABLES)

# Règles pour les exécutables
exo1_list: exo1_list.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

exo1_mat: exo1_mat.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

exo2_listes: exo2_listes.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

exo2_matrices: exo2_mat.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^
	
exo3_listes: exo3_listes.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

exo3_matrices: exo3_matrices.o $(FONCTIONS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Règles pour les fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Nettoyage
clean:
	rm -f $(FONCTIONS_OBJ) exo1_list.o exo1_mat.o exo2_listes.o exo2_mat.o exo3_listes.o exo3_matrices.o

fclean: clean
	rm -f $(EXECUTABLES)

# Recompilation complète
re: fclean all

# Règles non-fichiers
.PHONY: all clean fclean re
