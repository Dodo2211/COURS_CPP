#include <cmath>
#include <iostream>
class Shapp
{
protected:
    int x;
    int y;
    Shapp(int posx, int posy) : x(posx), y(posy){};
    ~Shapp() = default;

public:
    void move(int dx, int dy);
    virtual float area()=0;
};
inline void Shapp::move(int dx, int dy)
{
    x += dx;
    y += dy;
}
class Circle : public Shapp
{
private:
    int radius;

public:
    Circle(int posx, int posy, int rayon) : Shapp(posx, posy), radius(rayon){};
    ~Circle() = default;
    float area();
};

inline float Circle::area()
{
    return (M_PI * radius * radius);
}
class Rect : public Shapp
{
private:
    int w, l;

public:
    Rect(int posx, int posy, int w, int l) : Shapp(posx, posy), w(w), l(l){};
    ~Rect() = default;
    float area();
};

inline float Rect::area()
{
    return (w * l);
}

int main()
{
    Circle C1(10, 10, 5);
    C1.move(5, 5);
    std::cout << C1.area() << std::endl;
}
//pour liaison dinamique mots cles virtual
// #include <stdexept>
//trow std::range_error("...") ; exception  try{ } catch(int e){ }