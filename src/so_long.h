/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:01:26 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/05 15:28:24 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

void	init_map(t_gmap *gmap);
void	clean_map(t_gmap *gmap);
int		getfd_mapfile(char *mpath);
int		load_map(t_gmap *gmap, char *mpath);
#endif
