# Fil rouge aap

## Setup

*Prérequis*

- [Git](#git)

1. Cloner (installer) le repo

```sh
git clone https://github.com/Valdr687/aap
```

2. Installer Graphviz
Sous Ubuntu :

```sh
sudo apt install graphviz
```

Sous Fedora :

```sh
sudo dnf install graphviz
```

## Tests de performance

```sh
make

## Conversion
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/noms/PC-biogrid.txt -o temp.dot
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/noms/PC-biogrid.txt -o temp.dot
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/noms/PC-biogrid.txt -o temp.dot

echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/noms/PC-biogrid.txt -o temp.dot
echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/noms/PC-biogrid.txt -o temp.dot
echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/noms/PC-biogrid.txt -o temp.dot

echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2
echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2
echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2

echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2
echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2
echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/noms/PC-biogrid.txt -start CCDC138 -goal ITGA2

echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/noms/PC-biogrid.txt
echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/noms/PC-biogrid.txt
echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/noms/PC-biogrid.txt

echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/noms/PC-biogrid.txt
echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/noms/PC-biogrid.txt
echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/noms/PC-biogrid.txt
```

```sh
make

## Conversion
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/numeros/ex2.txt -o temp.dot
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/numeros/ex2.txt -o temp.dot
echo "Essai 1 : lecture liste" && time ./exo1_list -i ./graphes/numeros/ex2.txt -o temp.dot

echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/numeros/ex2.txt -o temp.dot
echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/numeros/ex2.txt -o temp.dot
echo "Essai 1 : lecture matrice" && time ./exo1_mat -i ./graphes/numeros/ex2.txt -o temp.dot

echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/numeros/ex2.txt -start 0 -goal 10
echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/numeros/ex2.txt -start 0 -goal 10
echo "Essai 2 : recherche de chemin (listes)" && time ./exo2_listes -i ./graphes/numeros/ex2.txt -start 0 -goal 10

echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/numeros/ex2.txt -start 0 -goal 10
echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/numeros/ex2.txt -start 0 -goal 10
echo "Essai 2 : recherche de chemin (matrices)" && time ./exo2_matrices -i ./graphes/numeros/ex2.txt -start 0 -goal 10

echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/numeros/ex2.txt
echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/numeros/ex2.txt
echo "Essai 3 : composantes fortement connexes (listes)" && time ./exo3_listes -i ./graphes/numeros/ex2.txt

echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/numeros/ex2.txt
echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/numeros/ex2.txt
echo "Essai 3 : composantes fortement connexes (matrices)" && time ./exo3_matrices -i ./graphes/numeros/ex2.txt
```

## Commandes de référence

### Générer une image à partir d'un fichier .dot

```sh
dot fichier_entree.dot -T png -o fichier_sortie.png
```

## Git

*Extrait de la formation de Rézoléo*

### Installer Git

Ubuntu :

```sh
sudo apt install git
```

Mac :

Git est normalement installé sur les dernières versions de MacOS. Pour vérifier si il est déjà disponible :

```sh
git --version
```

Si git n'est pas reconnu, il faut donc l'installer :

```sh
brew install git
```

Si vous n'avez pas brew, vous pouvez l'installer avec cette commande :

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Configurer Git

```sh
git config --global user.name “Jean Valjean"
git config --global user.email 1066432423+JeanValjean@users.noreply.github.com
```

Pensez à utiliser votre mail de commit :

1. Ouvrez [Github](https://github.com/settings/emails)
2. Utilisez votre adresse dans **Keep my email addresses private**
