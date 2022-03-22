/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:13:15 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/22 19:22:49 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

int	closewin_h(t_gwin *gwin)
{
	clean_gwin(gwin);
	mlx_destroy_window(gwin->mlx, gwin->mlx_win);
	exit (1);
}

int	level_complete(t_gwin *gwin)
{
	ft_printf("Congratulations, level complete!\n");
	closewin_h(gwin);
	return (0);
}

	// ft_printf("key pressed:%d\n", keycode);
int	keydown_h(int keycode, t_gwin *gwin)
{
	if (keycode == KEY_W)
		return (pl_move_up(gwin));
	else if (keycode == KEY_S)
		return (pl_move_down(gwin));
	else if (keycode == KEY_A)
		return (pl_move_left(gwin));
	else if (keycode == KEY_D)
		return (pl_move_right(gwin));
	else if (keycode == KEY_ESC)
		return (closewin_h(gwin));
	return (0);
}

//	ft_printf("frame:%d\n", gwin->frame);
int	render_h(t_gwin *gwin)
{
	if (!gwin->frame)
		gwin->render = 1;
	if (gwin->render)
		update_win(gwin);
	gwin->frame = ++gwin->frame % 100 ;
	return (0);
}
