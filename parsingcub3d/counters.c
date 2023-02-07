/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:51:16 by ataji             #+#    #+#             */
/*   Updated: 2023/01/14 23:50:37 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	countargs(char *firstline)
{
	int	i;
	int	check;
	int	counter;

	i = -1;
	counter = 0;
	check = 0;
	while (firstline[++i])
	{
		if (firstline[i] != ' ' && check == 0)
		{
			check = 1;
			counter++;
		}
		else if (firstline[i] == ' ')
			check = 0;
	}
	return (counter);
}

int	countlinesfirstmap(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	counter;

	i = -1;
	counter = 0;
	while (data->allmap[++i])
	{
		j = -1;
		while (data->allmap[i][++j])
		{
			k = 0;
			while (data->allmap[i][k] == ' ')
				k++;
			if (data->allmap[i][k] == '1'
				|| data->allmap[i][k] == '0')
				return (counter);
			if (data->allmap[i][j + 1] == '\0')
				counter++;
		}
	}
	return (counter);
}

int	countlinessecondmap(t_data *data)
{
	int	i;
	int	counter;

	i = data->countfirstlines - 1;
	counter = 0;
	while (data->allmap[++i])
	{
		if (data->allmap[i][0] == '\n')
			break ;
		counter++;
	}
	return (counter);
}

int	countlines(char *mapname)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR ");
		return (-1);
	}
	line = get_next_line(fd);
	if (!line)
		return (printf("ERROR : Empty map\n"), -1);
	count = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		free (line);
		if (!line)
			break ;
		count++;
	}
	close (fd);
	return (count);
}
