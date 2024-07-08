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

void	draw3d(t_map *data, t_point p, float aux)
{
	float	dist_adap = catady(SCRNH / 2, FOW / 2) - data->player->pp.y;
	int	alt_adap = (100 / p.h) * dist_adap;
	int corr_x = SCRNW / rads(ANG);
	t_point init;
	init.y = SCRNH / 2 + alt_adap / 2;
	init.x = aux;
	t_point end;
	end.y = SCRNH / 2 - alt_adap / 2;
	end.x =  aux;

	if (init.y >= SCRNH)
		init.y = SCRNH;
	if (init.y <= 0)
		init.y = 0;
	if (end.y <= 0)
		end.y = 0;
	if (end.y >= SCRNH)
		end.y = SCRNH;
/* 	int i = 0;
	int k = end.x + corr_x;
	while (end.x < k)
	{
		end.x = end.x + i;
		init.x = init.x + i; */
		if (p.dir == 'U')
			draw(data, end, init, CWHI);
		if (p.dir == 'D')
			draw(data, end, init, CCIA);
		if (p.dir == 'R')
			draw(data, end, init, CRED);
		if (p.dir == 'L')
			draw(data, end, init, CGRN);
/* 		i++;
	} */
}

void	choose_line(t_map *data, float ang, float aux)
{
	t_point v;
	t_point h;
	float		py = data->player->pp.y;
	float		px = data->player->pp.x;

	if ((ang >= 0 && ang <= (PI / 2)) || (ang > PI + (PI / 2) && ang < 2 * PI))
		h = dist_right(data, py, px, ang);
	if (ang > (PI / 2) && ang <= PI + (PI / 2))
		h = dist_left(data, py, px, ang);
	if (ang >= 0 && ang < PI)			
		v = dist_up(data, py, px, ang);
	if (ang >= PI && ang < 2 * PI)
		v = dist_down(data, py, px, ang);
/* 	if (v.x + 0.5 > (int)v.x)
		v.x = (int)v.x + 1;
	h.x = (int)h.x;
	h.y = (int)h.y;
	v.x = (int)v.x;
	v.y = (int)v.y; */
	h.h = hipo(data->player->pp.y - h.y, data->player->pp.x - h.x);
	v.h = hipo(data->player->pp.y - v.y, data->player->pp.x - v.x);
	if (h.h < v.h && (ang >= 0 && ang < PI) && (int)h.h == (int)v.h)
	{
		printf("left %f up %f ang %f\n", h.h, v.h, ang);
		printf("left x %f left y %f\n", h.x, h.y);
		printf("up x %f up y %f\n", v.x, v.y);
	}
	if (v.h < h.h)
		h = v;
	draw3d(data, h, aux);
	//create(data, h);
	drawlines(data, h);
}

void	drawang(t_map *data)
{
	float	ang;
	float	count;
	float	aux;

	aux = 0;
	ang = data->ang + (rads(ANG) / 2);
	count = data->ang + (rads(ANG) / 2);
	float totang =  0.0174533 / SIZE;
	while (aux < SCRNW)
	{
		if (ang >= 2 * PI)
			ang = ang - (2 * PI);
		if (ang < 0)
			ang = (2 * PI) + ang;
		choose_line(data, ang, aux);
		ang = ang - totang;
		count = count - totang;
		aux = aux + 1;
	}
}
