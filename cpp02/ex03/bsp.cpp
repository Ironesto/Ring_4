#include "Point.hpp"

static Fixed abs(Fixed fixed)
{
    if (fixed < 0)
        fixed = fixed * -1;
    return (fixed);
}

static Fixed triangleArea(Point const a, Point const b, Point const c)
{
    Fixed area;
    area = ((a.getX() * (c.getY() - b.getY())) +
                (c.getX() * (b.getY() - a.getY())) +
                    (b.getX() * (a.getY() - c.getY())))/2;
    area = abs(area);
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = triangleArea(a, b, c);
    //std::cout << ">>>>>>> abc Area: " << abcArea.toFloat() << std::endl;
    Fixed abpArea = triangleArea(a, b, point);
    //std::cout << ">>>>>>> abp Area: " << abpArea.toFloat() << std::endl;
    Fixed apcArea = triangleArea(a, point, c);
    //std::cout << ">>>>>>> apc Area: " << apcArea.toFloat() << std::endl;
    Fixed pbcArea = triangleArea(point, b, c);
   // std::cout << ">>>>>>> pbc Area: " << pbcArea.toFloat() << std::endl;
    Fixed total = abpArea + apcArea + pbcArea;
    //std::cout << "areas de abp + apc + pbc = " << total << std::endl;
    if (abcArea == abpArea + apcArea + pbcArea
        && abcArea != 0 && abpArea != 0 && apcArea != 0 && pbcArea != 0)
        return (true);
    else
        return (false);
}