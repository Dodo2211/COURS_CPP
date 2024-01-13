# Utilisation de la technique des makefiles pour compiler plusieurs fichiers pour former un exécutable

Les fichiers de code sont:  
`AB.cpp`  `AB.hpp`  `A.cpp`  `A.hpp`  `B.cpp`  `B.hpp`  `main_AB.cpp`

Le fichier `Makefile` définit les règles:
- pour créer un exécutable à partir des fichiers contenant le code
- pour re-créer un exécutable suite à la modification d'un fichier de code **sans recompiler** inutilement de fichiers
- en utilisant la compilation séparée (i.e. production des fichiers de code objet `.o` et construction de l'exécutable en linkant les `.o`).

Vous trouverez dans le `Makefile` les commentaires expliquant comme il s'écrit.

Pour l'utiliser faites les commandes suivantes:

```
$ make
```

qui fait:
```
g++ -std=c++11 -Wall -g -c A.cpp -o A.o
g++ -std=c++11 -Wall -g -c B.cpp -o B.o
g++ -std=c++11 -Wall -g -c AB.cpp -o AB.o
g++ -std=c++11 -Wall -g -c main_AB.cpp -o main_AB.o
g++ -std=c++11 -Wall -g A.o B.o AB.o main_AB.o -o main_AB
```

```
$ make clean
```
qui fait:
```
rm -f A.o B.o AB.o main_AB.o main_AB
```

```
$ make main_AB
```

```
$ make clean
```

```
make AB.o
```

```
make
```
qui ne recompile plus `AB.cpp`

modifiez le fichier `A.hpp` et recompilez tout

```
make 
```
