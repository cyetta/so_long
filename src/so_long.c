/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:28:12 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/06 20:42:04 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../ft_lib/libft.h"
#include "so_long.h"

void	init_map(t_gmap *gmap)
{
	ft_memset(gmap, 0, sizeof(t_gmap));
}

void	clean_map(t_gmap *gmap)
{
	int	i;

	if (gmap->map)
	{
		i = -1;
		while (++i < gmap->row)
			free(gmap->map[i]);
		free(gmap->map);
	}
	init_map(gmap);
}

int	getfd_mapfile(char *mpath)
{
	int	fd;

	fd = open(mpath, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mpath, 2);
		ft_putstr_fd("  directory cannot be opened\n", 2);
		return (-1);
	}
	else
	{
		fd = open(mpath, O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(mpath, 2);
			perror(" file cannot be opened");
			return (-1);
		}
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	t_gmap	gmap;
	int		i;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <maps.ber>\n", 2);
		return (1);
	}
	ft_putendl_fd(argv[1], 1);
	init_map(&gmap);
	if (!load_map(&gmap, argv[1]))
		return (2);
	i = -1;
	while (++i < gmap.row)
		ft_printf("%s\n", gmap.map[i]);
	ft_printf("coins%5d\nexit%5d\ncol%5d\nrow%5d\npl_col%5d\npl_row%5d\n", \
gmap.coins, gmap.exits, gmap.col, gmap.row, gmap.pl_col, gmap.pl_row);
	clean_map(&gmap);
	return (0);
}
