#include "../cub3d.h"

t_point	if_updown(t_map *data, t_point end, int x, int ang)
{
	if (end.x <= 0)
	{
		end.x = 0;
		end.y = data->player->ppoint.y + catopo(data->player->ppoint.x, ang);
		return (end);
	}
	if (x >= data->w - 1)
	{
		end.x = data->w * SIZE - SIZE;
		end.y = data->player->ppoint.y - catopo(end.x - data->player->ppoint.x, ang);
		return (end);
	}
	return (end);
}

t_point	dist_up(t_map *data, float py, float px, int ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;

	x = (px) / SIZE;
	auxy = py;
	y = (py - 1) / SIZE;
	while (auxy > y * SIZE)
		auxy--;
	end.y = py - fabs(py - auxy);
	end.x = catady(fabs(py - auxy), ang) + px;
	x = (end.x) / SIZE;
	y = (end.y) / SIZE;
	end.dir = 'U';
	if (end.x <= 0 || x >= data->w - 1)
		return (if_updown(data, end, x, ang));
	if ((int)(end.x) % SIZE == 0 && (int)end.y % SIZE == 0 && ang > 90)
	{
		if (data->map[y - 1][x - 1] == '1' && data->map[y][x -1] != '1')
			return (end);
	}
	if (data->map[y - 1][x] != '1')
		return (dist_up(data, end.y , end.x, ang));
	return (end);
}

t_point	dist_down(t_map *data, float py, float px, int ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;

	x = (px) / SIZE;
	auxy = py;
	y = (py) / SIZE;
	while (auxy < y * SIZE + SIZE)
		auxy++;
	end.x = catopo(auxy - py, ang - 90) + px;
	end.y = py + auxy - py;
	x = (end.x) / SIZE;
	y = (end.y) / SIZE;
	end.dir = 'D';
	if (end.x <= 0 || x >= data->w - 1)
		return (if_updown(data, end, x, ang));
	if ((int)(end.x) % SIZE == 0 && (int)end.y % SIZE == 0 && ang > 90)
	{
		if (data->map[y][x] == '1')
			return (end);
	}
	if (data->map[y][x] != '1' && y < data->h)
		return (dist_down(data, end.y , end.x, ang));
	return (end);
}
