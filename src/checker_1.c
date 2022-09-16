/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:17:39 by slord             #+#    #+#             */
/*   Updated: 2022/08/09 16:42:15 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_bad_token(t_mlx *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->m[i] != NULL)
	{
		while (info->m[i][j] != '\n' && info->m[i][j] != '\0')
		{
			if (info->m[i][j] == '0' || info->m[i][j] == '1' ||
					info->m[i][j] == 'C' || info->m[i][j] == 'E'
							|| info->m[i][j] == 'P')
				j++;
			else
			{
				printf("\nMap error:0 There is invalid tokens in the map.");
				game_over(info, 1);
			}
		}
		j = 0;
		i++;
	}
}

int	compare_ber(char *path, char *ber)
{
	int		i;
	int		j;

	j = 3;
	i = 0;
	while (path[i])
		i++;
	while (j >= 0)
	{
		i--;
		if (path[i] != ber[j])
			return (0);
		j--;
	}
	return (1);
}

int	game_over(t_mlx *info, int exit_code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (exit_code != 0)
	{
		mlx_destroy_image(info->mlx_pointer, info->key);
		mlx_destroy_image(info->mlx_pointer, info->wall);
		mlx_destroy_image(info->mlx_pointer, info->door);
		mlx_destroy_image(info->mlx_pointer, info->player1);
		mlx_destroy_image(info->mlx_pointer, info->pouliche);
		mlx_destroy_image(info->mlx_pointer, info->floor);
		mlx_destroy_window(info->mlx_pointer, info->window);
	}
	while (info->m[i] != NULL)
	{
		free (info->m[i]);
		i++;
	}
	free(info->m[i]);
	free(info->m);
	exit(exit_code);
}

void	map_checker(t_mlx *info)
{
	check_walls(info);
	check_doublons(info, 'P');
	check_no_item(info, 'E');
	check_no_item(info, 'P');
	check_no_item(info, 'C');
	check_map_reactangle(info);
	check_bad_token(info);
}
