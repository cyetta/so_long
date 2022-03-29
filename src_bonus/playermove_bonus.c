/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:45:38 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/29 20:29:07 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "so_long_bonus.h"

int	pl_move(t_gwin *gwin, int direction, int row, int col)
{
	gwin->gmap.pl_move = PL_MOVE;
	gwin->gmap.pl_direction = direction;
	gwin->gmap.pl_mv2row = row;
	gwin->gmap.pl_mv2col = col;
	gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col] = '0';
	gwin->gmap.map[row][col] = 'P';
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
	else if (gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] >= 'G' \
	&& gwin->gmap.map[gwin->gmap.pl_row - 1][gwin->gmap.pl_col] <= 'N')
		return (level_fail(gwin));
	pl_move(gwin, PL_DIRUP, gwin->gmap.pl_row - 1, gwin->gmap.pl_col);
	count_movements(gwin);
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
	else if (gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] >= 'G' \
	&& gwin->gmap.map[gwin->gmap.pl_row + 1][gwin->gmap.pl_col] <= 'N')
		return (level_fail(gwin));
	pl_move(gwin, PL_DIRDOWN, gwin->gmap.pl_row + 1, gwin->gmap.pl_col);
	count_movements(gwin);
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
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] >= 'G' \
	&& gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col - 1] <= 'N')
		return (level_fail(gwin));
	pl_move(gwin, PL_DIRLEFT, gwin->gmap.pl_row, gwin->gmap.pl_col - 1);
	count_movements(gwin);
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
	else if (gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] >= 'G' \
	&& gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col + 1] <= 'N')
		return (level_fail(gwin));
	pl_move(gwin, PL_DIRRIGHT, gwin->gmap.pl_row, gwin->gmap.pl_col + 1);
	count_movements(gwin);
	return (0);
}
