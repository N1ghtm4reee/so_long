/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:25:08 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 12:48:54 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup1(const char *s)
{
	int		len;
	char	*d;
	int		i;

	len = ft_strlen1((char *)s);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	lines_count(int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			get_next_line(-2);
	}
	return (y);
}

char	**parse(int fd, char **av)
{
	char		**map;
	static int	t_y;
	int			y;
	char		*line;

	if (fd == -1)
		exit(11);
	y = lines_count(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	map = malloc(sizeof(char *) * (y + 1));
	line = get_next_line(fd);
	map[t_y++] = line;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			get_next_line(-2);
			break ;
		}
		map[t_y++] = line;
	}
	map[t_y] = NULL;
	return (map);
}
