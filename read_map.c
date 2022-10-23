#include "fdf.h"

int	ft_count(char const *s, char sep)
{
	int	i;
	int	count;

	if (s == 0 || s[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (s[0] != sep)
		count++;
	while (s[i])
	{
		if (s[i] != sep && s[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

int get_height(char *file_name)
{
    char    *line;
    int     fd;
    int     height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    line = get_next_line(fd);
    while (line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (height);
}

int get_witdth(char *file_name)
{
    char    *line;
    int     fd;
    int     width;
    fd = open(file_name, O_RDONLY, 0);
    line = get_next_line(fd);
    width = ft_count(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    fill_matrix(int *z_line, char *line)
{
    char    **num;
    int     i;

    num = ft_split(line, ' ');
    i = 0;
    while (num[i])
    {
        z_line[i] = ft_atoi(num[i]);
        free(num[i]);
        i++;
    }    
    free(num);
}

void    read_map(char *file_name, fdf *data)
{
    int     i;
    int     fd;
    char    *line;
    
    data->height = get_height(file_name);
    data->width = get_witdth(file_name);
    data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        fill_matrix(data->z_matrix[i], line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    close(fd);
    data->z_matrix[i] = NULL;
}