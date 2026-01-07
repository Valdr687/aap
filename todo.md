# To Do - Liste complète des améliorations

## 📋 PROBLÈMES D'ARCHITECTURE (Priorité P2)

### Structure du projet

- [ ] **Pas de fichiers headers** (.h) - créer des headers séparés
- [ ] **Inclusion de .c dans .c** (ligne 4-5 de lecture_ecriture.c) - très mauvaise pratique
- [~] **Duplications de code** entre `list_lecture()` et `mat_lecture()` - PARTIELLEMENT RÉSOLU (fonction `caracteristiques_graphe()` créée, mais il reste encore beaucoup de duplication dans la boucle de lecture)
- [ ] Créer un Makefile pour la compilation

### Logique et code mort

- [ ] **exo1.c (lignes 77-79)**: Sections commentées jamais implémentées - supprimer ou implémenter
- [ ] **exo_3_listes.c (lignes 15-28)**: Fonction `main()` commentée - nettoyer
- [ ] **Fonction `division()`**: suppose toujours qu'il y a un séparateur - ajouter validation

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
- [ ] Remplacer `t_bool` par `<stdbool.h>` standard C99
- [ ] Utiliser `const` pour les paramètres non modifiés
- [ ] Utiliser des constantes pour les nombres magiques (100, -1, etc.)

## 🚀 OPTIMISATIONS (Priorité P3)

### Performance

- [ ] Recherche linéaire dans `rang_par_valeur()` - utiliser table de hachage
- [ ] Allocations multiples dans les boucles - optimiser
- [ ] Meilleure gestion d'erreurs avec codes de retour cohérents

### Tests

- [ ] Ajouter des tests unitaires
- [ ] Séparer les tests des fichiers principaux
- [ ] Tester avec différents formats de fichiers d'entrée

## 📊 PRIORITÉS RECOMMANDÉES

3. **P2 - Moyen** : Architecture, sécurité, fonctionnalités manquantes
4. **P3 - Nice to have** : Documentation, modernisation, performance
