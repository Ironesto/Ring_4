#include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;

    public:
        Point();
        Point(float x, float y);
        ~Point();
        Point(const Point &src);
        Point &operator=(const Point &src);

        Fixed getX() const;
        void setx(Fixed x);
        Fixed getY() const;
        void sety(Fixed y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);