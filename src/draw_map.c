/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:26:12 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/08 19:46:02 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	put_img_p(t_mlx *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
		mlx->img[2].img_ptr, i * 32, j * 32);
	mlx->x = i * 32;
	mlx->y = j * 32;
	mlx->hero_x = i;
	mlx->hero_y = j;
	mlx->map[j][i] = '0';
}

void	put_img_e(t_mlx *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
		mlx->img[1].img_ptr, i * 32, j * 32);
	mlx->portal_x = i * 32;
	mlx->portal_y = j * 32;
}

void	put_img_c(t_mlx *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
		mlx->img[3].img_ptr, i * 32, j * 32);
	mlx->food++;
}

void	draw_map(t_mlx *mlx)
{
	int	j;
	int	i;

	j = -1;
	while (++j < mlx->map_row)
	{
		i = -1;
		while (++i < mlx->map_col)
		{
			if (mlx->map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img[0].img_ptr, i * 32, j * 32);
			else if (mlx->map[j][i] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img[1].img_ptr, i * 32, j * 32);
			else if (mlx->map[j][i] == 'P')
				put_img_p(mlx, i, j);
			else if (mlx->map[j][i] == 'C')
				put_img_c(mlx, i, j);
			else if (mlx->map[j][i] == 'E')
				put_img_e(mlx, i, j);
		}
	}
}
