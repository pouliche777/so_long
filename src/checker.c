/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:46:34 by slord             #+#    #+#             */
/*   Updated: 2022/08/02 15:53:21 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_mlx *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
		{
			if (info->m[0][j] != '1')
			{
				printf("Map error : Borders of the map MUST be walls.");
				game_over(info, 0);
			}
			j++;
		}
		if (info->m[i][j - 1] != '1')
		{
			printf("Map error : Borders of the map MUST be walls.");
			game_over(info, 0);
		}
		j = 0;
		i++;
	}
	check_walls_1(info, i);
}

void	check_walls_1(t_mlx *info, int i)
{
	int	j;

	j = 0;
	while (info->m[i - 1][j])
	{
		if (info->m[i - 1][j] != '1')
		{
			printf("Map error : Borders of the map MUST be walls.");
			game_over(info, 0);
		}
		j++;
	}
}

void	check_doublons(t_mlx *info, char c)
{
	int	i;
	int	j;
	int	nb_c;	

	i = 0;
	j = 0;
	nb_c = 0;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
		{
			if (info->m[i][j] == c)
			{
				nb_c ++;
				if (nb_c > 1)
				{
					printf("Map error:more than 1 exit or player in the map.");
					game_over(info, 0);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_no_item(t_mlx *info, char c)
{
	int	i;
	int	j;
	int	nb_c;

	i = 0;
	j = 0;
	nb_c = 0;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
		{
			if (info->m[i][j] == c)
				nb_c ++;
			j++;
		}
		j = 0;
		i++;
	}
	if (nb_c == 0)
	{
		printf("Map error:0 player and/or exit and/or keys in the map.");
		game_over(info, 0);
	}
}

void	check_map_reactangle(t_mlx *info)
{
	int	i;
	int	j;
	int	str_len;

	i = 1;
	j = 0;
	str_len = 0;
	while (info->m[0][str_len] != '\n' && info->m[0][str_len] != '\0')
		str_len++;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
			j++;
		if (j != str_len)
		{
			printf("Map error:the map is not a rectangle");
			game_over(info, 0);
		}
		j = 0;
		i++;
	}
}
