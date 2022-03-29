/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:47:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/29 18:32:28 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long_bonus.h"

/*
free gwin struct resource
gwin->mlx, ->mlxwin must be initiazed.
*/
void	clean_gwin(t_gwin *gwin)
{
	int	i;

	i = -1;
	while (++i < 42)
	{
		if (gwin->tile[i])
		{
			mlx_destroy_image(gwin->mlx, gwin->tile[i]);
			gwin->tile[i] = NULL;
		}
	}
	if (gwin->gmap.mov_str)
		free(gwin->gmap.mov_str);
	clean_map(&(gwin->gmap));
}

/*
!mlx_destroy_window leaks
*/
static int	ld_tilerr(t_gwin *gwin, char *err, int errnum)
{
	ft_putstr_fd(err, 2);
	clean_gwin(gwin);
	mlx_destroy_window(gwin->mlx, gwin->mlx_win);
	return (errnum);
}

int	ld_tile(t_gwin *gwin, int idx, char *path)
{
	int	pos[2];

	gwin->tile[idx] = mlx_xpm_file_to_image(gwin->mlx, path, &pos[0], &pos[1]);
	if (!gwin->tile[idx])
		return (0);
	return (1);
}

static int	load_tile_p(t_gwin *gwin)
{
	if (!ld_tile(gwin, TILE_PLAYER + PL_DIRDOWN, "data/player_down_0.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRDOWN + 1, "data/player_down_1.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRDOWN + 2, "data/player_down_2.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRLEFT, "data/player_left_0.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRLEFT + 1, "data/player_left_1.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRLEFT + 2, "data/player_left_2.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRUP, "data/player_up_0.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRUP + 1, "data/player_up_1.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRUP + 2, "data/player_up_2.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRRIGHT, "data/player_right_0.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRRIGHT + 1, "data/player_right_1.xpm") \
	|| !ld_tile(gwin, TILE_PLAYER + PL_DIRRIGHT + 2, "data/player_right_2.xpm"))
		return (0);
	if (!ld_tile(gwin, TILE_GHOST, "data/ghost_0.xpm") \
	|| !ld_tile(gwin, TILE_GHOST + 1, "data/ghost_1.xpm") \
	|| !ld_tile(gwin, TILE_GHOST + 2, "data/ghost_2.xpm") \
	|| !ld_tile(gwin, TILE_GHOST + 3, "data/ghost_3.xpm"))
		return (0);
	return (1);
}

//	return (ld_tilerr(gwin, "Error\nTest error\n", 0));
int	loadtile(t_gwin *gwin)
{
	if (!ld_tile(gwin, TILE_GROUND, "data/ground_gray.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading ground.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_WALL, "data/wall1.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading wall.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_EXIT_CLOSED, "data/doorclosed.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading doorclosed.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_EXIT_OPENED, "data/dooropened.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading dooropened.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_COIN, "data/coin_0.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading coin_0.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_COIN + 1, "data/coin_1.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading coin_1.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_YOUWIN, "data/youwin.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading youwin.xpm tile\n", 0));
	if (!ld_tile(gwin, TILE_YOULOOSE, "data/youloose.xpm"))
		return (ld_tilerr(gwin, "Error\nError loading youloose.xpm tile\n", 0));
	if (!load_tile_p(gwin))
		return (ld_tilerr(gwin, "Error\nError loading player or ghost tiles\n", \
0));
	gwin->gmap.mov_str = ft_strdup("Number of movements: 0");
	if (!gwin->gmap.mov_str)
		return (ld_tilerr(gwin, "Error\nMemory allocation error\n", 0));
	return (1);
}
