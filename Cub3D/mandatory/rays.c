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

t_point	dist_ver(t_map *data, float py, float px, int ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;


	x = px / SIZE;
	auxy = py;
	y = py / SIZE;
	while (auxy >= y * SIZE)
	{
		//mlx_put_pixel(data->image.aux, px, auxy, 0xFFFFFFFF);
		auxy--;
	}
	float dy = py - auxy;
	float dx = catady(dy, ang);
	end.x = dx + px;
	end.y = py - dy;
	if (ang <= 90)
		x = (end.x) / SIZE;
	else
		x = (end.x) / SIZE;
	if (end.x <= 0)
	{
		end.x = 0;
		end.y = data->player->ppoint.y + catopo(data->player->ppoint.x, ang);
		return (end);
	}
	if (x >= data->w - 1)
	{
		end.x = data->w * SIZE - SIZE + 1;
		end.y = data->player->ppoint.y - catopo(end.x - data->player->ppoint.x, ang);
		return (end);
	}
	if (data->map[y - 1][x] != '1' && x < data->w && y - 1 > 0)
		return (dist_ver(data, end.y, end.x, ang));		//no se por que es -1
	//printf("endy %2f endx %2f hipo %2f ang %d\n", data->player->ppoint.y - end.y, end.x - data->player->ppoint.x,
	//		hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang);
	return (end);
}

t_point	dist_hor(t_map *data, float py, float px, int ang)
{

	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	while (auxx < x * SIZE + SIZE)
	{
		//mlx_put_pixel(data->image.aux, auxx, py, 0xFF0000FF);
		auxx++;
	}
	float dx = fabs(px - auxx);
	float dy = catopo(dx, ang);
	end.x = dx + px;
	end.y = py - dy;
	y = (end.y + 1) / SIZE;		//+1 para corregir rayos
	if (ang == 90)
	{
		//puts("entra");
		end.y = 0;
		end.x = data->player->ppoint.x;
		//printf("endy %2f endx %2f hipo %2f ang %d\n", data->player->ppoint.y - end.y, end.x - data->player->ppoint.x,
		//	hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang);
		return (end);
	}
	if (end.y <= 0)
	{
		end.y = 0;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y, ang);
		return (end);
	}
	if (end.y > data->h * SIZE)
	{
		end.y = data->h * SIZE;
		end.x = data->player->ppoint.x - catady(end.y - data->player->ppoint.y, ang);
		//printf("endy %2f endx %2f hipo %2f ang %d\n", data->player->ppoint.y - end.y, end.x - data->player->ppoint.x,
		//	hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang);
		return(end);
	}
/* 	if (data->map[y][x] == '1')
	{
		end.y = y * SIZE + SIZE;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y - end.y, ang);
		return (end);
	} */
	if (data->map[y][x + 1] != '1' && x < data->w && end.y > 0)
		return (dist_hor(data, end.y, end.x, ang));

	return (end);

}

t_point	dist_hor_left(t_map *data, float py, float px, int ang)
{

	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	while (auxx >= x * SIZE)
	{
		//mlx_put_pixel(data->image.aux, auxx, py, 0xFF0000FF);
		auxx--;
	}
	float dx = fabs(px - auxx);
	float dy = catopo(dx, ang);
	end.x = px - dx;
	end.y = py + dy;
	y = (end.y) / SIZE;
	//printf("x %d y %d \n",x, y);
	if (end.y <= 0)
	{
		end.y = 0;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y, ang);
		return (end);
	}
	if (end.y > data->h * SIZE)
	{
		end.y = data->h * SIZE;
		end.x = data->player->ppoint.x - catady(end.y - data->player->ppoint.y, ang);
		//printf("endy %2f endx %2f hipo %2f ang %d\n", data->player->ppoint.y - end.y, end.x - data->player->ppoint.x,
		//	hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang);
		return(end);
	}
/*  	if (data->map[y][x] == '1')
	{
		end.y = y * SIZE + SIZE;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y - end.y, ang);
		return (end);
	} */
	if (data->map[y][x - 1] != '1')
		return (dist_hor_left(data, end.y, end.x, ang));

	return (end);

}
