/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:51:28 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 14:30:28 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	close_window(int keycode, t_mlx *mlx)
{
	(void) keycode;
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	free (mlx->str_map);
	free (mlx->img);
	exit (1);
	return (0);
}

int	close_window2(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	free (mlx->img);
	exit (1);
	return (0);
}
