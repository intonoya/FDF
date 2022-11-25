/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:05:27 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:17:59 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	setting(t_fdf *util)
{
	int	z;
	int	z1;

	z = util->z_matrix[(int)util->y][(int)util->x] * util->z_scale;
	z1 = util->z_matrix[(int)util->y1][(int)util->x1] * util->z_scale;
	util->x *= util->unitsize;
	util->y *= util->unitsize;
	util->x1 *= util->unitsize;
	util->y1 *= util->unitsize;
	if (util->isom == 1)
	{
		isometric(&util->x, &util->y, z, util);
		isometric(&util->x1, &util->y1, z1, util);
	}
	util->x += util->shiftx;
	util->y += util->shifty;
	util->x1 += util->shiftx;
	util->y1 += util->shifty;
}

void	steps(t_fdf *util)
{
	float	x_step;
	float	y_step;
	int		max;

	setting(util);
	x_step = util->x1 - util->x;
	y_step = util->y1 - util->y;
	max = maximum(fabsf(x_step), fabsf(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(util->x1 - util->x) || (int)(util->y1 - util->y))
	{
		my_pixel_put(util);
		util->x += x_step;
		util->y += y_step;
	}
}

void	join_two_points(float x, float y, int tmp, t_fdf *util)
{
	util->x = x;
	util->y = y;
	util->x1 = util->x;
	util->y1 = util->y + 1;
	if (tmp)
	{
		util->x1 = util->x + 1;
		util->y1 = util->y;
	}
	steps(util);
}

void	draw(t_fdf *util)
{
	int	i;
	int	j;

	i = 0;
	menu(util);
	while (i < util->height)
	{
		j = 0;
		while (j < util->width)
		{
			color(util, j, i);
			if (j < util->width - 1)
				join_two_points(j, i, 1, util);
			if (i < util->height - 1)
				join_two_points(j, i, 0, util);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(util->mlx_ptr, util->win_ptr, util->img_ptr, 0, 0);
}	
