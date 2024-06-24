#include "cub3d.h"

float	rads(float x)
{
	float	res;

	res = x * (3.14159265 / 180);
	return (res);
}

float	catopo(int ady, int ang)
{
	float	res;

	res = ady * tan(rads(ang));
	return (res);
}

float	catady(int opo, int ang)
{
	float	res;

	res = opo / tan(rads(ang));
	return (res);
}

int	hipo(float y, float x)
{
	int	h;

	h = sqrt((y * y) + (x * x));
	return (h);
}
