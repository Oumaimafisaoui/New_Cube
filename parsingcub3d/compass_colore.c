/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_colore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:37 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 14:12:17 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkrgb(t_data *data, char *elements, char *colors)
{
	if (!ft_strcmp(elements, "F"))
		checkcoloref(data, colors);
	if (!ft_strcmp(elements, "C"))
		checkcolorec(data, colors);
	return (true);
}

bool	checkfile(char *elements)
{
	int		fd;
	size_t	size;

	fd = open(elements, O_RDONLY);
	if (fd < 0)
		all_errors(ERRFILE);
	size = ft_strlen(elements);
	if (elements[size - 1] != 'm' || elements[size - 2] != 'p'
		|| elements[size - 3] != 'x' || elements[size - 4] != '.')
		all_errors(ERRIMGNAME);
	close (fd);
	return (true);
}

bool	checknumbers(t_data *data, char **colors)
{
	int	i;

	i = -1;
	(void)data;
	if (countecolors(colors) != 3)
		all_errors(ERRNUMCOLOR);
	if (ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255)
		all_errors(ERRSYNCOLOR);
	if (ft_atoi(colors[1]) < 0 || ft_atoi(colors[1]) > 255)
		all_errors(ERRSYNCOLOR);
	if (ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255)
		all_errors(ERRSYNCOLOR);
	return (true);
}

bool	checkcoloref(t_data *data, char *elements)
{
	int		i;
	int		countcomma;

	countcomma = 0;
	i = -1;
	while (elements && elements[++i])
		if (elements[i] == ',')
			countcomma++;
	if (countcomma != 2)
		all_errors(ERRSYNCOLOR);
	data->floor = ft_split(elements, ',');
	return (checknumbers(data, data->floor));
}

bool	checkcolorec(t_data *data, char *elements)
{
	int		i;
	int		countcomma;

	countcomma = 0;
	i = -1;
	while (elements && elements[++i])
		if (elements[i] == ',')
			countcomma++;
	if (countcomma != 2)
		all_errors(ERRSYNCOLOR);
	data->ceil = ft_split(elements, ',');
	return (checknumbers(data, data->ceil));
}
