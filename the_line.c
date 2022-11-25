/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:29:34 by intonoya          #+#    #+#             */
/*   Updated: 2022/11/23 17:32:42 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

char	*get_line(char *str, t_line *the_line)
{
	int	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	the_line->ptr = malloc(sizeof(char) * (i + 1));
	if (!the_line->ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		the_line->ptr[i] = str[i];
		i++;
	}
	the_line->ptr[i] = 0;
	return (the_line->ptr);
}

static char	*next_line(char *str)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * 1);
	ptr[0] = 0;
	free(str);
	return (ptr);
}

static int	newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*read_line(char *str, int fd, t_line *the_line)
{
	int	i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, the_line->buff, 1);
		if (i == -1)
		{
			free(the_line->buff);
			return (NULL);
		}
		the_line->buff[i] = 0;
		the_line->tmp = str;
		if (!the_line->tmp)
		{
			the_line->tmp = malloc(sizeof(char) * 1);
			the_line->tmp[0] = 0;
		}
		str = ft_strjoin(the_line->tmp, the_line->buff);
		free(the_line->tmp);
		if (newline(str) == 1)
			break ;
	}
	free(the_line->buff);
	return (str);
}

char	*grab_line(int fd)
{
	static char	*str;
	t_line		the_line;

	if (fd < 0)
		return (NULL);
	the_line.buff = malloc(sizeof(char) * 2);
	if (!the_line.buff)
		return (NULL);
	str = read_line(str, fd, &the_line);
	if (!str)
		return (NULL);
	the_line.line = get_line(str, &the_line);
	str = next_line(str);
	return (the_line.line);
}
