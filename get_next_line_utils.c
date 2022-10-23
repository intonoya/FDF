/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:46:35 by intonoya          #+#    #+#             */
/*   Updated: 2022/07/10 17:25:38 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	a;
	size_t	b;
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	s = malloc(sizeof (char) * (a + b + 1));
	while (j < a)
		s[i++] = s1[j++];
	j = 0;
	while (j < b)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{	
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}		
}

void	*ft_calloc(size_t m, size_t n)
{
	char	*ptr;

	ptr = malloc(m * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, m * n);
	return (ptr);
}
