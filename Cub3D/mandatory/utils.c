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
	while(i < map->h)
	{	
		map->map[i] = ft_strdup(get_next_line(map->fd));
		i++;
	}
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