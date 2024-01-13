#pragma once
#include<iostream>

class Rationel
{
    friend std::ostream& operator<<(std::ostream& os,const Rationel& r);
    friend Rationel operator+ (const Rationel&r1,const Rationel&r2);

private:
    int p;
    int q;
public:
    Rationel(int p,int q);
    //Rationel(int p,int q);
};

inline Rationel::Rationel(int p,int q):p(p),q(q){}
inline std::ostream& operator<<(std::ostream& os,const Rationel& r){
    os<<r.p<<"/"<<r.q;
    return(os);
}
inline Rationel operator+ (const Rationel&r1,const Rationel&r2){
    return(Rationel(((r1.p*r2.q)+(r2.p*r1.q)),(r1.q*r2.q)));
}
