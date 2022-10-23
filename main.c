/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:45:02 by intonoya          #+#    #+#             */
/*   Updated: 2022/10/13 20:34:45 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	fdf	*util;

	util = (fdf *)malloc(sizeof(fdf));
    if (argc == 2)
    {
        if (!(check_extension(argv[1], ".fdf")))
            exit_message("Invalid file format");
        read_map(argv[1], util);

        util->unitsize = 15;
        util->angle = 0.8;
        util->z_scale = 1;
        util->mlx_ptr = mlx_init();
        util->win_ptr = mlx_new_window(util->mlx_ptr, 3000, 1000, "FDF");

        draw(util);
        mlx_key_hook(util->win_ptr, key_pressed, util);
        mlx_hook(util->win_ptr, 17, (1L << 17), red_cross, &util);
        mlx_loop(util->mlx_ptr);
    }
    else
        exit_message("Argument Error");
    free(util);
    return (0);
}	
