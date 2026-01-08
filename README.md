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
