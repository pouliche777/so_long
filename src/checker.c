/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:46:34 by slord             #+#    #+#             */
/*   Updated: 2022/08/01 18:10:26 by slord            ###   ########.fr       */
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
				game_over(info, 1);
			}
			j++;
		}
		if (info->m[i][j - 1] != '1')
		{
			printf("Map error : Borders of the map MUST be walls.");
			game_over(info, 1);
		}
		j = 0;
		i++;
	}
	while (info->m[i - 1][j])
	{
		if (info->m[i - 1][j] != '1')
		{
			printf("Map error : Borders of the map MUST be walls.");
			game_over(info, 1);
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
					printf("\nMap error:more than 1 exit or player in the map.");
					game_over(info, 1);
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
		printf("\nMap error:0 player and/or exit and/or keys in the map.");
		game_over(info, 1);
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
			printf("\nMap error:the map is not a rectangle");
			game_over(info, 1);
		}
		j = 0;
		i++;
	}
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
