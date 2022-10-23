/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:29 by intonoya          #+#    #+#             */
/*   Updated: 2022/10/11 17:44:03 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>

typedef struct
{
    int         width;
    int         height;
    int         **z_matrix;
    int         unitsize;
    int         color;
    int         z_scale;
    int         shiftx;
    int         shifty;
   	double	    angle;
    void        *mlx_ptr;
    void        *win_ptr;
}               fdf;

int		ft_count(char const *s, char sep);
int		get_height(char *file_name);
int		get_witdth(char *file_name);
void	fill_matrix(int *z_line, char *line);
void	read_map(char *file_name, fdf *data);
int		red_cross(int key, fdf *util);
int		file_exists(char *file);
int		check_extension(char *fn, char *fm);
int     mmax(float a, float b);
void    make_isometric(float *x, float *y, int z, double angle);
void    zoom1(float *x, float *y, float *x1, fdf *util);
void    zoom2(float *y1, int *z, int *z1, fdf *util);
void    draw_the_line(float x, float y, float x1, float y1, fdf *util);
void    draw(fdf *util);
int     key_pressed(int key, fdf *util);
void    exit_message(char *str);

#endif
