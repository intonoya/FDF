/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:45:02 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/08 17:15:56 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_fdf *util)
{
	int	i;

	i = 0;
	while (i < util->height)
	{
		free(util->z_matrix[i]);
		i++;
	}
	free(util->z_matrix);
}

int	main(int argc, char **argv)
{
	t_fdf	util;

	if (argc != 2)
		exit_message("Arguments Error!\n");
	util.fd = open(argv[1], O_RDONLY);
	if (util.fd < 0 || !check_extension(argv[1], ".fdf"))
		exit_message("File does not exist!\n");
	util.shiftx = WIN_W / 2;
	util.shifty = WIN_H / 2 - 300;
	util.isom = 1;
	util.z_scale = 1;
	util.angle = 0.8;
	read_map(argv[1], &util);
	zoom(&util);
	util.mlx_ptr = mlx_init();
	util.win_ptr = mlx_new_window(util.mlx_ptr, WIN_W, WIN_H, "fdf");
	draw(&util);
	mlx_hook(util.win_ptr, 17, (1L << 17), red_cross, &util);
	mlx_key_hook(util.win_ptr, key_pressed, &util);
	mlx_loop(util.mlx_ptr);
	return (0);
}
