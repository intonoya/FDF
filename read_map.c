/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:16:50 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/16 20:16:53 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	get_width(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

static int	ft_hex_dec(char *str)
{
	int	len;
	int	base;
	int	rslt;

	len = ft_strlen(str) - 1;
	base = 1;
	rslt = 0;
	while (str[len] && len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
			rslt += (str[len] - 48) * base;
		else if (str[len] >= 'A' && str[len] <= 'F')
			rslt += (str[len] - 55) * base;
		else if (str[len] >= 'a' && str[len] <= 'f')
			rslt += (str[len] - 87) * base;
		base *= 16;
		len--;
	}
	return (rslt);
}

static void	fill_map_helper(int i, t_fdf *util)
{
	int	k;

	k = 0;
	while (util->split[i])
	{
		k = 0;
		util->z_matrix[util->j][i] = ft_atoi(util->split[i]);
		while (util->split[i][k] != ',' && util->split[i][k])
			k++;
		if (util->split[i][k++] == ',')
			util->color[util->j][i] = ft_hex_dec(&util->split[i][k]);
		else
			util->color[util->j][i] = ft_atoi("0");
		free(util->split[i]);
		i++;
	}
	free(util->split);
}

static void	fill_map(t_fdf *util, char *av)
{
	int	i;

	util->j = 0;
	util->fd = open(av, O_RDONLY);
	util->read = grab_line(util->fd);
	while (util->read)
	{
		i = 0;
		util->split = ft_split(util->read, ' ');
		util->width = get_width(util->split);
		util->z_matrix[util->j] = malloc(sizeof(int) * util->width);
		util->color[util->j] = malloc(sizeof(int) * util->width);
		fill_map_helper(i, util);
		free(util->read);
		util->read = grab_line(util->fd);
		util->j++;
	}
	free(util->read);
	close(util->fd);
}

void	read_map(char *av, t_fdf *util)
{
	util->height = 0;
	util->read = grab_line(util->fd);
	if (util->read == 0)
		exit_message("File Error\n");
	while (util->read)
	{
		free(util->read);
		util->read = grab_line(util->fd);
		util->height++;
	}
	free(util->read);
	close(util->fd);
	util->z_matrix = (int **) malloc(sizeof(int *) * util->height + 1);
	util->color = (int **) malloc(sizeof(int *) * util->height + 1);
	fill_map(util, av);
}
