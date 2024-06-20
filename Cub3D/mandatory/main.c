/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:47:49 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/06/20 06:25:09 by gpaez-ga         ###   ########.fr       */
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

void	deletepixelx(t_map *data, int by, int bx)
{
	int px = bx + SIZE / 2;
	int py = by + SIZE / 2;
	int y = (by + SIZE / 2) / SIZE;
	int x = (bx + SIZE / 2) / SIZE;
	while (data->map[y][x] != '1')
		x--;
	if (py != data->image.player->instances[0].y + SIZE / 2)
	{
		while (px > x * SIZE && py)
		{
			mlx_put_pixel(data->image.aux, px, py, 0x00000000);
			px--;
		}
	}
}

void	deletepixeldiag(t_map *data, int by, int bx, int ang)
{
	int px = bx + SIZE / 2;
	int py = by + SIZE / 2;
	//int y = (by + SIZE / 2) / SIZE;
	//int x = (bx + SIZE / 2) / SIZE;
	int auxx = (px + cos(rads(ang))) / SIZE;
	int auxy = (py + cos(rads(ang))) / SIZE;
	while (data->map[auxy][auxx] != '1')
	{
		auxx = (px + cos(rads(ang))) / SIZE;
		auxy = (py + cos(rads(ang))) / SIZE;
		px--;
		py--;
	}
	//printf("x %d pxcos %d y %d pycos %d\n", x, auxx, y, auxy);
	px = bx + SIZE / 2;
	py = by + SIZE / 2;

	//printf("px %d (auxx * SIZE) + SIZE %d\n", px, (auxx * SIZE) + SIZE);
	if (px != data->image.player->instances[0].x + SIZE / 2 || py != data->image.player->instances[0].y + SIZE / 2)
	{
		while (px > (auxx * SIZE) + SIZE || py > (auxy * SIZE) + SIZE)
		{
			//puts("entra");
			mlx_put_pixel(data->image.aux, px + cos(rads(ang)), py + cos(rads(ang)), 0x00000000);
			py--;
			px--;
		}
	}
	if (ang > -ANG)
		deletepixeldiag(data, by, bx, ang - 1);
}

void	deletepixel(t_map *data, int by, int bx)
{
	int px = bx + SIZE / 2;
	int py = by + SIZE / 2;
	int y = (by + SIZE / 2) / SIZE;
	int x = (bx + SIZE / 2) / SIZE;
	while (data->map[y][x] != '1')
		y--;
	if (px != data->image.player->instances[0].x + SIZE / 2)
	{
		while (py > y * SIZE && px)
		{
			mlx_put_pixel(data->image.aux, px, py, 0x00000000);
			py--;
		}
	}
	deletepixelx(data, by, bx);
	deletepixeldiag(data, by, bx, ANG);
	if (px != data->image.player->instances[0].x + SIZE / 2 || py != data->image.player->instances[0].y + SIZE / 2)
	{
		mlx_put_pixel(data->image.aux, px + 1, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px + 2, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px + 3, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px - 3, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px - 2, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px - 1, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px, by + SIZE / 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px, by + SIZE / 2 + 1, 0x00000000);
		mlx_put_pixel(data->image.aux, px, by + SIZE / 2 + 2, 0x00000000);
		mlx_put_pixel(data->image.aux, px, by + SIZE / 2 + 3, 0x00000000);
	}

}

void	putpixelx(t_map *data)
{
	int px = data->image.player->instances[0].x + SIZE / 2;
	int py = data->image.player->instances[0].y + SIZE / 2;
	int y = (data->image.player->instances[0].y + SIZE / 2) / SIZE;
	int x = (data->image.player->instances[0].x + SIZE / 2) / SIZE;
	while (data->map[y][x] != '1')
		x--;
	while (px > (x * SIZE) + SIZE && py)
	{
		mlx_put_pixel(data->image.aux, px, py, 0xFF0000FF);
		px--;
	}
}

/* void	putpixeldiag(t_map *data, int ang)
{
	int px = data->image.player->instances[0].x + SIZE / 2;
	int py = data->image.player->instances[0].y + SIZE / 2;
	//int y = (data->image.player->instances[0].y + SIZE / 2) / SIZE;
	//int x = (data->image.player->instances[0].x + SIZE / 2) / SIZE;
	int auxx = (px + cos(rads(ang))) / SIZE;
	int auxy = (py + cos(rads(ang))) / SIZE;
	while (data->map[auxy][auxx] != '1')
	{
		auxx = (px + cos(rads(ang))) / SIZE;
		auxy = (py + cos(rads(ang))) / SIZE;
		px--;
		py--;
	}
	px = data->image.player->instances[0].x + SIZE / 2;
	py = data->image.player->instances[0].y + SIZE / 2;

	//printf("cos %f sin %f\n", cos(rads(ang)), sin(rads(ang)));
	while (px > (auxx * SIZE) + SIZE || py > (auxy * SIZE) + SIZE)
	{
		mlx_put_pixel(data->image.aux, px + cos(rads(ang)), py + cos(rads(ang)), 0xFFFFFFFF);
		py--;
		px--;
	}
	ft_printf("py %d px %d\n", py / SIZE, px / SIZE);
	if (ang > -ANG)
		putpixeldiag(data, ang - 1);

} */

float	hipo(float len, int ang)
{
	float res;

	res = len / cos(rads(ang));
	return (res);
}

void	putpixeldiag(t_map *data, int ang)
{
	float px = data->image.player->instances[0].x + SIZE / 2;
	float py = data->image.player->instances[0].y + SIZE / 2;
	//int y = (data->image.player->instances[0].y + SIZE / 2) / SIZE;
	//int x = (data->image.player->instances[0].x + SIZE / 2) / SIZE;
	int auxx = (px) / SIZE;
	int auxy = (py) / SIZE;
	while (data->map[auxy][auxx] != '1')		//ESTO ESTA MAL
	{
		auxx = (px) / SIZE;
		auxy = (py) / SIZE;
		px--;
		py--;
	}
	px = (data->image.player->instances[0].x + SIZE / 2);
	py =( data->image.player->instances[0].y + SIZE / 2);
	float h = hipo(px, ang);
	//printf("rads %f cos %f sin %f  tan %f\n",rads(ang), cos(rads(ang)), sin(rads(ang)), tan(rads(ang)));
	ft_printf("px %d (auxx * SIZE) + SIZE %d\n", px, (auxx * SIZE) + SIZE);
	ft_printf("hipo %d\n", h);
	while (px > (auxx * SIZE) + SIZE || py > (auxy * SIZE) + SIZE)
	{
		mlx_put_pixel(data->image.aux, px, py, 0xFFFFFFFF);
		py--;
		px--;
	}
	ft_printf("py %d px %d\n", py / SIZE, px / SIZE);	//px es muchisimo
/* 	if (ang > -ANG)
		putpixeldiag(data, ang - 1); */

}

/* void	putpixeldiag(t_map *data)
{
	int px = data->image.player->instances[0].x + SIZE / 2;
	int py = data->image.player->instances[0].y + SIZE / 2;
	int y = (data->image.player->instances[0].y + SIZE / 2) / SIZE;
	int x = (data->image.player->instances[0].x + SIZE / 2) / SIZE;
	while (data->map[(data->image.player->instances[0].y + SIZE / 2) / SIZE][x] != '1')
		x--;
	while (data->map[y][(data->image.player->instances[0].x + SIZE / 2) / SIZE] != '1')
		y--;
	printf("x %d pxcos %f y %d\n", x, (px + cos(rads(40))) / SIZE, y);
	if (x - (data->image.player->instances[0].x + SIZE / 2) / SIZE < y - (data->image.player->instances[0].y + SIZE / 2) / SIZE)
	{
		while (px > (x * SIZE) + SIZE)
		{
			//puts("entra");
			mlx_put_pixel(data->image.aux, px + cos(rads(40)), py + cos(rads(40)), 0xFFFFFFFF);
			py--;
			px--;
		}
	}
	else
		while (py > (y * SIZE) + SIZE)
		{
			//puts("entra");
			mlx_put_pixel(data->image.aux, px + cos(rads(40)), py + cos(rads(40)), 0xFFFFFFFF);
			py--;
			px--;
		}
} */

void	putpixel(t_map *data)
{
	int px = data->image.player->instances[0].x + SIZE / 2;
	int py = data->image.player->instances[0].y + SIZE / 2;
	int y = (data->image.player->instances[0].y + SIZE / 2) / SIZE;
	int x = (data->image.player->instances[0].x + SIZE / 2) / SIZE;
	while (data->map[y][x] != '1')
		y--;
	while (py > (y * SIZE) + SIZE && px)
	{
		mlx_put_pixel(data->image.aux, px, py, 0xFF0000FF);
		py--;
	}
	putpixelx(data);
	putpixeldiag(data, ANG);


	px = data->image.player->instances[0].x + SIZE / 2;
	mlx_put_pixel(data->image.aux, px + 1, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px + 2, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px + 3, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px - 3, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px - 2, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px - 1, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px, data->image.player->instances[0].y + SIZE / 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px, data->image.player->instances[0].y + SIZE / 2 + 1, 0xa413da);
	mlx_put_pixel(data->image.aux, px, data->image.player->instances[0].y + SIZE / 2 + 2, 0xa413da);
	mlx_put_pixel(data->image.aux, px, data->image.player->instances[0].y + SIZE / 2 + 3, 0xa413da);
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
	putpixel(data);
	deletepixel(data, y, x);


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


