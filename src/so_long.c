/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:28:12 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/25 18:35:51 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../ft_lib/libft.h"
#include "so_long.h"

void	init_map(t_gmap *gmap)
{
	gmap->col = 0;
	gmap->row = 0;
	gmap->map = NULL;
}

void	clean_map(t_gmap *gmap)
{
	init_map(gmap);
}

int	load_map(t_gmap *gmap, char *mpath)
{
	int	fd;

	init_map(gmap);
	fd = open(mpath, O_RDONLY);
	ft_putstr_fd("Open file ", 2);
	perror(mpath);
	if (close(fd))
	{
		perror(mpath);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_gmap	gmap;

	if (argc != 2)
		return (1);
	ft_putendl_fd(argv[1], 1);
	init_map(&gmap);
	if (load_map(&gmap, argv[1]))
		return (2);
	else
		clean_map(&gmap);
	return (0);
}
