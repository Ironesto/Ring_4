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
	int auxx = (px + cos((ang))) / SIZE;
	int auxy = (py + cos((ang))) / SIZE;
	while (data->map[auxy][auxx] != '1')
	{
		auxx = (px + cos((ang))) / SIZE;
		auxy = (py + cos((ang))) / SIZE;
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
			mlx_put_pixel(data->image.aux, px + cos((ang)), py + cos((ang)), 0x00000000);
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
	int auxx = (px + cos((ang))) / SIZE;
	int auxy = (py + cos((ang))) / SIZE;
	while (data->map[auxy][auxx] != '1')
	{
		auxx = (px + cos((ang))) / SIZE;
		auxy = (py + cos((ang))) / SIZE;
		px--;
		py--;
	}
	px = data->image.player->instances[0].x + SIZE / 2;
	py = data->image.player->instances[0].y + SIZE / 2;

	//printf("cos %f sin %f\n", cos((ang)), sin((ang)));
	while (px > (auxx * SIZE) + SIZE || py > (auxy * SIZE) + SIZE)
	{
		mlx_put_pixel(data->image.aux, px + cos((ang)), py + cos((ang)), 0xFFFFFFFF);
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

	res = len / cos((ang));
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
	//printf(" %f cos %f sin %f  tan %f\n",(ang), cos((ang)), sin((ang)), tan((ang)));
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
	printf("x %d pxcos %f y %d\n", x, (px + cos((40))) / SIZE, y);
	if (x - (data->image.player->instances[0].x + SIZE / 2) / SIZE < y - (data->image.player->instances[0].y + SIZE / 2) / SIZE)
	{
		while (px > (x * SIZE) + SIZE)
		{
			//puts("entra");
			mlx_put_pixel(data->image.aux, px + cos((40)), py + cos((40)), 0xFFFFFFFF);
			py--;
			px--;
		}
	}
	else
		while (py > (y * SIZE) + SIZE)
		{
			//puts("entra");
			mlx_put_pixel(data->image.aux, px + cos((40)), py + cos((40)), 0xFFFFFFFF);
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