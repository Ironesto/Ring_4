#include "../cub3d.h"

t_point	if_leftright(t_map *data, t_point end, int ang)
{	
	if (end.y <= 0)
	{
		end.y = 0;
		end.x = data->player->ppoint.x + catady(data->player->ppoint.y, ang);
		return (end);
	}
	if (end.y > data->h * SIZE)
	{
		end.y = data->h * SIZE;
		end.x = data->player->ppoint.x - catady(end.y - data->player->ppoint.y, ang);
		return (end);
	}
	return (end);
}

t_point	dist_right(t_map *data, float py, float px, int ang)
{
	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = px / SIZE;
	auxx = px;
	y = py / SIZE;
	while (auxx < x * SIZE + SIZE)
		auxx++;
	end.x = fabs(px - auxx) + px;
	end.y = py - catopo(fabs(px - auxx), ang);
	end.dir = 'R';
	if (ang == 90)
	{
		end.y = 0;
		end.x = data->player->ppoint.x;
		return (end);
	}
	if (end.y <= 0 || end.y > data->h * SIZE)
		return(if_leftright(data, end, ang));
	y = end.y / SIZE;
	if (data->map[y][x + 1] != '1')
		return (dist_right(data, end.y , end.x, ang));
	return (end);
}

t_point	dist_left(t_map *data, float py, float px, int ang)
{
	int	x;
	int	auxx;
	int	y;
	t_point end;

	x = (px - 1) / SIZE;
	auxx = px;
	y = py / SIZE;
	while (auxx > x * SIZE)
		auxx--;
	end.x = px - fabs(px - auxx);
	end.y = py + catopo(fabs(px - auxx), ang);
	end.dir = 'L';
	if (end.y <= 0 || end.y > data->h * SIZE)
		return(if_leftright(data, end, ang));
	x = end.x / SIZE;
	y = end.y / SIZE;
	if ((int)end.x % SIZE == 0 && (int)end.y % SIZE == 0 && end.y >= 0)
	{
		if (y > 0 && data->map[y - 1][x - 1] == '1' && data->map[y - 1][x] != '1')
			return (end);
	}
	if (data->map[y][x - 1] != '1')
		return (dist_left(data, end.y, end.x, ang));
	return (end);
}
