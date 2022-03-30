/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:45:38 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/30 16:32:06 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "so_long.h"

int	pl_move(t_gwin *gwin, int direction, int row, int col)
{
	gwin->gmap.pl_move = PL_MOVE;
	gwin->gmap.pl_direction = direction;
	gwin->gmap.pl_row = row;
	gwin->gmap.pl_col = col;
	return (0);
}

int	pl_move_up(t_gwin *gwin)
{
	if (gwin->gmap.pl_move)
		return (1);
	else if (gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] == '1')
		return (pl_move(gwin, PL_DIRUP, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] == 'E' \
	&& gwin->gmap.collected == gwin->gmap.coins)
		return (level_complete(gwin));
	else if (gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] == 'E' \
	&& gwin->gmap.collected != gwin->gmap.coins)
		return (pl_move(gwin, PL_DIRUP, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] == 'C')
		gwin->gmap.collected++;
	pl_move(gwin, PL_DIRUP, gwin->gmap.pl_row - 1, gwin->gmap.pl_col);
	gwin->gmap.movements++;
	ft_printf("Number of movements:%d\n", gwin->gmap.movements);
	return (0);
}

int	pl_move_down(t_gwin *gwin)
{
	if (gwin->gmap.pl_move)
		return (1);
	else if (gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] == '1')
		return (pl_move(gwin, PL_DIRDOWN, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] == 'E' \
	&& gwin->gmap.collected == gwin->gmap.coins)
		return (level_complete(gwin));
	else if (gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] == 'E' \
	&& gwin->gmap.collected != gwin->gmap.coins)
		return (pl_move(gwin, PL_DIRDOWN, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] == 'C')
		gwin->gmap.collected++;
	pl_move(gwin, PL_DIRDOWN, gwin->gmap.pl_row + 1, gwin->gmap.pl_col);
	gwin->gmap.movements++;
	ft_printf("Number of movements:%d\n", gwin->gmap.movements);
	return (0);
}

int	pl_move_left(t_gwin *gwin)
{
	if (gwin->gmap.pl_move)
		return (1);
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] == '1')
		return (pl_move(gwin, PL_DIRLEFT, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] == 'E' \
	&& gwin->gmap.collected == gwin->gmap.coins)
		return (level_complete(gwin));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] == 'E' \
	&& gwin->gmap.collected != gwin->gmap.coins)
		return (pl_move(gwin, PL_DIRLEFT, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] == 'C')
		gwin->gmap.collected++;
	pl_move(gwin, PL_DIRLEFT, gwin->gmap.pl_row, gwin->gmap.pl_col - 1);
	gwin->gmap.movements++;
	ft_printf("Number of movements:%d\n", gwin->gmap.movements);
	return (0);
}

int	pl_move_right(t_gwin *gwin)
{
	if (gwin->gmap.pl_move)
		return (1);
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] == '1')
		return (pl_move(gwin, PL_DIRRIGHT, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] == 'E' \
	&& gwin->gmap.collected == gwin->gmap.coins)
		return (level_complete(gwin));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] == 'E' \
	&& gwin->gmap.collected != gwin->gmap.coins)
		return (pl_move(gwin, PL_DIRRIGHT, gwin->gmap.pl_row, \
gwin->gmap.pl_col));
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] == 'C')
		gwin->gmap.collected++;
	pl_move(gwin, PL_DIRRIGHT, gwin->gmap.pl_row, gwin->gmap.pl_col + 1);
	gwin->gmap.movements++;
	ft_printf("Number of movements:%d\n", gwin->gmap.movements);
	return (0);
}
