#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
class Matrix
{
private:
    int n,p;
    
public:
    Matrix(int n1 , int p1 ,float valinit)
    {
        vector<vector<float>> m(n1, vector<float>(p1, NAN));
        n=n1;
        p=p1;
    }
    ~Matrix();
};

