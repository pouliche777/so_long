/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:49:25 by slord             #+#    #+#             */
/*   Updated: 2022/08/01 19:20:59 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	fonction qui cree lit la map ligne par ligne et qui creer stock la position
**	des tokens dans un pointeur de pointeur
*/

void	read_map(char **argv, t_mlx *info)
{
	int		fd;
	int		i;
	int		map_h;
	char	*map_tempo;

	i = 0;
	map_h = map_height(argv);
	info->m = malloc(sizeof(char *) * (map_h + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Map error : there is no such file");
		game_over(info, 0);
	}
	while (map_h > 0)
	{
		map_tempo = get_next_line(fd);
		info->m[i] = malloc(sizeof(char) * ft_strlen(map_tempo) + 1);
		info->m[i] = map_tempo;
		i++;
		map_h--;
	}
	info->m[i] = NULL;
	close(fd);
}

int	map_height(char **argv)

{
	int		fd;
	int		i;
	int		height;
	char	c;
	int		read_check;

	i = 0;
	height = 1;
	fd = open(argv[1], O_RDONLY);
	while (height)
	{
		read_check = read(fd, &c, 1);
		if (read_check == 0)
			break ;
		if (read_check < 0)
			return (-1);
		if (c == '\n')
			height++;
	}
	return (height);
}

void	draw_map(t_mlx *info)
{
	put_img(info, info->wall, '1');
	put_img(info, info->floor, '0');
	put_img(info, info->key, 'C');
	put_img(info, info->door, 'E');
	put_img(info, info->player1, 'P');
	put_img(info, info->pouliche, 'M');
}

void	img_init(t_mlx *info)
{
	int	img_height;
	int	img_width;

	info->floor = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/floor.xpm", &img_height, &img_width);
	info->pouliche = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/pouliche.xpm", &img_height, &img_width);
	info->key = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/key.xpm", &img_height, &img_width);
	info->door = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/door.xpm", &img_height, &img_width);
	info->wall = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/wall.xpm", &img_height, &img_width);
	info->player1 = mlx_xpm_file_to_image(info->mlx_pointer,
			"./images/player.xpm", &img_height, &img_width);
}
