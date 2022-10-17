/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:54:36 by mrollo            #+#    #+#             */
/*   Updated: 2022/05/25 17:53:17 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	print_movement(t_mlx *mlx)
{
	mlx->count++;
	ft_putnbr_fd(mlx->count, 1);
	write(1, "\n", 1);
}

void	move_right(t_mlx *mlx)
{
	if ((mlx->map[mlx->hero_y][mlx->hero_x + 1] == '0'
		|| mlx->map[mlx->hero_y][mlx->hero_x + 1] == 'E')
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[2].img_ptr, mlx->x += 32, mlx->y);
		mlx->hero_x++;
		print_movement(mlx);
	}
	else if (mlx->map[mlx->hero_y][mlx->hero_x + 1] == 'C'
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[2].img_ptr, mlx->x += 32, mlx->y);
		mlx->hero_x++;
		mlx->food--;
		mlx->map[mlx->hero_y][mlx->hero_x] = '0';
		print_movement(mlx);
	}
}

void	move_down(t_mlx *mlx)
{
	if ((mlx->map[mlx->hero_y + 1][mlx->hero_x] == '0'
		|| mlx->map[mlx->hero_y + 1][mlx->hero_x] == 'E')
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[6].img_ptr, mlx->x, mlx->y += 32);
		mlx->hero_y++;
		print_movement(mlx);
	}
	else if (mlx->map[mlx->hero_y + 1][mlx->hero_x] == 'C'
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[6].img_ptr, mlx->x, mlx->y += 32);
		mlx->hero_y++;
		mlx->food--;
		mlx->map[mlx->hero_y][mlx->hero_x] = '0';
		print_movement(mlx);
	}
}

void	move_left(t_mlx *mlx)
{
	if ((mlx->map[mlx->hero_y][mlx->hero_x - 1] == '0'
		|| mlx->map[mlx->hero_y][mlx->hero_x - 1] == 'E')
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[7].img_ptr, mlx->x -= 32, mlx->y);
		mlx->hero_x--;
		print_movement(mlx);
	}
	else if (mlx->map[mlx->hero_y][mlx->hero_x - 1] == 'C'
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[7].img_ptr, mlx->x -= 32, mlx->y);
		mlx->hero_x--;
		mlx->food--;
		mlx->map[mlx->hero_y][mlx->hero_x] = '0';
		print_movement(mlx);
	}
}

void	move_up(t_mlx *mlx)
{
	if ((mlx->map[mlx->hero_y - 1][mlx->hero_x] == '0'
		|| mlx->map[mlx->hero_y - 1][mlx->hero_x] == 'E')
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[5].img_ptr, mlx->x, mlx->y -= 32);
		mlx->hero_y--;
		print_movement(mlx);
	}
	else if (mlx->map[mlx->hero_y - 1][mlx->hero_x] == 'C'
		&& mlx->game_status == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[1].img_ptr, mlx->x, mlx->y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img[5].img_ptr, mlx->x, mlx->y -= 32);
		mlx->hero_y--;
		mlx->food--;
		mlx->map[mlx->hero_y][mlx->hero_x] = '0';
		print_movement(mlx);
	}
}
