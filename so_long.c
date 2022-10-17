/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:36:02 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 17:05:24 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	read_map(t_mlx *mlx, char *path)
{
	char	*temp;

	mlx->str_map = ft_init(path);
	if (mlx->str_map == NULL)
		error_control("Empty map\n");
	temp = ft_strtrim(mlx->str_map, "\n");
	free (mlx->str_map);
	mlx->str_map = temp;
}

void	set_and_check(t_mlx *mlx)
{
	mlx->map_row = count_row(mlx->str_map);
	mlx->map_col = count_col(mlx->str_map);
	check_map(mlx->str_map, mlx->map_col);
	mlx->map = ft_split(mlx->str_map, '\n');
	check_wall(mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		i;

	i = 0;
	if (argc != 2)
		error_control("Map missing\n");
	check_ber(argv[1]);
	read_map(&mlx, argv[1]);
	set_and_check(&mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.img = (t_img *)malloc(sizeof(t_img) * 8);
	image_up(mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, mlx.map_col * 32,
			mlx.map_row * 32, "so_long");
	draw_map(&mlx);
	mlx.count = 0;
	mlx.game_status = 1;
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_window2, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
