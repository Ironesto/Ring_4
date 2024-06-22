#include "cub3d.h"

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

t_point	dist_ver(t_map *data, int py, int px, int ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;


	x = px / SIZE;
	auxy = py;
	y = py / SIZE;
	while (auxy > y * SIZE)
	{
		//mlx_put_pixel(data->image.aux, px, auxy, 0xFFFFFFFF);
		auxy--;
	}
	float dy = py - auxy;
	float opo = catady(dy, ang);
	float dx = opo;
	//mlx_put_pixel(data->image.aux, px, py - opo, 0xa413da);
	end.x = dx + px;
	end.y = py - dy;
	//draw(data, end, data->player->ppoint, 0xFFFFFFFF);
	x = end.x / SIZE;
	if (data->map[y - 1][x] != '1' && x < data->w && y - 1 > 0)
		return (dist_ver(data, end.y - 1, end.x, ang));		//no se por que es -1
	return (end);
}

t_point	dist_ver_down(t_map *data, int py, int px, int ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;


	x = px / SIZE;
	auxy = py;
	y = py / SIZE;
	while (auxy < y * SIZE + SIZE)
	{
		//mlx_put_pixel(data->image.aux, px, auxy, 0xFFFFFFFF);
		auxy++;
	}
	//printf("px %d auxy %d\n", px, auxy);
	float dy = auxy - py;
	float opo = catady(dy, ang);
	float dx = opo;
	//mlx_put_pixel(data->image.aux, px, py - opo, 0xa413da);
	end.x = dx + px;
	end.y = py + dy;
	x = end.x / SIZE;
	//printf("x %d y %d\n", x, y);
	if (data->map[y + 1][x] != '1' && x + 1 < data->w && y + 1 < data->h)
		return (dist_ver_down(data, end.y + 1, end.x, ang));
	return (end);
}

t_point	dist_hor(t_map *data, int py, int px, int ang)
{

	int	x;
	int	auxx;
	int	y;
	t_point end;


	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	//printf("player y %d, player x %d \n", data->player->ppoint.y, data->player->ppoint.x);
	while (auxx < x * SIZE + SIZE)
	{
		//mlx_put_pixel(data->image.aux, auxx, py, 0xFF0000FF);
		auxx++;
	}
	float dx = abs(px - auxx);
	float opo = catopo(dx, ang);
	float dy = opo;
	//mlx_put_pixel(data->image.aux, auxx, py - opo, 0xa413da);
	end.x = dx + px;
	end.y = py - dy;
	y = end.y / SIZE;
	if (data->map[y][x + 1] != '1')
		return (dist_hor(data, end.y, end.x, ang));
	return (end);

}