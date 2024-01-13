#include "template.hpp"
#include <iostream>

int main(){
    Stack <char> s(5);
    Stack <int> s1(7);
    // s1=s; //impossible car explicite 
    s.push('u');
    s.push('2');
    s.push('g');
    // s.push(2);
    // s.push(6);
    // s.push(9);
    s.top();
    std::cout<<s.nb<<std::endl;
    std::cout << "Valeur retirée de la pile : ";
    std::cout << s.pop() << "\n\n";

    // std::cout << "Valeur retirée de la pile : ";
    // std::cout << s.pop() << "\n\n";

    s.print();
    return 0;
}