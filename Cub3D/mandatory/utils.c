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
	size_t	i;

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

int	savepoint(t_map *data, int y, int x)
{
	data->player->n_pl++;
	data->player->posx = x;
	data->player->posy = y;
	data->player->ppoint.dir = data->map[y][x];
	if (data->player->ppoint.dir == 'N')
		data->ang = 90;
	if (data->player->ppoint.dir == 'S')
		data->ang = 270;
	if (data->player->ppoint.dir == 'E')
		data->ang = 0;
	if (data->player->ppoint.dir == 'W')
		data->ang = 180;
	return (0);
}

int	ft_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if(fd < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
