/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:47:49 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/04/11 19:59:29 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validargs(int argc, char **argv)
{
	char	*valid;
	
	if (argc != 2)
	{
		write(2, "ERROR: invalid number of arguments\n", 35);
		return (1);
	}
	valid = ft_strjoin("./maps/", argv[1]);
	if (open(valid, O_RDONLY) == -1)
	{
		write(2, "ERROR: map not found\n", 21);
		return (1);
	}
	if (ft_strncmp(&valid[ft_strlen(valid) - 4], ".cub", 3) != 0)
	{
		write(2, "ERROR: invalid extension\n", 25);
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (validargs(argc, argv) == 1)
		return (1);
	return (0);
}
