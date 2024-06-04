#include "cub3d.h"

int	ft_error(char *str)
{
	int	i = 0;
	while(str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	savelines(t_map *map)
{
	int	i;

	i = 1;
	map->fd = open(map->route, O_RDONLY);
	if (map->fd == -1)
	{
		return (1);
	}
	map->map[0] = ft_strdup(get_next_line(map->fd));
	if (ft_strlen(map->map[0]) > map->w)
			map->w = ft_strlen(map->map[0]);
	while(i < map->h)
	{
		map->map[i] = ft_strdup(get_next_line(map->fd));
		if (ft_strlen(map->map[i]) > map->w)
			map->w = ft_strlen(map->map[i]);
		i++;
	}
	if (ft_strlen(map->map[i - 1]) > map->w)
		map->w = ft_strlen(map->map[i - 1]);
	if (TEST)		//BORRAR
		ft_printf("%sTESTER:%slinea mas larga de %d\n", BLU, RST, map->w);
	map->map[i + 1] = NULL;
	return (0);
}

int	savepoint(t_player *point, int y, int x)
{
	point->n_pl++;
	point->posx = x;
	point->posy = y;
	return (0);
}
int	createimage(t_map *map)
{
	mlx_texture_t	*image;

	if (open("./assets/cartucho.png", O_RDONLY)  == -1)
		return (ft_error("ERROR: Cannot open the image\n"));
	else
		image = mlx_load_png("./assets/cartucho.png");
	puts("falla");
	map->image.player = mlx_texture_to_image(map->mlx, image);
	mlx_delete_texture(image);
	return (0);
}

int imagetomap(t_map *map)
{
	mlx_image_to_window(map->mlx, map->image.player, map->w * SIZE, map->h * SIZE);
	return (0);
}
