/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:23:55 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/02 13:30:06 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_backup(char	*text_backup)
{
	int		index;
	int		count;
	char	*new_backup_start;

	index = 0;
	while (*(text_backup + index) && *(text_backup + index) != '\n')
		index++;
	if (!(*(text_backup + index)))
	{
		free(text_backup);
		return (NULL);
	}
	new_backup_start = malloc(sizeof(char) * (ft_strlen(text_backup) - index));
	if (!new_backup_start)
		return (NULL);
	index++;
	count = 0;
	while (*(text_backup + index))
		new_backup_start[count++] = text_backup[index++];
	*(new_backup_start + count) = '\0';
	free(text_backup);
	return (new_backup_start);
}

char	*ft_take_line(char *text_backup)
{
	int		index;
	char	*the_line;

	index = 0;
	if (!(*(text_backup)))
		return (NULL);
	while (*(text_backup + index) && (*(text_backup + index)) != '\n')
		index++;
	the_line = (char *)malloc(sizeof(char) * (index + 2));
	if (!the_line)
		return (NULL);
	index = 0;
	while (*(text_backup + index) && (*(text_backup + index)) != '\n')
	{
		*(the_line + index) = *(text_backup + index);
		index++;
	}
	if (*(text_backup + index) == '\n')
	{
		*(the_line + index) = *(text_backup + index);
		index++;
	}
	*(the_line + index) = '\0';
	return (the_line);
}

char	*ft_read_backup(int fd, char *text_backup)
{
	int		bytes;
	char	*text;

	bytes = 1;
	text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!text)
		return (NULL);
	while ((!(ft_strchr(text_backup, '\n')) && bytes != 0))
	{
		bytes = read(fd, text, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(text);
			return (NULL);
		}
		text[bytes] = '\0';
		text_backup = ft_strjoin(text_backup, text);
	}
	free(text);
	return (text_backup);
}

char	*get_next_line(int fd)
{
	char		*the_line;
	static char	*text_backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text_backup = ft_read_backup(fd, text_backup);
	if (!text_backup)
		return (NULL);
	the_line = ft_take_line(text_backup);
	text_backup = ft_update_backup(text_backup);
	return (the_line);
}
