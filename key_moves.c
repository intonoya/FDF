#include "fdf.h"

int     key_pressed(int key, fdf *util)
{
    if (key == 53)
		exit(0);
    if (key == 126)
        util->shifty -= 15;
    else if(key == 125)
        util->shifty += 15;
    else if(key == 124)
        util->shiftx += 15;
    else if(key == 123)
        util->shiftx -= 15;
    else if (key == 86 || key == 21)
        util->angle += 0.05;
    else if (key == 88 || key == 22)
        util->angle -= 0.05;
    else if (key == 91 || key == 28)
		util->z_scale += 1;
	else if (key == 84 || key == 19)
		util->z_scale -= 1;
    else if (key == 69 || key == 24)
        util->unitsize += 1;
    else if (key == 78 || key == 27)
        util->unitsize -= 1;
    mlx_clear_window(util->mlx_ptr, util->win_ptr);
    draw(util);
    return(0);
}