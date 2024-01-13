#pragma once
#include "A.hpp"
#include "B.hpp"
class AB
{
    A a;
    B b;

public:
    AB(int i, int j) : a(i), b(j) {}
    void fAB();
};
