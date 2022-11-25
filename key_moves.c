/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:16:36 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:16:40 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	key_pressed1(int key, t_fdf *util)
{
	if (key == 34)
	{
		if (util->isom == 1)
			util->isom -= 1;
		else if (util->isom == 0)
			util->isom += 1;
	}
	else if (key == 86 || key == 21)
		util->angle += 0.05;
	else if (key == 88 || key == 22)
		util->angle -= 0.05;
}

int	key_pressed(int key, t_fdf *util)
{
	if (key == 53)
		exit(0);
	if (key == 126)
		util->shifty -= 15;
	else if (key == 125)
		util->shifty += 15;
	else if (key == 124)
		util->shiftx += 15;
	else if (key == 123)
		util->shiftx -= 15;
	else if (key == 91 || key == 28)
		util->z_scale += 1;
	else if (key == 84 || key == 19)
		util->z_scale -= 1;
	else if (key == 69 || key == 24)
		util->unitsize += 1;
	else if (key == 78 || key == 27)
		util->unitsize -= 1;
	key_pressed1(key, util);
	mlx_destroy_image(util->mlx_ptr, util->img_ptr);
	util->img_ptr = mlx_xpm_file_to_image(util->mlx_ptr, util->path, \
		&util->w, &util->h);
	draw(util);
	return (0);
}
