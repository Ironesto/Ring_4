/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:47:49 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/07/06 02:18:15 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_tester(int argc, char **argv, t_map *map)
{
	int i = 0;

	if (validargs(argc, argv, map) == 1 && TEST)
	{
		ft_printf("%sTESTER:%s arguments validation KO\n", BLU, RST);
		return (1);
	}
	else if (TEST)
		ft_printf("%sTESTER:%s arguments validation OK\n", BLU, RST);
	if (validmap(map) == 1 && TEST)
	{
		ft_printf("%sTESTER:%s map validation KO\n", BLU, RST);
		return (1);
	}
	else if (TEST)
		ft_printf("%sTESTER:%s map validation OK\n", BLU, RST);
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
		ft_printf("\n%sfreeing%s map\n", CYN, RST);			//BORRAR
			free(map->map);				//liberar todas las lineas y finalmente el puntero doble
	}
	if (map->route)
	{
		ft_printf("%sfreeing%s route\n", CYN, RST);		//BORRAR
		free(map->route);
	}
	if (map->player)
	{
		ft_printf("%sfreeing%s player\n", CYN, RST);	//BORRAR
		free (map->player);
	}
	close(map->fd);
}

void	ft_init(t_map *map)
{
	map->fd = 0;
	map->h = 0;
	map->w = 0;
	map->ang = ANG;
	map->player = malloc(sizeof(t_player));
	map->player->n_pl = 0;
	map->player->posx = -1;
	map->player->posy = -1;
}

void drawline(t_map *data, int ang)
{
	t_point	v;
	t_point	h;
	if (ang >= 360)
		ang -= 360;
	if (ang < 0)
		ang += 360;
/* 	if (ang >= 0 && ang < 180)
		v = dist_up(data, data->player->ppoint.y, data->player->ppoint.x, ang);
 	else */
		v = dist_down(data, data->player->ppoint.y, data->player->ppoint.x, ang);
 	draw(data, v, data->player->ppoint, CWHI);
 	//if (ang <= 90)
		h = dist_right(data, data->player->ppoint.y, data->player->ppoint.x, ang);
	//else 
	//	h = dist_left(data, data->player->ppoint.y, data->player->ppoint.x, ang);
	draw(data, h, data->player->ppoint, CRED);
	//printf("%spposx %f pposy %f%s\n",MAG, data->player->ppoint.x, data->player->ppoint.y, RST);
	//printf("y en v %f, x en v %f\n",v.y / SIZE, v.x / SIZE);
	//printf("%sy en h %f, x en h %f%s\n",RED, h.y / SIZE, h.x / SIZE, RST);
	printf("vx %f vy %f\n%shx %f hy %f%s	ang %d\n",v.x, v.y, RED, h.x, h.y, RST, ang);
}

void	hook(void *param)
{
	t_map	*data;
	int		x;
	int		y;

	data = param;
	x = data->image.player->instances[0].x;
	y = data->image.player->instances[0].y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && !compmovy(x, y, SIZE, data))
		data->image.player->instances[0].y -= 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) && !compmovy2(x, y, SIZE, data))
		data->image.player->instances[0].y += 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && !compmovx(y, x, SIZE, data))
		data->image.player->instances[0].x -= 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) && !compmovx2(y, x, SIZE, data))
		data->image.player->instances[0].x += 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->ang += 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->ang -= 2;
	deletepix(data);
	data->player->ppoint.y = data->image.player->instances[0].y + SIZE / 2;
	data->player->ppoint.x = data->image.player->instances[0].x + SIZE / 2;

	int i = 2;
	if (i == 1)
		drawline(data, data->ang);
	else
		drawang(data, data->player->ppoint.y, data->player->ppoint.x, data->ang);

	mlx_put_pixel(data->image.aux, data->player->ppoint.x + 1, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x + 2, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x + 3, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x - 3, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x - 2, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x - 1, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x, data->player->ppoint.y, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x, data->player->ppoint.y + 1, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x, data->player->ppoint.y + 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->player->ppoint.x, data->player->ppoint.y + 3, 0xa413da);
/* 	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->image.player->instances[0].z += 2; */
/* 	if (data->map[data->player->posy][data->player->posx] == 'C')
		erase_coll(data);
	if (data->player == 1 || data->player == 0)
		opendoor(data); */
}

int	main(int argc, char **argv)
{
	t_map map;
	ft_init(&map);
	if (ft_tester(argc, argv, &map) == 1)
		return (ft_free(&map), 1);
	map.mlx = mlx_init((map.w - 1) * SIZE, map.h * SIZE, argv[1], true);
	createimage(&map);
	imagetomap(&map);
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_free(&map);
	return (0);
}


