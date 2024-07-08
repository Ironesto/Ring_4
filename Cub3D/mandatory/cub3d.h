/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:50:08 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/07/08 04:18:35 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define RST "\e[0m"

#define SRCNW	800
#define SRCNH	600
#define SRCNUP	150
#define FOW		60

#define SIZE	64
#define PI		3.14159265

#define ANG		20

#define CBLU 0x6cffeb
#define CGRN 0xa413da
#define CRED 0xFF0000FF
#define CWHI 0xFFFFFFFF
#define CCIA 0x3498dbff

#define TEST 1

typedef	struct	s_point
{
	float	x;
	float	y;
	float	h;
	char	dir;
}	t_point;

typedef	struct s_player
{
	int		n_pl;
	int		posy;
	int		posx;
	t_point	pp;
}	t_player;

typedef struct s_image
{
	mlx_image_t	*back;
	mlx_image_t	*aux;
	mlx_image_t	*player;
	mlx_image_t	*wall;
}	t_image;

typedef struct s_map
{
	mlx_t		*mlx;
	t_player	*player;
	char		**map;
	char		*route;
	int			fd;
	int			ang;
	size_t		w;
	size_t		h;
	t_image		image;
	//t_point		**ray;
}	t_map;


	//validations
int	validargs(int argc, char **argv, t_map *map);
int	validclose(t_map *map, size_t k, int i);
int	validlines(t_map *map);
int	validmap(t_map *map);

	//utils
int	ft_error(char *str);
int	savelines(t_map *map);
int	savepoint(t_map * data, int y, int x);
int	ft_fd(char *str);

	//create
int	createimage(t_map *map);
int	imagetomap(t_map *map);

	//moves
int	compmovy(int posx, int pos, int size, t_map *data);
int	compmovy2(int posx, int pos, int size, t_map *data);
int	compmovx2(int posy, int pos, int size, t_map *data);
int	compmovx(int posy, int pos, int size, t_map *data);

	//rays
void	draw(t_map *data, t_point end, t_point begin, int color);
void	deletepix(t_map *data);
void	drawang(t_map *data);

	//updown
t_point	if_updown(t_map *data, t_point end, int x, int ang);
t_point	dist_up(t_map *data, float py, float px, int ang);
t_point	dist_down(t_map *data, float py, float px, int ang);

	//leftright
t_point	if_leftright(t_map *data, t_point end, int ang);
t_point	dist_right(t_map *data, float py, float px, int ang);
t_point	dist_left(t_map *data, float py, float px, int ang);

	//trigo
float	rads(float x);
float	catopo(float ady, int ang);
float	catady(float opo, int ang);
float	hipo(float y, float x);
