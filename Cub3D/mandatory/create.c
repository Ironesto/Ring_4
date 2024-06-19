#include "cub3d.h"

int	createimage(t_map *map)
{
	mlx_texture_t	*image;

	image = NULL;
	map->image.player = mlx_new_image(map->mlx, SIZE, SIZE);
	if (ft_fd("./assets/wall.png") == -1)
		return (ft_error("ERROR: Cannot open the image\n"));
	else
		image = mlx_load_png("./assets/wall.png");
	map->image.wall = mlx_texture_to_image(map->mlx, image);
	mlx_delete_texture(image);

	map->image.aux = mlx_new_image(map->mlx, map->w * SIZE, map->h* SIZE);
	mlx_image_to_window(map->mlx, map->image.aux, 0, 0);
	map->image.back = mlx_new_image(map->mlx, map->w * SIZE, map->h* SIZE);
	mlx_image_to_window(map->mlx, map->image.back, 0, 0);
	size_t y = 0;
	size_t x;
	while (y <= (map->h * SIZE) / 2)
	{
		x = -1;
		while (++x < map->w * SIZE)
			mlx_put_pixel(map->image.back, x, y, 0x6cffeb);
		y++;
	}
	while (y > (map->h * SIZE) / 2 && y < map->h *SIZE)
	{
		x = -1;
		while (++x < map->w * SIZE)
			mlx_put_pixel(map->image.back, x, y, 0x13DA1F);
		y++;
	}
	return (0);
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
				mlx_image_to_window(map->mlx, map->image.wall, i * SIZE, k * SIZE);
			i++;
		}
		k++;
	}
	mlx_image_to_window(map->mlx, map->image.player, map->player->posx * SIZE, map->player->posy * SIZE);
	return (0);
}
