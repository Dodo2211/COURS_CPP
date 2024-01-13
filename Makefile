# La commande make permet d'appliquer les règles définies dans le fichier Makefile.

# Les règles vont permettre de construire l'exécutable en ne recompilant que ce qui est nécessaire.
# Pour cela, on va utiliser la compilation séparée de ces fichiers i.e. produire des codes objets (les .o)

# On ne recompilera pas un fichier:
#   - si son code objet existe déjà
#   - et si les fichiers de header dont il dépend n'ont pas été modifiés
#   - et si le fichier source n'a pas été modifié

# Comment sait-on si un fichier a été modifié depuis la dernière compilation ?
#   - on compare les dates de modification des fichiers !
#   - si la date de modification du fichier source est plus récente que celle du fichier objet
#     alors on recompile le fichier source pour produire un nouveau fichier objet


# Les règles de ce fichier de Makefile, vont donc permettre:
#   - de produire les codes objets des fichiers
#   - de lier ensemble les codes objets pour faire l'exécutable
#   - de nettoyer le repertoire en supprimant les fichiers objets ou l'exécutable ou d'autres fichiers temporaires


# On commence par définir les compilateurs utilisés (afin de pouvoir facilement les modifier)
# -------------------------------------------------
CC = g++


# On définit les paramètres à passer au compilateur
# -------------------------------------------------
CCFLAGS = -Wall -std=c++11 -g 
# par exemple:
#    -Wall pour avoir tous les warnings
#    -std=c++11 pour utiliser le standard c++11
#    -g pour avoir les informations de debug ...
# et ceux à passer au linker (ici il n'y en a pas)
LDFLAGS = 

# On liste les fichiers sources (les .cpp) à compiler
# ---------------------------------------------------
SOURCES = A.cpp B.cpp AB.cpp main_AB.cpp

# On liste des fichiers objets correspondant aux fichiers de code
# (ceux qu'on linkera ensemble pour créer l'exécutable)
# (ici on fait un remplacement des suffixes .cpp par des .o)
OBJECTS = $(SOURCES:.cpp=.o)


# On définit les différentes règles à appliquer (pour construire l'exécutable mais pas que)
# ---------------------------------------------

# une règle est de la forme:

# cible: dépendances
#       commande

# la cible:
#   - c'est le nom du fichier à produire
# les dépendances:
#   - sont les fichiers dont dépend la cible
#   - ils doivent être produits avant de pouvoir produire la cible


# La première règle demande à produire l'exécutable (que nous appelons ici main_AB)
# il n'y a pas de commande
all: main_AB
# notons que c'est la première règle du fichier Makefile:
#   - c'est celle qui sera appliquée par défaut
#    i.e. si on ne précise pas de cible lors de l'appel de make `$ make` 


# On définit ensuite les dépendances entre les fichiers objets et les fichiers de header
# --------------------------------------------------------------------------------------
# par exemple
# - le fichier A.o dépend de A.hpp et de A.cpp
# - le fichier B.o dépend de B.hpp et de B.cpp
# - le fichier AB.o dépend de AB.hpp et de AB.cpp et de A.hpp et de B.hpp
# - le fichier main_AB.o dépend de A.hpp et de B.hpp et de AB.hpp et de main_AB.cpp
A.o : A.hpp
B.o : B.hpp
AB.o :  A.hpp B.hpp AB.hpp
main_AB.o : A.hpp B.hpp AB.hpp
# ... difficile de ne pas faire d'erreur ou de ne pas en oublier ...
# et si c'est le cas, parfois la recompilation se fera mal et le code produit sera faux !!!
# d'où l'intérêt d'utiliser des systèmes de build plus évolués comme cmake


# Cette seconde règle demande à produire l'exécutable main_AB
# la commande:
#   - est de linker les fichiers objets ensemble
#     où $@ est le nom de la cible (ici main_AB)
#     où $^ est la liste des dépendances (ici les fichiers objets)
# les dépendances:
#   - est la liste des fichiers objets
#                on appelle cette règle en faisant `$ make main_AB`
main_AB: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# Cette règle permet de compiler un fichier .cpp en un fichier .o
#   - la cible est un fichier .o 
#   - la dépendance est un fichier .cpp
# la commande:
#   - est de compiler le fichier .cpp en un fichier .o
#     où $< est le nom de la première dépendance (ici le fichier .cpp)
#     où $@ est le nom de la cible (ici le fichier .o)
#
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# Cette règle permet de nettoyer le répertoire
# La cible est clean (on peut l'appeler avec `$ make clean`)
# Comme cette commande ne produit pas de fichier, on la déclare comme étant une cible phony
clean:
	rm -f $(OBJECTS) main_AB
phony: clean
