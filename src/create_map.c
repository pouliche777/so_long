/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:53:40 by slord             #+#    #+#             */
/*   Updated: 2022/08/09 16:35:09 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_mlx *info, void *image, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
		{
			if (info->m[i][j] == c)
				mlx_put_image_to_window(info->mlx_pointer,
					info->window, image, (j * 56), (i * 56));
			j++;
		}
		j = 0;
		i++;
	}
}

void	trouver_position_p(t_mlx *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	{
		while (info->m[i] != NULL)
		{
			while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
			{	
				if (info->m[i][j] == 'P')
				{
					info->player.x = i;
					info->player.y = j;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	trouver_position_m(t_mlx *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	{
		while (info->m[i] != NULL)
		{
			while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
			{	
				if (info->m[i][j] == 'E')
				{
					info->monster.x = i;
					info->monster.y = j;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	find_nb_keys(t_mlx *info)
{
	int	i;
	int	j;

	info->nb_key = 0;
	i = 0;
	j = 0;
	{
		while (info->m[i] != NULL)
		{
			while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
			{	
				if (info->m[i][j] == 'C')
				{
					info->nb_key++;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	validate_1(t_mlx *info, int key)
{
	int	x;
	int	y;

	x = info->player.x;
	y = info->player.y;
	if (key == 13)
	{
		if (info->m[x - 1][y] == 'E' && info->nb_key == 0)
			game_over(info, 0);
		if (info->m[x - 1][y] != '1' && info->m[x - 1][y] != 'E')
			move(info, &info->player.x, -1);
	}
	if (key == 1)
	{
		if (info->m[x + 1][y] == 'E' && info->nb_key == 0)
			game_over(info, 0);
		if (info->m[x + 1][y] != '1' && info->m[x + 1][y] != 'E')
			move(info, &info->player.x, 1);
	}
	if (key == 53)
		game_over(info, 1);
}
