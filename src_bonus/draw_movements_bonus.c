/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:43:32 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/29 19:23:40 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long_bonus.h"

void	count_movements(t_gwin *gwin)
{
	char	*str_mv;

	gwin->gmap.movements++;
	free(gwin->gmap.mov_str);
	str_mv = ft_itoa(gwin->gmap.movements);
	gwin->gmap.mov_str = ft_strjoin("Number of movements: ", str_mv);
	free(str_mv);
}

void	draw_movements(t_gwin *gwin)
{
	void	*t;

	t = mlx_new_image(gwin->mlx, 180, 20);
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, t, 6, 6);
	mlx_string_put(gwin->mlx, gwin->mlx_win, 10, 20, 0x00ffffff, \
gwin->gmap.mov_str);
	mlx_destroy_image(gwin->mlx, t);
}

void	draw_youwin(t_gwin *gwin)
{
	if ((gwin->gmap.exits / 25) % 2 == 0)
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_YOUWIN], \
gwin->x_wind / 2 - 192, gwin->y_wind / 2 - 64);
	if (!--gwin->gmap.exits)
		closewin_h(gwin);
}

void	draw_youloose(t_gwin *gwin)
{
	if ((gwin->gmap.patrol / 25) % 2 == 0)
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_YOULOOSE], \
gwin->x_wind / 2 - 192, gwin->y_wind / 2 - 64);
	if (!--gwin->gmap.patrol)
		closewin_h(gwin);
}
