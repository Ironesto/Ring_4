#include "cub3d.h"

int	createimage(t_map *map)
{
	map->image.player = mlx_new_image(map->mlx, SIZE, SIZE);
	//map->image.wall = mlx_new_image(map->mlx, SIZE, SIZE);
	map->image.aux = mlx_new_image(map->mlx, map->w * SIZE, map->h* SIZE);
	mlx_image_to_window(map->mlx, map->image.aux, 0, 0);
	map->image.back = mlx_new_image(map->mlx, map->w * SIZE, map->h* SIZE);
	mlx_image_to_window(map->mlx, map->image.back, 0, 0);
	size_t y = 0;
	size_t x;
/* 	while (y <= (map->h * SIZE) / 2)
	{
		x = -1;
		while (++x < map->w * SIZE)
			mlx_put_pixel(map->image.back, x, y, 0x6cffeb);
		y++;
	} */
	while (y > (map->h * SIZE) / 2 && y < map->h *SIZE)
	{
		x = -1;
		while (++x < map->w * SIZE)
			mlx_put_pixel(map->image.back, x, y, 0x13DA1F);
		y++;
	}
	return (0);
}

void	drawcube(t_map *data, int by, int bx)
{
	int y = by * SIZE;
	int x = bx * SIZE;
	int aux = x;
	int	aux2 = y;
	while (aux < x + SIZE)
	{
		mlx_put_pixel(data->image.back, aux, aux2, 0xa413da);
		mlx_put_pixel(data->image.back, aux, aux2 + SIZE, 0xa413da);
		aux++;
	}
	aux2 = x;
	aux = y;
	while (aux < y + SIZE)
	{
		mlx_put_pixel(data->image.back, aux2, aux, 0xa413da);
		mlx_put_pixel(data->image.back, aux2 + SIZE, aux, 0xa413da);
		aux++;
	}
	aux2 = x;
	aux = y;
	while (aux < y + SIZE)
	{
		mlx_put_pixel(data->image.back, aux2, aux, 0x6cffeb);
		aux++;
		aux2++;
	}
	aux2 = x;
	aux = y + SIZE;
	while (aux > y)
	{
		mlx_put_pixel(data->image.back, aux2, aux, 0x6cffeb);
		aux--;
		aux2++;
	}
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
			if (map->map[k][i] == '1')
				drawcube(map, k, i);
			i++;
		}
		k++;
	}
	mlx_image_to_window(map->mlx, map->image.player, map->player->posx * SIZE, map->player->posy * SIZE);
	return (0);
}
