/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:47:49 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/06/21 05:38:57 by gpaez-ga         ###   ########.fr       */
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
	map->player = malloc(sizeof(t_player));
	map->player->n_pl = 0;
	map->player->posx = -1;
	map->player->posy = -1;
}

float	rads(float x)
{
	float	res;

	res = x * (3.14159265 / 180);
	return (res);
}

float	catopo(int ady, int ang)
{
	float	res;

	res = ady * tan(rads(ang));
	return (res);
}

void	draw(t_map *data, t_point end, t_point begin, int color)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	pixel_x = begin.x;
	pixel_y = begin.y;
	while (pixels > 0)
	{
		mlx_put_pixel(data->image.aux, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}


void	del_hor(t_map *data, int py, int px, int ang)
{

	int	x;
	int	auxx;
	int	y;


	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	//printf("player y %d, player x %d \n", data->player->ppoint.y, data->player->ppoint.x);
	while (auxx < x * SIZE + SIZE)
	{
		mlx_put_pixel(data->image.aux, auxx, py, 0x00000000);
		auxx++;
	}
	//printf("py %d, px %d \n", py, px);
	mlx_put_pixel(data->image.aux, auxx, py, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py - 1, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py + 1, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py - 2, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py + 2, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py + 3, 0x00000000);
	mlx_put_pixel(data->image.aux, auxx, py - 3, 0x00000000);

	float dx = abs(data->player->ppoint.x - auxx);
	float opo = catopo(dx, ang);
	float dy = opo;
	//int h = sqrt((dx * dx) + (dy * dy));
	mlx_put_pixel(data->image.aux, auxx, py - opo, 0x00000000);
	t_point end;
	end.x = dx + data->player->ppoint.x;
	end.y = py - dy;
	draw(data, end, data->player->ppoint, 0x00000000);
	if (data->map[y][x + 1] != '1')
		del_hor(data, py, auxx, ang);

/* 	if (ang > -ANG)
		del_hor(data, py, px, ang - 1);
		*/
	}

int	dist_ver(t_map *data, int py, int px, int ang)
{
	int	x;
	int	auxy;
	int	y;


	x = px / SIZE;
	auxy = py;
	y = py / SIZE;
	//printf("player y %d, player x %d \n", data->player->ppoint.y, data->player->ppoint.x);
	//printf("auxy %d y * SIZE  %d\n", auxy, y * SIZE);
	while (auxy > y * SIZE)
	{
		mlx_put_pixel(data->image.aux, px, auxy, 0xFFFFFFFF);
		auxy--;
	}
	//printf("auxy %d\n", auxy);
	float dy = abs(py - auxy);
	float opo = catopo(dy, 90 - ang);
	float dx = opo;
	printf("dy %f, dx %f\n", dy, dx);
	//mlx_put_pixel(data->image.aux, px, py - opo, 0xa413da);
	t_point end;
	end.x = dx + px;
	end.y = py - dy;
	draw(data, end, data->player->ppoint, 0xFFFFFFFF);
	printf("endx %d endy %d\n",end.x, end.y);
	if (data->map[y - 1][x] != '1')
		dist_ver(data, end.y - 1, end.x, ang);
	int pixels;
	pixels = sqrt((dy * dy) + (dx * dx));
	return (pixels);
}

int	dist_hor(t_map *data, int py, int px, int ang)
{

	int	x;
	int	auxx;
	int	y;


	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	//printf("player y %d, player x %d \n", data->player->ppoint.y, data->player->ppoint.x);
	while (auxx < x * SIZE + SIZE)
	{
		mlx_put_pixel(data->image.aux, auxx, py, 0xFF0000FF);
		auxx++;
	}
	float dx = abs(px - auxx);
	float opo = catopo(dx, ang);
	float dy = opo;
	mlx_put_pixel(data->image.aux, auxx, py - opo, 0xa413da);
	t_point end;
	end.x = dx + px;
	end.y = py - dy;
	draw(data, end, data->player->ppoint, 0xFF0000FF);
	if (data->map[y][x + 1] != '1')
		dist_hor(data, end.y, auxx, ang);
/* 	if (ang > -ANG)
		dist_hor(data, py, px, ang - 1); */
	//printf("dy %f, dx %f\n", dy, dx);
	int pixels;
	pixels = sqrt((dy * dy) + (dx * dx));
	return (pixels);

}

/* void	dist_hor(t_map *data, int py, int px)
{

} */

void	hook(void *param)
{
	t_map	*data;
	int		x;
	int		y;

	data = param;
	x = data->image.player->instances[0].x;
	y = data->image.player->instances[0].y;
	data->player->ppoint.y = data->image.player->instances[0].y + SIZE / 2;
	data->player->ppoint.x = data->image.player->instances[0].x + SIZE / 2;
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
	dist_hor(data, data->image.player->instances[0].y + SIZE / 2, data->image.player->instances[0].x + SIZE / 2, ANG);
	dist_ver(data, data->image.player->instances[0].y + SIZE / 2, data->image.player->instances[0].x + SIZE / 2, ANG);
	//dist_hor(data, data->image.player->instances[0].y + SIZE / 2, data->image.player->instances[0].x + SIZE / 2, -ANG);
	//if (data->player->ppoint.x != data->image.player->instances[0].x + SIZE / 2 || data->player->ppoint.y != data->image.player->instances[0].y + SIZE / 2)
		//del_hor(data, data->player->ppoint.y, data->player->ppoint.x, ANG);
	
/* 	t_point end;
	end.x = 0;
	end.y = 0;
	draw(data, end, data->player->ppoint); */
	//putpixel(data);
	//deletepixel(data, y, x);



	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 + 1, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 + 2, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 + 3, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 - 3, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 - 2, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2 - 1, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2, data->image.player->instances[0].y + SIZE / 2 + 1, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2, data->image.player->instances[0].y + SIZE / 2 + 2, 0xa413da);
	mlx_put_pixel(data->image.aux, data->image.player->instances[0].x + SIZE / 2, data->image.player->instances[0].y + SIZE / 2 + 3, 0xa413da);
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


