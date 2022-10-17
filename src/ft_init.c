/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:43:21 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 16:44:55 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_init(char *path)
{
	int		fd;
	char	*line;
	int		exit;
	char	*str_map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_control("Cannot read the map\n");
	line = NULL;
	exit = 0;
	str_map = NULL;
	while (!exit)
	{
		line = get_next_line(fd);
		if (!line)
			exit = 1;
		else
		{
			str_map = ft_strjoin(str_map, line);
			free (line);
		}
	}
	return (str_map);
}

int	count_col(char *str_map)
{
	int	count;

	count = 0;
	while (str_map[count] != '\n')
		count++;
	return (count);
}

int	count_row(char *str_map)
{
	int	count;
	int	map_row;

	count = 0;
	map_row = 0;
	while (str_map[count])
	{
		if (str_map[count] != '\n')
			count++;
		else
		{
			map_row++;
			count++;
		}
	}
	map_row++;
	return (map_row);
}

void	add_image(t_mlx mlx, char *path, int i)
{
	int	img_width;
	int	img_height;

	mlx.img[i].img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, path, &img_width,
			&img_height);
	mlx.img[i].addr = (int *)mlx_get_data_addr(mlx.img[i].img_ptr,
			&mlx.img[i].bpp, &mlx.img[i].line_length, &mlx.img[i].endian);
}

void	image_up(t_mlx mlx)
{
	add_image(mlx, "img/wall.xpm", 0);
	add_image(mlx, "img/black.xpm", 1);
	add_image(mlx, "img/ghost.xpm", 2);
	add_image(mlx, "img/pacman.xpm", 3);
	add_image(mlx, "img/portal.xpm", 4);
	add_image(mlx, "img/ghost_up.xpm", 5);
	add_image(mlx, "img/ghost_down.xpm", 6);
	add_image(mlx, "img/ghost_left.xpm", 7);
}
