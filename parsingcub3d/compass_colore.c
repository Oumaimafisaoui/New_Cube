/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_colore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:37 by ataji             #+#    #+#             */
/*   Updated: 2023/01/19 16:29:43 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkrgb(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "F"))
	{
		if (checkcoloref(data, elements) == false)
			return (false);
		data->f++;
	}
	if (!ft_strcmp(elements[0], "C"))
	{
		if (checkcolorec(data, elements) == false)
			return (false);
		data->c++;
	}
	return (true);
}

bool	checkfile(char **elements)
{
	int		fd;
	size_t	size;

	fd = open(elements[1], O_RDONLY);
	if (fd < 0)
	{
		perror ("ERROR ");
		return (false);
	}
	size = ft_strlen(elements[1]);
	if (elements[1][size - 1] != 'm' || elements[1][size - 2] != 'p'
		|| elements[1][size - 3] != 'x' || elements[1][size - 4] != '.')
	{
		printf(ERRIMGNAME);
		return (false);
	}
	close (fd);
	return (true);
}

bool	checknumbers(char **colors)
{
	int	i;

	i = -1;
	if (countecolors(colors) != 3)
		return (printf(ERRNUMCOLOR), false);
	if (ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	if (ft_atoi(colors[1]) < 0 || ft_atoi(colors[1]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	if (ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	return (true);
}

bool	checkcoloref(t_data *data, char **elements)
{
	int		i;
	int		countcomma;

	countcomma = 0;
	i = -1;
	while (elements[1] && elements[1][++i])
		if (elements[1][i] == ',')
			countcomma++;
	if (countcomma != 2)
		return (printf(ERRSYNCOLOR), false);
	data->floor = ft_split(elements[1], ',');
	return (checknumbers(data->floor));
}

bool	checkcolorec(t_data *data, char **elements)
{
	int		i;
	int		countcomma;

	countcomma = 0;
	i = -1;
	while (elements[1] && elements[1][++i])
		if (elements[1][i] == ',')
			countcomma++;
	if (countcomma != 2)
		return (printf(ERRSYNCOLOR), false);
	data->ceil = ft_split(elements[1], ',');
	return (checknumbers(data->ceil));
}
