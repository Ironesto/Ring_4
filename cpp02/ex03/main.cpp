#include "Point.hpp"

int main()
{
    Point a;
    Point b(0, 15);
    Point c(15, 7.5f);
    Point p(4.05f, 15);

    if (bsp(a, b, c, p))
        std::cout<< "Dentro" <<std::endl;
    else
        std::cout<< "Fuera" <<std::endl;
    return 0;
}