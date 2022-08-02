/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:16:56 by slord             #+#    #+#             */
/*   Updated: 2022/08/01 19:49:49 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	info;

	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
	{
		printf("Map error: The map file is not a .ber");
		game_over(&info, 0);
	}
	if (argc == 2)
		read_map(argv, &info);
	else
	{
		printf("Error:the game takes 1 argument only.");
		game_over(&info, 0);
	}
	info.mlx_pointer = mlx_init();
	info.window = mlx_new_window(info.mlx_pointer, 2000, 1000,
			"La pouliche ardente");
	img_init(&info);
	map_checker(&info);
	trouver_position_p(&info);
	trouver_position_m(&info);
	draw_map(&info);
	find_nb_keys(&info);
	mlx_hook(info.window, 2, 0, validate, &info);
	mlx_loop(info.mlx_pointer);
}
