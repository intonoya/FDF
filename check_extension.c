
#include "fdf.h"

int		red_cross(int key, fdf *util)
{
	(void)key;
	(void)util;
	exit(0);
}

void    exit_message(char *str)
{
    //write(1, "[fdf]", 7);
    ft_putstr_fd(str, 1);
    write(1, "\n", 1);
    exit(0);
}

int file_exists(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);    
}

int check_extension(char *fn, char *fm)
{
    int fn_len;
    int fm_len;

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