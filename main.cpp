#include "stack.hpp"
#include <iostream>

int main() {
    Stack s(5);
    Stack s1(7);
    // s1=s; //impossible car explicite 
    s.push(17);
    s.push(21);
    s.push(39);
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
}