/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:16:56 by slord             #+#    #+#             */
/*   Updated: 2022/08/17 16:57:48 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start(t_mlx *info)
{
	img_init(info);
	map_checker(info);
	trouver_position_p(info);
	trouver_position_m(info);
	find_nb_keys(info);
	info->nb_move = 0;
	draw_map(info);
	mlx_hook(info->window, 2, 0, validate, info);
	mlx_hook(info->window, 17, 0, game_over, info);
}

void	check_dir(char *path)
{
	void	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		printf("Map error: The map file is a directory");
		closedir(dir);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	info;

	if (argc == 2)
	{
		if (compare_ber(argv[1], ".ber") == 0)
		{
			printf("Map error: The map file is not a .ber");
			exit(0);
		}
		check_dir(argv[1]);
		read_map(argv, &info);
	}
	else
	{
		printf("Error:the game takes 1 argument only.");
		exit(0);
	}
	info.mlx_pointer = mlx_init();
	info.window = mlx_new_window(info.mlx_pointer, ft_strlen(info.m[0])
			* 56 -56, map_height(argv) * 56, "La pouliche ardente");
	start(&info);
	mlx_loop(info.mlx_pointer);
}
