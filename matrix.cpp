#include "matrix.hpp"

int main(){
    Matrix m(4,4);
    m.at(0,1,1.2);
    m.at(0,2,17.6);
    m.at(1,2,3.4);
    m.at(2,3,7.3);
    m.at(3,1,9.8);
    m.pluscourschemein();

    
    m.print(cout);
    std::cout<<std::endl;
    Matrix m1("ex0.gr");
    m1.print(cout);
    std::cout<<std::endl;
    std::cout<<std::endl;
    m1.pluscourschemein();
    //m1.print(cout);
    std::cout<<m1;
    
}