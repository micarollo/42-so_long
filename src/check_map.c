/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:46:29 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 17:10:43 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	check_char(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		if (str_map[i] == '0' || str_map[i] == '1' || str_map[i] == 'P'
			|| str_map[i] == 'C' || str_map[i] == '\n' || str_map[i] == 'E')
			i++;
		else
			error_control("Your map has a wrong character\n");
	}
	return (0);
}

static int	second_check(char *str_map)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (str_map[i])
	{
		if (str_map[i] == 'E')
			e++;
		if (str_map[i] == 'C')
			c++;
		if (str_map[i] == 'P')
			p++;
		i++;
	}
	if (e == 1 && c >= 1 && p == 1)
		return (0);
	else
		error_control("Your map needs at least one C and only one E-P\n");
	return (0);
}

int	check_rectangle(char *str_map, int map_col)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str_map[i])
	{
		if (str_map[i] != '\n')
		{
			count++;
			i++;
		}
		else
		{
			if (count == map_col)
			{
				i++;
				count = 0;
			}
			else
				error_control("The map is not a rectangle\n");
		}
	}
	return (0);
}

int	check_wall(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map_row)
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][mlx->map_col - 1] != '1')
			error_control("Your map has to be surrounded by walls\n");
		i++;
	}
	i = 0;
	while (i < mlx->map_col)
	{
		if (mlx->map[0][i] != '1' || mlx->map[mlx->map_row - 1][i] != '1')
			error_control("Your map has to be surrounded by walls\n");
		i++;
	}
	return (0);
}

void	check_map(char *str_map, int map_col)
{
	check_char(str_map);
	second_check(str_map);
	check_rectangle(str_map, map_col);
}
