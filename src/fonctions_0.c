/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:03:47 by slord             #+#    #+#             */
/*   Updated: 2022/08/01 20:01:21 by slord            ###   ########.fr       */
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
	info->m[info->monster.x][info->monster.y] = 'M';
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

void	game_over(t_mlx *info, int exit_code)
{
	int	i;
	int	j;

	if (exit_code == 0)
		exit(exit_code);
	i = 0;
	j = 0;
	mlx_destroy_image(info->mlx_pointer, info->key);
	mlx_destroy_image(info->mlx_pointer, info->wall);
	mlx_destroy_image(info->mlx_pointer, info->door);
	mlx_destroy_image(info->mlx_pointer, info->player1);
	mlx_destroy_image(info->mlx_pointer, info->pouliche);
	mlx_destroy_image(info->mlx_pointer, info->floor);
	mlx_destroy_window(info->mlx_pointer, info->window);
	while (info->m[i] != NULL)
	{
		ft_bzero(info->m[i], ft_strlen(info->m[i]));
		free (info->m[i]);
		i++;
	}
	free(info->m);
	exit(exit_code);
}

void	map_checker(t_mlx *info)
{
	check_walls(info);
	check_doublons(info, 'E');
	check_doublons(info, 'P');
	check_no_item(info, 'E');
	check_no_item(info, 'P');
	check_no_item(info, 'C');
	check_map_reactangle(info);
}
