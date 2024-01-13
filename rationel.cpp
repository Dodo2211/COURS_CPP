#include"Rationel.hpp"

int main()
{
    Rationel r(1,2);
    Rationel r1(3,4);
    Rationel r3=r1+r;
    std::cout<<r<<std::endl;
    std::cout<<r1<<std::endl;
    std::cout<<r3<<std::endl;
    
    return 0 ;
}