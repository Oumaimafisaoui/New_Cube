/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:18:36 by ataji             #+#    #+#             */
/*   Updated: 2023/02/07 20:04:31 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_back_slash_n(char *store_line)
{
	int	i;

	i = -1;
	if (store_line)
		while (store_line[++i])
			if (store_line[i] == '\n')
				return (1);
	return (0);
}

char	*get_line_file(char *static_line, int fd)
{
	int		rd_bytes;
	char	*store_line;

	store_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!store_line)
		return (NULL);
	while (!get_back_slash_n(static_line))
	{
		rd_bytes = read(fd, store_line, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(store_line), NULL);
		if (rd_bytes == 0)
			break ;
		store_line[rd_bytes] = 0;
		static_line = ft_strjoin(static_line, store_line);
	}
	if (store_line)
		free(store_line);
	return (static_line);
}

char	*rest_line(char *static_line)
{
	int		count;
	char	*tab;
	int		size;

	count = 0;
	if (!static_line)
		return (NULL);
	while (static_line[count] && static_line[count] != '\n')
		count++;
	if (!static_line[count])
		return (free(static_line), NULL);
	size = ft_strlen(static_line) - count;
	if (size == 0)
		size = 1;
	tab = (char *)malloc(size);
	if (!tab)
		return (free(static_line), NULL);
	if (size > 1)
		ft_memmove(tab, &static_line[count + 1], size - 1);
	tab[size - 1] = '\0';
	if (ft_strlen(tab) == 0)
		return (free(static_line), free(tab), NULL);
	return (free(static_line), tab);
}

char	*get_line_static(char *static_line)
{
	int		i;
	char	*line;

	i = 0;
	while (static_line[i] && static_line[i] != '\n')
		i++;
	if (static_line[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memmove(line, static_line, i);
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_line = get_line_file(static_line, fd);
	if (!static_line || (static_line && *static_line == '\0'))
		return (NULL);
	line = get_line_static(static_line);
	static_line = rest_line(static_line);
	return (line);
}