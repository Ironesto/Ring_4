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

int validlines(t_map *map)
{
	int	i;

	i = 0;
	while(map->map[0][i] && map->map[0][i + 1])
	{
 		while (ft_strchr("1 \t", map->map[0][i]))
			i++;
		if (map->map[0][i] != '\0' && map->map[0][i] != '\n')
			return (1);
		if (map->map[0 - 1][i])	//podria ser el jugador tambien
			ft_printf("arriba\n");
		//if (map->map[0 + 1][i] != '1')	//podria ser el jugador tambien
		//	return (1);
		i++;
	}
	return (0);
}

int 	validmap(t_map *map)
{
	while (get_next_line(map->fd))
		map->h++;
	if (TEST)												//BORRAR
		ft_printf("numero de lineas del mapa: %d\n",map->h);		//BORRAR
	if (map->h > 2)
		map->map = malloc(sizeof(char *) * (map->h + 1));
	else
		return(ft_error("ERROR: invalid map\n"));
	if (close(map->fd) == -1)
		return (ft_error("ERROR: bad close\n"));
	savelines(map);
	if (validlines(map) == 1)
		return(ft_error("ERROR: bad lines\n"));
	return (0);
}
