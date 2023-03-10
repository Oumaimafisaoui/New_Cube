/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:31:02 by ataji             #+#    #+#             */
/*   Updated: 2023/02/20 11:59:15 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	countdoublepoint(char **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

bool	check_arguments(int numofargs, char *mapname)
{
	char	**lastmap;
	size_t	len;

	lastmap = NULL;
	len = 0;
	if (numofargs != 2)
		all_errors(ERRARGUMENTS);
	if (check_point(mapname) == true)
	{
		lastmap = ft_split(mapname, '.');
		if (ft_strcmp(lastmap[1], "cub"))
			return (printf(ERRNAME), false);
	}
	else
		all_errors(ERRNAME);
	ft_free(lastmap);
	return (true);
}

bool	readfromfile(char *mapname, t_data *data)
{
	int		fd;

	data->i = -1;
	data->countlines = countlines(mapname);
	if (data->countlines == -1)
		all_errors(ERREMPTY);
	data->allmap = (char **)malloc(sizeof(char *) * (data->countlines + 1));
	if (!data->allmap)
		all_errors(ERRALLOC);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		all_errors(ERRFILE);
	while (++data->i < data->countlines)
		data->allmap[data->i] = get_next_line(fd);
	data->allmap[data->i] = NULL;
	close (fd);
	return (true);
}

bool	parsemap(t_data *data)
{
	parsefirstofmap(data);
	parsesecondofmap(data);
	parsecharsecondmap(data);
	return (true);
}

bool	allparsing(int ac, char **av, t_data *data)
{
	check_arguments(ac, av[1]);
	readfromfile(av[1], data);
	data->countfirstlines = countlinesfirstmap(data);
	data->countsecondlines = countlinessecondmap(data);
	dividingmap(data);
	parsemap(data);
	return (true);
}
