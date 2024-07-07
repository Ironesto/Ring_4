#include "../cub3d.h"

void	draw(t_map *data, t_point end, t_point begin, int color)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	pixel_x = begin.x;
	pixel_y = begin.y;
	while (pixels > 0)
	{
		mlx_put_pixel(data->image.aux, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	deletepix(t_map *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < data->h * SIZE)
	{
		k = 0;
		while (k < data->w * SIZE)
		{
			mlx_put_pixel(data->image.aux, k, i, 0x00000000);
			k++;
		}
		i++;
	}
}

/* 
void	drawlines(t_map *data, t_point h, t_point v, int aux)
{
	//Probar aqui en vez de en la funcion para optimizar
	h.h = hipo(data->player->ppoint.y - h.y, data->player->ppoint.x - h.x);
	v.h = hipo(data->player->ppoint.y - v.y, data->player->ppoint.x - v.x);
	//
	printf("hor %f ver %f\n", h.h, v.h);
	if (v.h >= h.h && ((aux >= 0 && aux <= 90) || (aux > 270 && aux < 360)))
		draw(data, h, data->player->ppoint, CRED);
	else if (v.h >= h.h && (aux > 90 && aux <= 270))
		draw(data, h, data->player->ppoint, CCIA);
	if (v.h <= h.h && (aux >= 180 && aux < 360))
		draw(data, v, data->player->ppoint, CGRN);
	else if (v.h < h.h && (aux >= 0 && aux < 180))
		draw(data, v, data->player->ppoint, CWHI);
} */

int	create(t_map *data, t_point point)
{
	int	line;

	if (point.dir == 'U' || point.dir == 'D')
		line = (int)point.x % SIZE;
	else if (point.dir == 'L' || point.dir == 'R')
		line = (int)point.y % SIZE;
	else
		return (ft_error("ERROR: dir cannot be "), ft_error(&point.dir), ft_error("\n"));
	//printf("linea/columna es %d\n", line);
	return (0);
}

void	drawlines(t_map *data, t_point h, int aux)
{
	if (h.dir == 'U')
		draw(data, h, data->player->ppoint, CWHI);
	if (h.dir == 'D')
		draw(data, h, data->player->ppoint, CCIA);
	if (h.dir == 'R')
		draw(data, h, data->player->ppoint, CRED);
	if (h.dir == 'L')
		draw(data, h, data->player->ppoint, CGRN);
}

void	draw3d(t_map *data, t_point p)
{
	
	printf("x %f y %f h %f\n", p.x, p.y, p.h);
	printf("ang en rad %f\n",rads(FOW / 2));
	float	dist_adap = catady(SRCNW / 2, rads(FOW / 2));
	printf("distancia es %f\n", dist_adap);
	int	h_adap = (p.h / SRCNUP) * dist_adap;
	printf("altura es %d\n", h_adap);
}

void	choose_line(t_map *data, int px, int py, int aux)
{
	t_point v;
	t_point h;

	if ((aux >= 0 && aux <= 90) || (aux > 270 && aux < 360))
		h = dist_right(data, py, px, aux);
	if (aux > 90 && aux <= 270)
		h = dist_left(data, py, px, aux);
	if (aux >= 0 && aux < 180)			
		v = dist_up(data, py, px, aux);
	if (aux >= 180 && aux < 360)
		v = dist_down(data, py, px, aux);
	h.h = hipo(data->player->ppoint.y - h.y, data->player->ppoint.x - h.x);
	v.h = hipo(data->player->ppoint.y - v.y, data->player->ppoint.x - v.x);
	if (v.h < h.h)
		h = v;
	draw3d(data, h);
	//create(data, h);
	drawlines(data, h, aux);
}

void	drawang(t_map *data, int py, int px, int ang)
{
	int aux;
	int	count;

	aux = data->ang + (ANG / 2);
	count = data->ang + (ANG / 2);
	while (count > data->ang - (ANG / 2))
	{
		if (aux >= 360)
			aux = aux - 360;
		if (aux < 0)
			aux = 360 + aux;
		choose_line(data, px, py, aux);
		aux--;
		count--;
	}
}
