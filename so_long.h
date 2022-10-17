/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:36:30 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 16:46:32 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		line_length;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*img;
	int		x;
	int		y;
	int		count;
	char	*str_map;
	char	**map;
	int		map_col;
	int		map_row;
	int		hero_x;
	int		hero_y;
	int		food;
	int		portal_x;
	int		portal_y;
	int		game_status;
}			t_mlx;

char	**ft_split(char const *s, char c);
char	*ft_init(char *path);
int		count_col(char *str_map);
int		count_row(char *str_map);
void	check_map(char *str_map, int map_col);
void	move_right(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	draw_map(t_mlx *mlx);
int		check_wall(t_mlx *mlx);
int		close_window(int keycode, t_mlx *mlx);
int		check_rectangle(char *str_map, int map_col);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	image_up(t_mlx mlx);
int		check_ber(char *path);
void	add_image(t_mlx mlx, char *path, int i);
void	error_control(char *msj);
int		key_hook(int keycode, t_mlx *mlx);
int		close_window(int keycode, t_mlx *mlx);
int		close_window2(t_mlx *mlx);
char	*ft_strtrim(char const *s1, char *set);

#endif
