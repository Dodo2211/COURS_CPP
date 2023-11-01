// Exercice n°1 
//Écrire un programme qui demande à l'utilisateur de saisir deux dimensions longueur et largeur et affiche en retour l'air et le périmètre du rectangle.
/*$ ./a.out
Saisir la longueur (m) : 10.05
Saisir la largeur (m): 3.42
La surface est 34.371 m2
Le périmètre est 26.94 m
*/

#include<iostream>

int main(){
    float larg=0;
    float lon=0;
    std::cout<<"Saisir la longueur (m):";
    std::cin>>lon;
    if(std::cin.fail()){
        std::cout<<"La valeur saisie est incorrect"<<std::endl;
        return 1;
    }
    std::cout<<"Saisir la largeur (m):";
    std::cin>>larg;
    if(std::cin.fail()){
        std::cout<<"La valeur saisie est incorrect"<<std::endl;
        return 1;
    }
    std::cout<<"La surface est de :"<<lon*larg<<"m²"<<std::endl;
    std::cout<<"Le perimetre est de :"<<lon+lon+larg+larg<<"m"<<std::endl;

    return 0;
}

//OK 31/10/2023
