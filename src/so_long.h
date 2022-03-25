/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:01:26 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/25 21:16:35 by cyetta           ###   ########.fr       */
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
# define TILE_YOUWIN 36
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define PL_MOVESTOP 0
# define PL_MOVE 1
# define PL_DIRDOWN 0
# define PL_DIRLEFT 1
# define PL_DIRUP 2
# define PL_DIRRIGHT 3

typedef struct s_gmap
{
	int		col;
	int		row;
	int		coins;
	int		exits;
	int		collected;
	int		pl_col;
	int		pl_row;
	int		pl_move;
	int		pl_direction;
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
	int		frame;
	int		render;
	t_gmap	gmap;
}	t_gwin;

void	init_map(t_gmap *gmap);
void	init_gwin(t_gwin *gwin);
void	clean_map(t_gmap *gmap);
int		getfd_mapfile(char *mpath);
int		load_map(t_gmap *gmap, char *mpath);
int		loadtile(t_gwin *gwin);
void	clean_gwin(t_gwin *gwin);
int		closewin_h(t_gwin *gwin);
int		keydown_h(int keycode, t_gwin *gwin);
int		render_h(t_gwin *gwin);
int		update_window(t_gwin *gwin);
int		draw_tile(t_gwin *gwin, char tile, int x, int y);
void	draw_ground(t_gwin *gwin, int x, int y);
void	draw_wall(t_gwin *gwin, int x, int y);
void	draw_coin(t_gwin *gwin, int x, int y);
void	draw_player(t_gwin *gwin, int x, int y);
void	draw_exit(t_gwin *gwin, int x, int y);
void	draw_youwin(t_gwin *gwin);
int		pl_move_up(t_gwin *gwin);
int		pl_move_down(t_gwin *gwin);
int		pl_move_left(t_gwin *gwin);
int		pl_move_right(t_gwin *gwin);
int		level_complete(t_gwin *gwin);
#endif
