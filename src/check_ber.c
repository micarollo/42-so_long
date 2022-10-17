/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:38:03 by mrollo            #+#    #+#             */
/*   Updated: 2022/05/31 15:42:05 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	check_ber(char *path)
{
	int		i;
	int		len;
	char	*ext;

	len = ft_strlen(path);
	if (len >= 5)
	{
		ext = ft_substr(path, (len - 4), 4);
		i = ft_strncmp(ext, ".ber", 4);
		if (i != 0)
		{
			error_control("Your map has to be .ber\n");
			free (ext);
		}
		else
		{
			free (ext);
			return (0);
		}
	}
	else
		error_control("Your map has to be 'name'.ber\n");
	return (0);
}
