/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:53:30 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/26 14:00:16 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../ft_lib/libft.h"
#include "so_long_bonus.h"

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

int	open_ber(char *mpath, int flag)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(mpath, '.');
	if (!ext || (ext && ft_strncmp(ext, ".ber", 5) != 0))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mpath, 2);
		ft_putstr_fd(" is not .ber file.\nUsage: ./so_long [maps].ber\n", 2);
		return (-1);
	}
	fd = open(mpath, flag);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mpath, 2);
		perror(" file cannot be opened");
		return (-1);
	}
	return (fd);
}

int	getfd_mapfile(char *mpath)
{
	int	fd;

	fd = open(mpath, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mpath, 2);
		ft_putstr_fd(" - directory cannot be opened\n", 2);
		close(fd);
		return (-1);
	}
	return (open_ber(mpath, O_RDONLY));
}
