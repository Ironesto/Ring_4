#include "cub3d.h"

int	validargs(int argc, char **argv, t_map *map)
{
	if (argc != 2)
	{
		return (ft_error("ERROR: invalid number of arguments\n"));
	}
	map->route = ft_strjoin("./maps/", argv[1]);
	map->fd = open(map->route, O_RDONLY);
	if (map->fd == -1)
	{
		return (ft_error("ERROR: map not found\n"));
	}
	if (ft_strncmp(&map->route[ft_strlen(map->route) - 4], ".cub", 3) != 0)
	{
		return (ft_error("ERROR: invalid extension\n"));
	}
	return (0);
}

int	validclose(t_map *map, size_t k, int i)
{
	if (!ft_strchr("10NSWE",map->map[k][i - 1]) || !ft_strchr("10NSWE",map->map[k][i + 1]))	//BORRAR COMENTARIO comprueba delante y detras de cada 0 o jugador
		return (1);
	if (k == 0 || !ft_strchr("10NSWE",map->map[k - 1][i]) ||
		!ft_strchr("10NSWE",map->map[k - 1][i - 1]) || !ft_strchr("10NSWE",map->map[k - 1][i + 1]))
		return (1);
	if (k == map->h - 1 || !ft_strchr("10NSWE",map->map[k + 1][i]) ||
		!ft_strchr("10NSWE",map->map[k + 1][i - 1]) || !ft_strchr("10NSWE",map->map[k + 1][i + 1]))
		return (1);
	return (0);
}

int validlines(t_map *map)
{
	int		i;
	size_t	k;

	k = 0;
	while(k < map->h)
	{
		i = 0;
		while (ft_strchr("10NSWE \t", map->map[k][i]) && map->map[k][i])
		{
			if (ft_strchr("0NSWE",map->map[k][i]) && validclose(map, k, i) == 1)
				return (ft_error("ERROR: map not closed\n"));
			if (ft_strchr("NSWE",map->map[k][i]))
			{
				savepoint(map, k, i);
				if (map->player->n_pl != 1)
					return(ft_error("ERROR: number of players is not 1\n"));
			}
			i++;
		}
		if (!ft_strchr("10NSWE \t\n\0", map->map[k][i]))
			return (ft_error("ERROR: invalid character\n"));
		k++;
	}
	return (0);
}

int 	validmap(t_map *map)
{
	while (get_next_line(map->fd))	//leaks? guardar aqui al jugador en ese caso
		map->h++;
	if (TEST)												//BORRAR
		ft_printf("%sTESTER:%s numero de lineas del mapa: %d\n",BLU, RST, map->h);		//BORRAR
	if (map->h > 2)
		map->map = malloc(sizeof(char *) * (map->h + 1));	//poner a NULL el extra? y proteger malloc
	else
		return(ft_error("ERROR: invalid map\n"));
	if (close(map->fd) == -1)
		return (ft_error("ERROR: bad close\n"));
	if (savelines(map) == 1)
		return (ft_error("ERROR: open map failed\n"));
	if (validlines(map) == 1)
		return(ft_error("ERROR: bad lines\n"));
	if (map->player->n_pl != 1)
		return(ft_error("ERROR: number of players is not 1\n"));
	return (0);
}
