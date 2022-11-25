/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:19:23 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:17:32 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_pixel_put(t_fdf *util)
{
	char	*dst;

	if (util->x > 0 && util->y > 0 && WIN_W > util->x && \
		WIN_H > util->y)
	{
		dst = util->addr + ((int)util->y * util->size_line + \
			(int)util->x * (util->bpp / 8));
		*(unsigned int *)dst = util->pixel;
	}
}

void	color(t_fdf *util, int x, int y)
{
	if (util->isom == 1 || util->isom == 0)
	{
		if (util->z_matrix[y][x] == 0 && util->color[y][x] == 0)
			util->pixel = 0xFFE300;
		else if (util->z_matrix[y][x] >= 0 && util->color[y][x] > 0)
			util->pixel = util->color[y][x];
		else if (util->z_matrix[y][x] > 0 && util->color[y][x] == 0)
			util->pixel = 0xFF5403;
		else
			util->pixel = 0x125B50;
	}
}

void	zoom(t_fdf *util)
{
	if (util->height < 100 && util->width < 100)
		util->unitsize = 20;
	else
		util->unitsize = 10;
}

void	menu(t_fdf *util)
{
	util->path = "./background.xpm";
	util->img_ptr = mlx_xpm_file_to_image(util->mlx_ptr, util->path, \
		&util->w, &util->h);
	util->addr = mlx_get_data_addr(util->img_ptr, &util->bpp, \
		&util->size_line, &util->endian);
}

void	isometric(float *x, float *y, int z, t_fdf *util)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(util->angle);
	*y = (prev_x + prev_y) * sin(util->angle) - z;
}
