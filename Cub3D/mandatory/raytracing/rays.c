#include "../cub3d.h"

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

void	deletepix(t_map *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < SCRNH)
	{
		k = 0;
		while (k < SCRNW)
		{
			mlx_put_pixel(data->image.aux, k, i, 0x00000000);
			k++;
		}
		i++;
	}
}

void	drawlines(t_map *data, t_point h)
{
	if (h.dir == 'U')
		draw(data, h, data->player->pp, CBLK);
	if (h.dir == 'D')
		draw(data, h, data->player->pp, CCIA);
	if (h.dir == 'R')
		draw(data, h, data->player->pp, CRED);
	if (h.dir == 'L')
		draw(data, h, data->player->pp, CGRN);
}

int	get_color(mlx_image_t *img, int p)
{
	int	c;

	c = img->pixels[p] << 24 | img->pixels[p + 1] << 16 | img->pixels[p + 2]
		<< 8 | img->pixels[p + 3];
	return (c);
}
/*  void	drawtexture(t_map *data, t_point init, t_point end, t_point p, float aux)
 {
	float i;
	int pixel;
	float	multi;
	int	x;

	x = (int)p.x / SIZE;
	pixel = ((SIZE * SIZE) - SIZE + ((int)p.x % SIZE)) * 4;
	multi = (end.y - init.y) / SIZE;
	i = i + (multi / (int)multi);
	while (SCRNH / 2 > init.y)
	{
		//i = multi - (multi / (int)multi);
		i =  -1;
		while (i < multi - (multi / (int)multi))
		{
			if (init.y + i >= 0 && init.y < SCRNH / 2)
				mlx_put_pixel(data->image.aux, init.x, (int)init.y + i, get_color(data->image.wall, pixel));
			i = i + (multi / (int)multi);
		}
		pixel = pixel - (SIZE * 4);
		init.y = init.y + i;
	}
	init.y = SCRNH / 2;
	pixel = ((SIZE * SIZE) - SIZE + ((int)p.x % SIZE)) * 4;
	while (end.y >= init.y)
	{
		//i = multi - (multi / (int)multi);
		i =  -1;
		while (i < multi - (multi / (int)multi))
		{
			if (init.y + i >= 0 && init.y < SCRNH)
				mlx_put_pixel(data->image.aux, init.x, (int)init.y + i, get_color(data->image.wall, pixel));
			i = i + (multi / (int)multi);
		}
		pixel = pixel - (SIZE * 4);
		init.y = init.y + i;
	}
 } */



void	drawtexture(t_map *data, t_point init, t_point end, t_point p, float aux)
{
		float i;
		int pixel;
		float	multi;
		pixel = ((SIZE * SIZE) - SIZE + ((int)p.x % SIZE)) * 4;
		multi = (end.y - init.y) / SIZE;
		//if (aux == SCRNW / 2)
			//printf("end - init / SIZE = %f\n", (end.y - init.y) / SIZE);
		while (end.y >= init.y)
		{
			i =  0;
			while (i <= (int)multi && init.y + i <= end.y)
			{
				if (init.y + i >= 0 && init.y < SCRNH)
					mlx_put_pixel(data->image.aux, init.x, (int)(init.y  + i), get_color(data->image.wall, pixel));
				//if (aux == SCRNW / 2 && get_color(data->image.wall, pixel) == 0 && init.y < SCRNH)
				//	printf("color %d en y %f\n", get_color(data->image.wall, pixel), init.y);
				i++;
			}
				if (init.y >= 0 && init.y < SCRNH)
					mlx_put_pixel(data->image.aux, init.x, (init.y + i), CBLK);
			i = 0;
			while (i < (int)multi && init.y + i <= end.y)
				i = i + (multi / (int)multi);
			/* if ((init.y + i) > (int)init.y + (int)i + 1 && init.y + 1 >= 0 && init.y + 1 < SCRNH)
				printf("se salta\n"); */
			init.y = init.y + i;
/* 			if (init.y - 1 >= 0 && init.y - 1 < SCRNH)
				mlx_put_pixel(data->image.aux, init.x, (int)(init.y - 1), get_color(data->image.wall, pixel)); */
			pixel = pixel - (SIZE * 4);
		}
}

void	draw3d(t_map *data, t_point p, float aux)
{
	t_point init;
	t_point end;
	float	dist_adap;
	int	alt_adap;

	//dist_adap = catady(SCRNW / 2, 62 / 2) - data->player->pp.y;	//CAMBIAR
	dist_adap = catady(SCRNW / 2, FOW / 2) - data->player->pp.y;	//CAMBIAR
	//dist_adap = catady(SCRNH / 2, FOW / 2);
	alt_adap = (300 / p.h) * dist_adap;		//CAMBIAR
	init.y = SCRNH / 2 + alt_adap / 2;
	init.x = aux;
	end.y = SCRNH / 2 - alt_adap / 2;
	end.x =  aux;

/*  	if (init.y >= SCRNH)
		init.y = SCRNH - 1;
	if (init.y <= 0)
		init.y = 0;
	if (end.y <= 0)
		end.y = 0;
	if (end.y >= SCRNH)
		end.y = SCRNH - 1;
	if (p.dir == 'U')
		draw(data, end, init, CWHI);
	if (p.dir == 'D')
		draw(data, end, init, CCIA);
	if (p.dir == 'R')
		draw(data, end, init, CRED);
	if (p.dir == 'L')
		draw(data, end, init, CGRN); */
	drawtexture(data, init, end, p, aux);

}

void	choose_line(t_map *data, float ang, float aux)
{
	t_point v;
	t_point h;
	float		py = data->player->pp.y;
	float		px = data->player->pp.x;

	if ((ang >= 0 && ang <= (PI / 2)) || (ang > PI + (PI / 2) && ang < 2 * PI))
		h = dist_right(data, py, px, ang);
	if (ang > (PI / 2) && ang <= PI + (PI / 2))
		h = dist_left(data, py, px, ang);
	if (ang > 0 && ang < PI)			
		v = dist_up(data, py, px, ang);
	if (ang >= PI && ang < 2 * PI)
		v = dist_down(data, py, px, ang);

	h.h = hipo(data->player->pp.y - h.y, data->player->pp.x - h.x);
	v.h = hipo(data->player->pp.y - v.y, data->player->pp.x - v.x);
	//if (h.h < v.h)
	if (v.h < h.h)
		h = v;

	draw3d(data, h, aux);
	//create(data, h);
	//drawlines(data, h);
}

void	drawang(t_map *data)
{
	float	ang;
	float	count;
	float	rays;

	rays = 0;
	ang = data->ang + (rads(ANG) / 2);
	count = data->ang + (rads(ANG) / 2);
	float totang =  rads(ANG) / SCRNW;
	while (rays < SCRNW)
	{
		if (ang >= 2 * PI)
			ang = ang - (2 * PI);
		if (ang < 0)
			ang = (2 * PI) + ang;
		choose_line(data, ang, rays);
		ang = ang - totang;
		count = count - totang;
		rays = rays + 1;
	}
}
