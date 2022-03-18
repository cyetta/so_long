/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:53:30 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/18 17:21:41 by cyetta           ###   ########.fr       */
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

void	init_gwin(t_gwin *gwin)
{
	ft_memset(gwin, 0, sizeof(t_gwin));
}

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
