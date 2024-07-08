#include "cub3d.h"

float	rads(float x)
{
	float	res;

	res = x * (PI / 180);
	return (res);
}

float	catopo(float ady, float ang)
{
	float	res;

	res = ady * tan(ang);
	return (res);
}

float	catady(float opo, float ang)
{
	float	res;

	res = opo / tan(ang);
	return (res);
}

float	hipo(float y, float x)
{
	float	h;

	h = sqrt((y * y) + (x * x));
	return (h);
}
