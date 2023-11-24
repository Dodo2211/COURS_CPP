#include <iostream>

struct Stack {
    int *tab;
    int size;
    int nb;
     ~Stack(){
        delete [] tab;
     }

    explicit Stack(int n) : nb(0), size(n),
        tab(new int[n]) {}
    
    Stack(const Stack& rs) = delete;
    void operator =(const Stack & rs)=delete;
    /* Ajout d'une valeur dans la pile */
    void push(int e) {
        if (nb == size) {
            std::cout << "Erreur ! La pile est pleine !" << "\n\n";
            exit(0);
        }
        else {
            tab[nb] = e;
            nb++;
        }
    }

    /* Suppression d'une valeur de la pile*/
    int pop() {
        int tmp;
        if (nb == 0) {
            std::cout << "Erreur ! La pile est vide !" << "\n\n";
            exit(0);
        }
        else {
            tmp = tab[nb-1];
            tab[nb] = 0;
            nb-=1;
            return tmp;
        }
    }

    /* Affichage de la pile */
    void print() {
        std::cout << "Affichage de la pile : " << std::endl;
        for (int i = nb-1; i >= 0; i--) {
            std::cout << tab[i] << std::endl;
        }
        std::cout << std::endl;
    }

    /* Verification de la plenitude de la pile */
    void is_full() {
        if (nb == size) {
            std::cout << "La pile est pleine" << "\n\n";
        }
        else {
            std::cout << "La pile n'est pas pleine" << "\n\n";
        }
    }

    /* Verification de la vacuite de la pile */
    void is_empty() {
        if (nb == 0) {
            std::cout << "La pile est vide" << "\n\n";
        }
        else {
            std::cout << "La pile n'est pas vide" << "\n\n";
        }
    }
    void top() {
        std::cout << "Affichage de la deriniere valeur de la pile : " << std::endl;
        std::cout << tab[nb-1] << std::endl;
        std::cout << std::endl;
    }

};