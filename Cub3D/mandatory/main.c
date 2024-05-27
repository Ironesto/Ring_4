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
	close(map->fd);
}

int	main(int argc, char **argv)
{
	t_map map;
	if (ft_tester(argc, argv, &map) == 1)
		return (ft_free(&map), 1);
	ft_free(&map);
	return (0);
}
