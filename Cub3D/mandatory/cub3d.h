/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:50:08 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/06/04 05:39:53 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define RST "\e[0m"

#ifndef SIZE
 #define SIZE 64
#endif

#define TEST 1

typedef	struct s_player
{
	int	n_pl;
	int	posy;
	int	posx;
}	t_player;

typedef struct s_image
{
	mlx_image_t	*player;
}	t_image;

typedef struct s_map
{
	mlx_t		*mlx;
	t_player	*player;
	char		**map;
	char		*route;
	int			fd;
	size_t		w;
	int			h;
	t_image		image;
}	t_map;


	//validations
int	validargs(int argc, char **argv, t_map *map);
int	validmap(t_map *map);

	//utils
int	ft_error(char *str);
int	savelines(t_map *map);
int	savepoint(t_player *point, int y, int x);
int	createimage(t_map *map);
int imagetomap(t_map *map);
