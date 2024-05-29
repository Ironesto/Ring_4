/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:47:49 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/05/27 05:01:41 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_tester(int argc, char **argv, t_map *map)
{
	int i = 0;

	if (validargs(argc, argv, map) == 1 && TEST)
	{
		ft_printf("TESTER: arguments validation KO\n");
		return (1);
	}
	else if (TEST)
		ft_printf("TESTER: arguments validation OK\n");
	if (validmap(map) == 1 && TEST)
	{
		ft_printf("TESTER: map validation KO\n");
		return (1);
	}
	else if (TEST)
		ft_printf("TESTER: map validation OK\n");
	while (map->map[i] && TEST)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	return(0);
}

void ft_free(t_map *map)
{
	if (map->map)
	{
		ft_printf("freeing map\n");			//BORRAR
			free(map->map);				//liberar todas las lineas y finalmente el puntero doble
	}
	if (map->route)
	{
		ft_printf("freeing route\n");		//BORRAR
		free(map->route);
	}
	if (map->player)
	{
		ft_printf("freeing player\n");	//BORRAR
		free (map->player);
	}
	close(map->fd);
}

void	ft_init(t_map *map)
{
	map->fd = 0;
	map->h = 0;
	map->player = malloc(sizeof(t_player));
	map->player->n_pl = 0;
	map->player->posx = -1;
	map->player->posy = -1;
}

int	main(int argc, char **argv)
{
	t_map map;
	ft_init(&map);
	if (ft_tester(argc, argv, &map) == 1)
		return (ft_free(&map), 1);
	ft_free(&map);
	return (0);
}
