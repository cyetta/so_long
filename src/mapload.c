/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:50:43 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/25 20:42:56 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "so_long.h"

/*
Append string to map array
*/
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

/*
Checks element on game map is correct
*/
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

/*
Checks for correct data loaded
*/
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
	gmap->exits = -1;
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

/*
Initialize gmap stucture by game map file data
returns 0 if error occured, gmap is cleaning
else returns 1
*/
int	load_map(t_gmap *gmap, char *mpath)
{
	int		fd;
	char	*s;

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
