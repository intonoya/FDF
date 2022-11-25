/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:29 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:18:32 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W	2000
# define WIN_H	1000
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_line
{
	char	*line;
	char	*buff;
	char	*tmp;
	char	*ptr;
}				t_line;

typedef struct s_fdf
{
	int			width;
	int			height;
	int			pixel;
	int			fd;
	char		*read;
	int			**z_matrix;
	char		**split;
	int			**color;
	int			unitsize;
	int			z_scale;
	int			shiftx;
	int			shifty;
	double		angle;
	char		*path;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	float		x1;
	float		y1;
	int			z1;
	float		x;
	float		y;
	int			z;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			isom;
	int			w;
	int			h;
	int			j;
	int			i;
}				t_fdf;

void	read_map(char *av, t_fdf *util);
void	fill_matrix(int *z_line, char *line);
void	read_map(char *file_name, t_fdf *data);
int		red_cross(int key, t_fdf *util);
int		file_exists(char *file);
int		check_extension(char *fn, char *fm);
int		maximum(float a, float b);
void	draw(t_fdf *util);
int		key_pressed(int key, t_fdf *util);
void	exit_message(char *str);
void	my_pixel_put(t_fdf *util);
char	*get_line(char *str, t_line *the_line);
char	*grab_line(int fd);
void	color(t_fdf *util, int x, int y);
void	menu(t_fdf *util);
void	zoom(t_fdf *util);
void	isometric(float *x, float *y, int z, t_fdf *util);

#endif