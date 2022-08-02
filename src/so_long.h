/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:14:16 by slord             #+#    #+#             */
/*   Updated: 2022/08/01 19:59:13 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_unit
{
	void	*img;
	int		x;
	int		y;
}	t_unit;

typedef struct s_mlx
{
	void		*mlx_pointer;
	void		*window;
	void		*key;
	void		*wall;
	void		*door;
	void		*floor;
	void		*pouliche;
	void		*player1;
	char		**m;
	int			nb_key;
	int			map_h;
	t_unit		monster;
	t_unit		player;
	t_unit		exit;
}	t_mlx;

void	read_map(char **argv, t_mlx *info);
int		map_height(char **argv);
void	put_img(t_mlx *info, void *img, char c);
void	draw_map(t_mlx *info);
int		validate(int key, t_mlx *info);
void	validate_monster(t_mlx *info);
void	move_monster(t_mlx *info, int *pxy, int inc);
void	move(t_mlx *info, int *pxy, int inc);
void	trouver_position_p(t_mlx *info);
void	trouver_position_m(t_mlx *info);
int		cheap_random(int s);
void	find_nb_keys(t_mlx *info);
void	game_over(t_mlx *info, int exit_code);
void	img_init(t_mlx *info);
void	validate_1(t_mlx *info, int key);
void	validate_monster_1(t_mlx *info, int nb);
void	check_walls(t_mlx *info);
void	check_walls_1(t_mlx *info, int i);
void	check_map_reactangle(t_mlx *info);
void	check_no_item(t_mlx *info, char c);
void	check_doublons(t_mlx *info, char c);
void	map_checker(t_mlx *info);

#endif