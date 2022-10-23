/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:19:23 by intonoya          #+#    #+#             */
/*   Updated: 2022/10/23 17:40:13 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <math.h>

int     mmax(float a, float b)
{
    return(a > b ? a : b);
}

void    make_isometric(float *x, float *y, int z, double angle)
{
    *x = (*x - *y) * cos(angle);
    *y = (*x + *y) * sin(angle) - z;
}

void    zoom1(float *x, float *y, float *x1, fdf *util)
{
    *x *= util->unitsize;
    *y *= util->unitsize;
    *x1 *= util->unitsize;
}

void    zoom2(float *y1, int *z, int *z1, fdf *util)
{
    *y1 *= util->unitsize;
    *z *= util->z_scale;
    *z1 *= util->z_scale;
}

void    draw_the_line(float x, float y, float x1, float y1, fdf *util)
{

    float       x_step;
    float       y_step;
    int         max;
    int         z;
    int         z1;

    z = util->z_matrix[(int)y][(int)x];
    z1 = util->z_matrix[(int)y1][(int)x1];
    zoom1(&x, &y, &x1, util); //zoom withunit size
    zoom2(&y1, &z, &z1, util);//zoom with unit size
    util->color = (z || z1) ? 0x4f039a : 0xffffff;//colour
    make_isometric(&x, &y, z, util->angle);//the angle
    make_isometric(&x1, &y1, z1, util->angle);//the angle
    x += util->shiftx;
    y += util->shifty;
    x1 += util->shiftx;
    y1 += util->shifty;
    x_step = x1 - x;//calculate the steps(65 - 75)
    y_step = y1 - y;
    max = mmax(fabsf(x_step), fabsf(y_step));
    x_step /= max;
    y_step /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(util->mlx_ptr, util->win_ptr, x, y, util->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *util)
{
    int     i;
    int     j;

    i = 0;
    while(i < util->height)
    {
        j = 0;
        while(j < util->width)
        {
            if(j < util->width - 1)
                draw_the_line(j, i, j + 1, i, util);
            if(i < util->height - 1)
                draw_the_line(j, i, j, i + 1, util);
            j++;
        }
        i++;
    }
    mlx_string_put(util->mlx_ptr, util->win_ptr, 5, 5, 0x00FAFF, "Zoom In(+) Zoom Out(-) Up(up button) Down(down button) Right(right button) Left(left button))");
    mlx_string_put(util->mlx_ptr, util->win_ptr, 5, 25, 0x00FAFF, "Angle P(4) Angle N(6) Scale P(8) Scale N(2)");
}    