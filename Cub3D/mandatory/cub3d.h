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

typedef	struct s_player
{
	int	n_pl;
	int	posy;
	int	posx;
}	t_player;


typedef struct s_map
{
	t_player	*player;
	char		**map;
	char		*route;
	int			fd;
	int			h;
}	t_map;


	//validations
int	validargs(int argc, char **argv, t_map *map);
int	validmap(t_map *map);

	//utils
int	ft_error(char *str);
int	savelines(t_map *map);
int	savepoint(t_player *point, int y, int x);