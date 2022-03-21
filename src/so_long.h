/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:01:26 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/22 00:02:44 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../mlx/mlx.h"

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SZ 128
# define TILE_GROUND 0
# define TILE_WALL 4
# define TILE_EXIT_CLOSED 8
# define TILE_EXIT_OPENED 9
# define TILE_COIN 16
# define TILE_PLAYER 20
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_gmap
{
	int		col;
	int		row;
	int		coins;
	int		exits;
	int		pl_col;
	int		pl_row;
	int		movements;
	char	**map;
}	t_gmap;

typedef struct s_gwin
{
	void	*mlx;
	void	*mlx_win;
	void	*tile[42];
	int		x_wind;
	int		y_wind;
	t_gmap	gmap;
}	t_gwin;

void	init_map(t_gmap *gmap);
void	init_gwin(t_gwin *gwin);
void	clean_map(t_gmap *gmap);
int		getfd_mapfile(char *mpath);
int		load_map(t_gmap *gmap, char *mpath);
int		loadtile(t_gwin *gwin);
void	clean_gwin(t_gwin *gwin);
#endif
