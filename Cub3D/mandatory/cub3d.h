/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:50:08 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/05/27 05:07:13 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

#define TEST 1

typedef struct s_map
{
	char	**map;
	char	*route;
	int		fd;
	int		h;
}	t_map;


	//validations
int	validargs(int argc, char **argv, t_map *map);
int	validmap(t_map *map);

	//utils
int	ft_error(char *str);
int	savelines(t_map *map);