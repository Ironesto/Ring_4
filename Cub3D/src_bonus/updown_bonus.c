/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updown_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:29:28 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 01:50:43 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_point	if_updown(t_mlx *data, t_point end, int x, float ang)
{
	if (end.x <= 0)
	{
		end.x = 0;
		end.y = data->player->y + catopo(data->player->x, ang);
		return (end);
	}
	if (x > data->map->w_map)
	{
		end.x = data->map->w_map * TILE_SIZE;
		end.y = data->player->y - catopo(end.x - data->player->x, ang);
		return (end);
	}
	return (end);
}

t_point	dist_up(t_mlx *data, float py, float px, float ang)
{
	int		x;
	int		y;
	int		auxy;
	t_point	end;

	end.h = 0;
	x = (px) / TILE_SIZE;
	auxy = py;
	y = (py - 1) / TILE_SIZE;
	while (auxy > y * TILE_SIZE)
		auxy--;
	end.y = py - fabs(py - auxy);
	end.x = catady(fabs(py - auxy), ang) + px;
	x = end.x / TILE_SIZE;
	y = end.y / TILE_SIZE;
	end.dir = 'U';
	if (end.x <= 0 || x > data->map->w_map)
		return (if_updown(data, end, x, ang));
	if (y > 0 && data->map->map2d[y - 1][x] != '1')
		return (dist_up(data, end.y, end.x, ang));
	return (end);
}
/* 	if (data->map[y][x] == '1')
		puts("es 1"); */
	// if ((int)(end.x) % TILE_SIZE == 0 && (int)end.y % TILE_SIZE == 0 && ang > (M_PI / 2))
	// {
	// 	if (data->map->map2d[y - 1][x - 1] == '1' && data->map->map2d[y][x - 1] != '1')
	// 		return (end);
	// }

t_point	dist_down(t_mlx *data, float py, float px, float ang)
{
	int		x;
	int		y;
	int		auxy;
	t_point	end;

	end.h = 0;
	x = px / TILE_SIZE;
	auxy = py;
	y = py / TILE_SIZE;
	while (auxy < y * TILE_SIZE + TILE_SIZE)
		auxy++;
	end.x = catopo(auxy - py, ang - (M_PI / 2)) + px;
	end.y = py + auxy - py;
	x = end.x / TILE_SIZE;
	y = end.y / TILE_SIZE;
	end.dir = 'D';
	if (end.x <= 0 || x >= data->map->w_map - 1)
		return (if_updown(data, end, x, ang));
	if (y < data->map->h_map && data->map->map2d[y][x] != '1')
		return (dist_down(data, end.y, end.x, ang));
	return (end);
}

	// if ((int)(end.x) % TILE_SIZE == 0 && (int)end.y % TILE_SIZE == 0 && ang > (M_PI / 2))
	// {
	// 	if (data->map->map2d[y][x] == '1')
	// 		return (end);
	// }