#include "Point.hpp"

Point::Point()
{
    _x = 0;
    _y = 0;
    //std::cout<<"Point constructor called"<<std::endl;
}

Point::Point(float x, float y)
{
    _x = x;
    _y = y;
    //std::cout<<"Point constructor called"<<std::endl;
}

Point::~Point()
{
    //std::cout<<"Point destructor called"<<std::endl;
}

Point::Point(const Point &src)
{
    *this = src;
}

Point &Point::operator=(const Point &src)
{
    _x = src.getX();
    _y = src.getY();
    return *this;
}

Fixed   Point::getX() const { return this->_x; }
void    Point::setx(Fixed x) { this->_x = x; }

Fixed   Point::getY() const { return this->_y; }
void    Point::sety(Fixed y) { this->_y = y; }
