#include "cub3d.h"

int	createimage(t_map *map)
{
	map->image.player = mlx_new_image(map->mlx, SIZE, SIZE);
	//map->image.wall = mlx_new_image(map->mlx, SIZE, SIZE);
	map->image.back = mlx_new_image(map->mlx, SCRNW, SCRNH);
	mlx_image_to_window(map->mlx, map->image.back, 0, 0);
	map->image.aux = mlx_new_image(map->mlx, SCRNW, SCRNH);
	mlx_image_to_window(map->mlx, map->image.aux, 0, 0);
	size_t y = 0;
	size_t x;
	while (y <= (SCRNH) / 2)
	{
		x = -1;
		while (++x < SCRNW)
			mlx_put_pixel(map->image.back, x, y, 0x6cffebFF);
		y++;
	}
	while (y > (SCRNH) / 2 && y < SCRNH)
	{
		x = -1;
		while (++x < SCRNW)
			mlx_put_pixel(map->image.back, x, y, 0x13DA1FFF);
		y++;
	}
	return (0);
}

void	drawcube(t_map *data, int by, int bx)
{
	int	y;
	if ( by == 0)
		y = 0;
	else
		y = (by * SIZE) - 1;
	int x;
	if (bx == 0)
		x = 0;
	else
		x = (bx * SIZE) - 1;
	int aux = x;
	int	aux2 = y;
	while (aux < x + SIZE)
	{
		mlx_put_pixel(data->image.back, aux, y, CGRN);
		if (y == 0)
			mlx_put_pixel(data->image.back, aux, SIZE - 1, CGRN);
		else
			mlx_put_pixel(data->image.back, aux, y + SIZE, CGRN);
		aux++;
	}
	aux = y;
	while (aux < y + SIZE)
	{
		mlx_put_pixel(data->image.back, x, aux, CGRN);
		if (x == 0)
			mlx_put_pixel(data->image.back, SIZE - 1, aux, CGRN);
		else
			mlx_put_pixel(data->image.back, x + SIZE, aux, CGRN);
		aux++;
	}
	aux2 = x;
	aux = y;
}

int imagetomap(t_map *map)
{
	size_t	i;
	size_t	k;

	k = 0;
	while(k < map->h)
	{
		i = 0;
		while (i < map->w)
		{
/* 			if (map->map[k][i] == '1')
				drawcube(map, k, i); */
			i++;
		}
		k++;
	}
	mlx_image_to_window(map->mlx, map->image.player, map->player->posx * SIZE, map->player->posy * SIZE);
	return (0);
}
