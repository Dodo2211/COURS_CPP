#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<exception>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
class Matrix
{
private:
    int rows,columns;
    vector<float> buffer;
    int indice(int r,int c)const;
    
public:
    Matrix(const std::string &filename);
    Matrix(int n1 , int p1 ): rows(n1),columns(p1)
    {
        buffer.resize(n1*p1,INFINITY);
        
    }
    float at(int r,int c) const;
    void at (int r,int c, float v);
    void print(ostream&) const;
    std::vector<float> pluscourschemein(void);
    // virtual ~Matrix() = default;
};
inline Matrix::Matrix(const std::string &filename){
    // La première ligne du fichier filename contient le nombre de sommets.
    // Les autres lignes contiennent les transitions entre les sommets du graphe.
    // Une transition est un triplet: from to value
    //     où from est le sommet de départ (un entier)
    //        to est le sommet d'arrivée   (un entier)
    //        value est la valeur réelle de la transition entre from et to.

    // On ouvre le fichier en lecture.
    std::ifstream input_file(filename);

    // Si il y a eu un problème lors de l'ouverture du fichier:
    if (!input_file.is_open())
    {
        // là on affiche simplement un message et on sort de la fonction
        std::cout << "Cannot open file " << filename << std::endl;
        return; // on termine la fonction
    }

    // On va lire le fichier ligne par ligne en mettant chaque ligne dans une std::string.
    std::string line;

    // On lit la première ligne du fichier qui doit contenir le nombre de sommets du graphe.
    // Si il n'y a pas de lignes dans le fichier getline retourne false et on lance une exception.
    if (!getline(input_file, line))
    {
        std::cout << "File " << filename << " is empty" << std::endl;
        return; // on termine la fonction
    }
    // La std::string line contient un entier.
    // On va transformer la string en un entier (fonction std::stoi string to integer)
    // et mettre l'entier dans la variable nb_vertices
    int nb_vertices = 0;
    // là je considère que la traduction s'est bien passée
    nb_vertices = std::stoi(line);
    rows=nb_vertices;
    columns=nb_vertices;
    buffer.resize(rows*columns,INFINITY);

    // On lit toutes les lignes du fichier: quand il n'y en aura plus, getline retournera false.
    // On lit la ligne et on met son contenu dans la variable line.
    while (getline(input_file, line))
    {
        // Dans line, on sait qu'on a deux int et un double.
        // Pour extraire ces trois nombres, on initialise sur cette string, un objet de type istringstream.
        // Dans lequel on va pouvoir lire avec, l'opérateur >>, nos 3 nombres.
        std::istringstream iss(line);
        int from, to;
        double value;
        iss >> from >> to >> value;
        // On met la transition dans le graphe.
        buffer[indice(from,to)]=value;
        //std::cout << "transition " << from << " -(" << value << ")-> " << to << std::endl;
    }
}

inline std::vector<float> Matrix::pluscourschemein(void){
    auto A = buffer;
    for(int i=0;i<rows;i++){
        A[indice(i,i)]=0;
    }
    for(int k=0;k<rows;k++){
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(A[indice(i,j)]>(A[indice(i,k)]+A[indice(k,j)])){
                    A[indice(i,j)]=(A[indice(i,k)]+A[indice(k,j)]);
                }
            }
        }
    }
    return A;
}
inline float Matrix::at(int r, int c) const{
    return(buffer[indice(r,c)]);
}
inline void Matrix::at(int r,int c,float v){
    buffer[indice(r,c)]=v;
}
inline void Matrix::print(ostream& os) const {
    os<<"\t";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            os<<at(i,j)<<"\t";
        }
        os<<endl<<"\t";
    }
}
ostream& operator<< (ostream& os, const Matrix& m) {
    m.print(os);
    return os;

}
inline int Matrix::indice(int r,int c)const{
    return(r*rows+c);
}
