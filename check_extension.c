/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:12:35 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:12:39 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	maximum(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	red_cross(int key, t_fdf *util)
{
	(void)key;
	(void)util;
	exit(0);
}

void	exit_message(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

int	file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_extension(char *fn, char *fm)
{
	int	fn_len;
	int	fm_len;

	if (!(file_exists(fn)))
		return (0);
	fn_len = ft_strlen(fn);
	fm_len = ft_strlen(fm);
	if (!(fm_len == 4) && !(fn_len > 4))
		return (0);
	return (*(fn + fn_len - 1) == *(fm + fm_len - 1)
		&& *(fn + fn_len - 2) == *(fm + fm_len - 2)
		&& *(fn + fn_len - 3) == *(fm + fm_len - 3)
		&& *(fn + fn_len - 4) == *(fm + fm_len - 4));
}
