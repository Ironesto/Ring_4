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


	x = (px) / SIZE;
	auxy = py;
	y = (py - 1) / SIZE;
	while (auxy > y * SIZE)
	{
		//mlx_put_pixel(data->image.aux, px, auxy, 0xFFFFFFFF);
		auxy--;
	}
	float dy = fabs(py - auxy);
	float dx = catady(dy, ang);
	end.x = dx + px;
	end.y = py - dy;
	if (end.x <= 0)
	{
		end.x = 0;
		end.y = data->player->ppoint.y + catopo(data->player->ppoint.x, ang);
		return (end);
	}
	if (x >= data->w - 1)
	{
		end.x = data->w * SIZE - SIZE;
		end.y = data->player->ppoint.y - catopo(end.x - data->player->ppoint.x, ang);
		return (end);
	}
	x = (end.x) / SIZE;
	y = (end.y) / SIZE;
	if (data->map[y - 1][x] != '1')
		return (dist_ver(data, end.y , end.x, ang));
	//printf("endy %f endx %f hipo %f ang %d\n", end.y, end.x,
	//		hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang);
	//printf("pposx %f pposy %f\n",data->player->ppoint.x, data->player->ppoint.y);
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
	//printf("%d\n", auxx);
	float dx = fabs(px - auxx);
	float dy = catopo(dx, ang);
	end.x = dx + px;
	end.y = py - dy;
	if (ang == 90)
	{
		end.y = 0;
		end.x = data->player->ppoint.x;
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

	y = end.y / SIZE;		//+1 para corregir rayos
	if (data->map[y][x + 1] != '1')
		return (dist_hor(data, end.y , end.x, ang));
		//printf("%sendy %f endx %f hipo %f ang %d%s\n", RED, end.y, end.x,
		//	hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang, RST);
	return (end);

}

t_point	dist_hor_left(t_map *data, float py, float px, int ang)
{

	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = (px - 1) / SIZE;
	auxx = px;
	y = (py) / SIZE;
	while (auxx > x * SIZE)
	{
		//mlx_put_pixel(data->image.aux, auxx, py, 0xFF0000FF);
		auxx--;
	}
	float dx = fabs(px - auxx);
	float dy = catopo(dx, ang);
	end.x = px - dx;
	end.y = py + dy;
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
	x = (end.x) / SIZE;
	y = (end.y) / SIZE;
	if (data->map[y][x - 1] != '1')
		return (dist_hor_left(data, end.y, end.x, ang));
	return (end);

}

t_point	prueba(t_map *data, float py, float px, int ang)
{

	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	int auxy = py;
	while (auxx < (x * SIZE) + SIZE)
	{
		mlx_put_pixel(data->image.aux, auxx, auxy, CRED);
		auxx++;
	}
	//printf("%d\n", auxx);
	float dx = fabs(px - auxx);
	float dy = catopo(dx, ang);
	end.x = dx + px;
	end.y = py - dy;
	if (ang == 90)
	{
		end.y = 0;
		end.x = data->player->ppoint.x;
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
	y = (end.y) / SIZE;		//+1 para corregir rayos
	if (data->map[y][x] == '1')
	{
		puts("entra");
		end.y = y * SIZE + SIZE;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y - end.y , ang);
		return(end);
	}
	if (data->map[y][x + 1] != '1')
		return (prueba(data, end.y , end.x, ang));
		//printf("%sendy %f endx %f hipo %f ang %d%s\n", RED, end.y, end.x,
		//	hipo(data->player->ppoint.y - end.y, end.x - data->player->ppoint.x), ang, RST);
	return (end);

}
