/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:57:18 by slord             #+#    #+#             */
/*   Updated: 2022/08/02 13:59:52 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_monster(t_mlx *info)
{
	int	x;
	int	y;
	int	nb;
	int	g;

	x = info->monster.x;
	y = info->monster.y;
	g = info->player.x;
	nb = cheap_random(g);
	if (nb == 0)
	{
		if (info->m[x][y + 1] != '1' && info->m[x][y + 1] != 'E'
				&& info->m[x][y + 1] != 'C')
			move_monster(info, &info->monster.y, 1);
	}
	if (nb == 1)
	{
		if (info->m[x][y - 1] != '1' && info->m[x][y - 1] != 'E'
				&& info->m[x][y - 1] != 'C')
			move_monster(info, &info->monster.y, -1);
	}
	validate_monster_1(info, nb);
}

void	validate_monster_1(t_mlx *info, int nb)
{
	int	x;
	int	y;
	int	g;

	x = info->monster.x;
	y = info->monster.y;
	g = info->player.x;
	nb = cheap_random(g);
	if (nb == 2)
	{
		if (info->m[x - 1][y] != '1' && info->m[x - 1][y] != 'E'
				&& info->m[x - 1][y] != 'C')
			move_monster(info, &info->monster.x, -1);
	}
	if (nb == 3)
	{
		if (info->m[x + 1][y] != '1' && info->m[x + 1][y] != 'E'
				&& info->m[x + 1][y] != 'C')
			move_monster(info, &info->monster.x, 1);
	}
}

void	move_monster(t_mlx *info, int *pxy, int inc)
{
	if (info->m[info->monster.x][info->monster.y] == 'E')
	{
		info->m[info->monster.x][info->monster.y] = 'E';
		draw_map(info);
	}
	else
		info->m[info->monster.x][info->monster.y] = '0';
	*pxy = *pxy + inc;
	info->m[info->monster.x][info->monster.y] = 'M';
	draw_map(info);
	if (info->monster.x == info->player.x && info->player.y == info->monster.y)
		game_over(info, 0);
}
