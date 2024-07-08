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
	h.h = hipo(data->player->pp.y - h.y, data->player->pp.x - h.x);
	v.h = hipo(data->player->pp.y - v.y, data->player->pp.x - v.x);
	//
	printf("hor %f ver %f\n", h.h, v.h);
	if (v.h >= h.h && ((aux >= 0 && aux <= 90) || (aux > 270 && aux < 360)))
		draw(data, h, data->player->pp, CRED);
	else if (v.h >= h.h && (aux > 90 && aux <= 270))
		draw(data, h, data->player->pp, CCIA);
	if (v.h <= h.h && (aux >= 180 && aux < 360))
		draw(data, v, data->player->pp, CGRN);
	else if (v.h < h.h && (aux >= 0 && aux < 180))
		draw(data, v, data->player->pp, CWHI);
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

void	drawlines(t_map *data, t_point h)
{
	if (h.dir == 'U')
		draw(data, h, data->player->pp, CWHI);
	if (h.dir == 'D')
		draw(data, h, data->player->pp, CCIA);
	if (h.dir == 'R')
		draw(data, h, data->player->pp, CRED);
	if (h.dir == 'L')
		draw(data, h, data->player->pp, CGRN);
}

void	draw3d(t_map *data, t_point p, int aux)
{
	
	//printf("x %f y %f h %f\n", p.x, p.y, p.h);
	//printf("ang en rad %f\n",rads(FOW / 2));
	float	dist_adap = catady(SRCNH / 2, FOW / 2) - data->player->pp.y;
	//printf("distancia es %f\n", dist_adap);
	int	alt_adap = (SRCNUP / p.h) * dist_adap;
	int corr_x = SRCNW / ANG;
	t_point init;
	init.y = SRCNH / 2 + alt_adap / 2;
	init.x = corr_x * aux;
	t_point end;
	end.y = SRCNH / 2 - alt_adap / 2;
	end.x = corr_x * aux;

	if (init.y >= SRCNH)
		init.y = SRCNH;
	if (end.y <= 0)
		end.y = 0;

		if (p.dir == 'U')
			draw(data, end, init, CWHI);
		if (p.dir == 'D')
			draw(data, end, init, CCIA);
		if (p.dir == 'R')
			draw(data, end, init, CRED);
		if (p.dir == 'L')
			draw(data, end, init, CGRN);
}

void	choose_line(t_map *data, int ang, int aux)
{
	t_point v;
	t_point h;
	int		py = data->player->pp.y;
	int		px = data->player->pp.x;

	if ((ang >= 0 && ang <= 90) || (ang > 270 && ang < 360))
		h = dist_right(data, py, px, ang);
	if (ang > 90 && ang <= 270)
		h = dist_left(data, py, px, ang);
	if (ang >= 0 && ang < 180)			
		v = dist_up(data, py, px, ang);
	if (ang >= 180 && ang < 360)
		v = dist_down(data, py, px, ang);
	h.h = hipo(data->player->pp.y - h.y, data->player->pp.x - h.x);
	v.h = hipo(data->player->pp.y - v.y, data->player->pp.x - v.x);
	if (v.h < h.h)
		h = v;
	draw3d(data, h, aux);
	//create(data, h);
	drawlines(data, h);
}

void	drawang(t_map *data)
{
	int ang;
	int	count;
	int	aux;

	aux = 0;
	ang = data->ang + (ANG / 2);
	count = data->ang + (ANG / 2);
	while (count > data->ang - (ANG / 2))
	{
		if (ang >= 360)
			ang = ang - 360;
		if (ang < 0)
			ang = 360 + ang;
		choose_line(data, ang, aux);
		ang--;
		count--;
		aux++;
	}
}
