/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:45:49 by mrollo            #+#    #+#             */
/*   Updated: 2022/05/25 17:52:06 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void) keycode;
	(void) mlx;
	if (keycode == 2)
		move_right(mlx);
	if (keycode == 1)
		move_down(mlx);
	if (keycode == 0)
		move_left(mlx);
	if (keycode == 13)
		move_up(mlx);
	if (keycode == 53)
		close_window(53, mlx);
	if (mlx->food == 0 && mlx->game_status == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[4].img_ptr, mlx->portal_x, mlx->portal_y);
	if (mlx->food == 0 && mlx->map[mlx->hero_y][mlx->hero_x] == 'E'
		&& mlx->game_status == 1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, (mlx->map_col / 2) * 32,
			(mlx->map_row / 2) * 32, 0x00FF0000, "You win!");
		mlx->game_status = 0;
	}
	return (0);
}
