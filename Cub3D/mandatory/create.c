#include "cub3d.h"

int	createimage(t_map *map)
{
	mlx_texture_t	*image;

	image = NULL;
	if (ft_fd("./assets/cartucho.png")  == -1)
		return (ft_error("ERROR: Cannot open the image\n"));
	else
		image = mlx_load_png("./assets/cartucho.png");
	map->image.player = mlx_texture_to_image(map->mlx, image);
	mlx_delete_texture(image);
	if (ft_fd("./assets/wall.png") == -1)
		return (ft_error("ERROR: Cannot open the image\n"));
	else
		image = mlx_load_png("./assets/wall.png");
	map->image.wall = mlx_texture_to_image(map->mlx, image);
	mlx_delete_texture(image);
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
