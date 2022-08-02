/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:03:47 by slord             #+#    #+#             */
/*   Updated: 2022/08/02 14:55:42 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate(int key, t_mlx *info)
{
	int	x;
	int	y;

	x = info->player.x;
	y = info->player.y;
	if (key == 2)
	{
		if (info->m[x][y + 1] == 'E' && info->nb_key == 0)
			game_over(info, 0);
		if (info->m[x][y + 1] != '1' && info->m[x][y + 1] != 'E')
			move(info, &info->player.y, 1);
	}
	if (key == 0)
	{
		if (info->m[x][y - 1] == 'E' && info->nb_key == 0)
			game_over(info, 0);
		if (info->m[x][y - 1] != '1' && info->m[x][y - 1] != 'E')
			move(info, &info->player.y, -1);
	}
	validate_1(info, key);
	return (0);
}

void	move(t_mlx *info, int *pxy, int inc)
{
	info->m[info->player.x][info->player.y] = '0';
	*pxy = *pxy + inc;
	if (info->m[info->player.x][info->player.y] == 'C')
		info->nb_key --;
	info->m[info->player.x][info->player.y] = 'P';
	draw_map(info);
	if (info->monster.x == info->player.x && info->player.y == info->monster.y)
		game_over(info, 0);
	validate_monster(info);
}

int	cheap_random(int s)
{
	static int	x = 42;
	int			a;
	int			m;
	int			c;

	c = s;
	m = 1117;
	a = 314;
	x = (a * x + c) % m;
	return ((a * x + c) % 4);
}
