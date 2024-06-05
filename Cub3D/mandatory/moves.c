#include "cub3d.h"

int	compmovy(int posx, int pos, int size, t_map *data)
{
	int			aux;

	aux = (pos + 20) / size;
	if (data->map[data->player->posy - 1][data->player->posx] == '1' && aux < data->player->posy)
		return (1);
	if ((pos + 20) / size < data->player->posy && (posx + 47) / size > data->player->posx
		&& data->map[data->player->posy - 1][data->player->posx + 1] == '1'
			&& data->map[data->player->posy][data->player->posx + 1] != '1')
		return (1);
	if ((pos + 20) / size < data->player->posy && (posx + 15) / size < data->player->posx
		&& data->map[data->player->posy - 1][data->player->posx - 1] == '1'
			&& data->map[data->player->posy][data->player->posx - 1] != '1')
		return (1);
	if (aux < data->player->posy && (pos + 60) / size < data->player->posy)
	{
		if (data->map[data->player->posy - 1][data->player->posx] != '1')
		{
			data->player->posy--;
			//ft_printf("moves: %d\n", ++data->moves);
		}
		else
			return (1);
	}
	return (0);
}

int	compmovy2(int posx, int pos, int size, t_map *data)
{
	int			aux;

	aux = (pos + 55) / size;
	if ((pos + 63) / size > data->player->posy
		&& data->map[data->player->posy + 1][data->player->posx] == '1')
		return (1);
	if ((pos + 63) / size > data->player->posy && (posx + 47) / size > data->player->posx
		&& data->map[data->player->posy + 1][data->player->posx + 1] == '1'
			&& data->map[data->player->posy][data->player->posx + 1] != '1')
		return (1);
	if ((pos + 63) / size > data->player->posy && (posx + 15) / size < data->player->posx
		&& data->map[data->player->posy + 1][data->player->posx - 1] == '1'
			&& data->map[data->player->posy][data->player->posx - 1] != '1')
		return (1);
	if (aux > data->player->posy && (pos + 20) / size > data->player->posy)
	{
		if (data->map[data->player->posy + 1][data->player->posx] != '1')
		{
			data->player->posy++;
			//ft_printf("moves: %d\n", ++data->moves);
		}
		else
			return (1);
	}
	return (0);
}

int	compmovx2(int posy, int pos, int size, t_map *data)
{
	int			aux;

	aux = (pos + 50) / size;
	if (aux > data->player->posx && data->map[data->player->posy][data->player->posx + 1] == '1')
		return (1);
	if (aux > data->player->posx && (posy + 23) / size < data->player->posy
		&& data->map[data->player->posy - 1][data->player->posx + 1] == '1'
			&& data->map[data->player->posy - 1][data->player->posx] != '1')
		return (1);
	if (aux > data->player->posx && (posy + 61) / size > data->player->posy
		&& data->map[data->player->posy + 1][data->player->posx + 1] == '1'
			&& data->map[data->player->posy + 1][data->player->posx] != '1')
		return (1);
	if ((pos + 20) / size > data->player->posx && aux > data->player->posx)
	{
		if (data->map[data->player->posy][data->player->posx + 1] != '1')
		{
			data->player->posx++;
			//ft_printf("moves: %d\n", ++data->moves);
		}
		else
			return (1);
	}
	return (0);
}

int	compmovx(int posy, int pos, int size, t_map *data)
{
	int	aux;

	aux = (pos + 12) / size;
	if (data->map[data->player->posy][data->player->posx - 1] == '1'
		&& (pos + 12) / size < data->player->posx)
		return (1);
	if (aux < data->player->posx && (posy + 23) / size < data->player->posy
		&& data->map[data->player->posy - 1][data->player->posx - 1] == '1'
			&& data->map[data->player->posy - 1][data->player->posx] != '1')
		return (1);
	if (aux < data->player->posx && (posy + 61) / size > data->player->posy
		&& data->map[data->player->posy + 1][data->player->posx - 1] == '1'
			&& data->map[data->player->posy + 1][data->player->posx] != '1')
		return (1);
	if (aux < data->player->posx && (pos + 40) / size < data->player->posx)
	{
		if (data->map[data->player->posy][data->player->posx - 1] != '1')
		{
			data->player->posx--;
			//ft_printf("moves: %d\n", ++data->moves);
		}
		else
			return (1);
	}
	return (0);
}