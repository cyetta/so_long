/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:28:12 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/04 23:49:05 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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

int	app_str2map(t_gmap *gmap, char *s)
{
	char	**t;

	t = gmap->map;
	gmap->map = (char **) ft_calloc(gmap->row + 1, sizeof(char *));
	if (!gmap->map)
		return (0);
	if (s[ft_strlen(s) - 1] == '\n')
		s[ft_strlen(s) - 1] = '\0';
	if (gmap->row > 0)
	{
		ft_memcpy(gmap->map, t, sizeof(char *) * gmap->row);
		free(t);
	}
	gmap->map[gmap->row] = s;
	++gmap->row;
	return (1);
}

int	map_check_pos(int i, int j, t_gmap *gmap)
{
	if ((i == 0 || i == gmap->row - 1) && gmap->map[i][j] != '1')
		return (0);
	else if ((j == 0 || j == gmap->col - 1) && gmap->map[i][j] != '1')
		return (0);
	else if (gmap->map[i][j] == 'C')
		gmap->coins++;
	else if (gmap->map[i][j] == 'E')
		gmap->exits++;
	else if (gmap->map[i][j] == 'P' && !gmap->pl_col && !gmap->pl_row)
	{
		gmap->pl_col = j;
		gmap->pl_row = i;
	}
	else if (gmap->map[i][j] == 'P' && gmap->pl_col && gmap->pl_row)
		gmap->map[i][j] = '0';
	else if (gmap->map[i][j] != '0' && gmap->map[i][j] != '1')
		return (0);
	return (1);
}

int	map_check_borders(t_gmap *gmap)
{
	int	i;
	int	j;

	gmap->col = ft_strlen(gmap->map[0]);
	i = -1;
	while (++i < gmap->row)
	{
		if (gmap->col != (int)ft_strlen(gmap->map[i]))
			return (0);
		j = -1;
		while (++j < gmap->col)
			if (!map_check_pos(i, j, gmap))
				return (0);
	}
	if (gmap->coins < 1 || gmap->exits < 1 || (!gmap->pl_col && !gmap->pl_row))
		return (0);
	return (1);
}

int	check_map(t_gmap *gmap)
{
	if (gmap->row == 0)
		ft_putstr_fd("Error\nMap file is empty\n", 2);
	else if (gmap->row < 3)
		ft_putstr_fd("Error\nIncorrect мap file\n", 2);
	else if (!map_check_borders(gmap))
		ft_putstr_fd("Error\nIncorrect мap file\n", 2);
	else
		return (1);
	clean_map(gmap);
	return (0);
}

int	load_map(t_gmap *gmap, char *mpath)
{
	int		fd;
	char	*s;

	init_map(gmap);
	fd = getfd_mapfile(mpath);
	if (fd < 0)
		return (0);
	s = get_next_line(fd);
	while (s)
	{
		if (!app_str2map(gmap, s))
			break ;
		s = get_next_line(fd);
	}
	close(fd);
	if (s)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 2);
		clean_map(gmap);
		free(s);
		return (0);
	}
	return (check_map(gmap));
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
