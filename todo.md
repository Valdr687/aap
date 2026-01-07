# To Do - Liste complète des améliorations

## 📋 PROBLÈMES D'ARCHITECTURE (Priorité P2)

### Structure du projet

- [ ] Créer un Makefile pour la compilation
  - [ ] Compiler
  - [ ] Affichage graphe numéro + txt
  - [ ] Exo 2 sur ces graphes
  - [ ] Exo 3 sur ces graphes
- [X] Créer des headers (.h) séparés (base.h, base_fil_rouge.h, lecture_ecriture.h) ✅ FAIT
- [X] Modifier les fichiers .c pour inclure les .h au lieu des .c ✅ FAIT

### Logique et code mort

- [ ] **exo1.c (lignes 77-79)**: Sections commentées jamais implémentées - supprimer ou implémenter
- [ ] **exo_3_listes.c (lignes 15-28)**: Fonction `main()` commentée - nettoyer

### Type enum `t_type` amélioré

- [ ] Le type n'est utilisé que pour le parsing, mais pas pour le stockage/affichage

## ✨ FONCTIONNALITÉS MANQUANTES (Priorité P2-P3)

### À implémenter

- [X] Lire arguments (fait)
- [ ] Convertir graphe en format .dot
- [ ] Générer image avec Graphviz
- [ ] Exécuter commande de génération image (O/n)
- [ ] Lecture depuis stdin (commenté dans exo1.c ligne 77)
- [ ] Validation du format des fichiers d'entrée
- [ ] Messages d'erreur plus descriptifs
- [ ] Écriture dans un fichier .dot (section TODO ligne 180)

## 📝 DOCUMENTATION ET QUALITÉ (Priorité P3)

### Documentation

- [ ] **TODO non résolus** dans le code (lignes 20, 44 de base.c)
- [ ] Ajouter documentation des fonctions (style Doxygen)
- [ ] Uniformiser commentaires (français OU anglais, pas les deux)
- [ ] Compléter le README avec exemples d'utilisation

### Nommage et style

- [ ] Nommage incohérent : mix français/anglais (fichier_à_lire, graph_list, etc.)
