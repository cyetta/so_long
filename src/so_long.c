/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:28:12 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/17 20:41:28 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

int	start_game(t_gwin *gwin)
{
	gwin->x_wind = gwin->gmap.col * 16;
	gwin->y_wind = gwin->gmap.row * 16;
	gwin->mlx = mlx_init();
	if (gwin->mlx)
	{
		gwin->mlx_win = mlx_new_window(gwin->mlx, gwin->x_wind, gwin->y_wind, \
"so_long");
		mlx_loop(gwin->mlx);
	}
	else
		ft_putstr_fd("Error\nmlx not initialized", 2);

	clean_map(&gwin->gmap);
	return (0);
}

int	main(int argc, char **argv)
{
	t_gwin	gwin;
	int		i;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <maps.ber>\n", 2);
		return (1);
	}
	// ft_putendl_fd(argv[1], 1);
	if (!load_map(&gwin.gmap, argv[1]))
		return (2);
	i = -1;
// 	while (++i < gwin.gmap.row)
// 		ft_printf("%s\n", gwin.gmap.map[i]);
// 	ft_printf("coins%5d\nexit%5d\ncol%5d\nrow%5d\npl_col%5d\npl_row%5d\n", \
// gwin.gmap.coins, gwin.gmap.exits, gwin.gmap.col, gwin.gmap.row, \
// gwin.gmap.pl_col, gwin.gmap.pl_row);
	start_game(&gwin);
	return (0);
}
