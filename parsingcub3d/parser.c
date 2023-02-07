/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:54:51 by ataji             #+#    #+#             */
/*   Updated: 2023/02/07 19:16:30 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checktexture(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "WE"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->we++;
	}
	if (!ft_strcmp(elements[0], "SO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->so++;
	}
	if (!ft_strcmp(elements[0], "NO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->no++;
	}
	if (!ft_strcmp(elements[0], "EA"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->ea++;
	}
	return (true);
}

void	settexture(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "EA"))
		data->texture[EA] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "WE"))
		data->texture[WE] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "SO"))
		data->texture[SO] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "NO"))
		data->texture[NO] = ft_strdup(elements[1]);
}

bool	checkkeys(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "WE") || !ft_strcmp(elements[0], "SO")
		|| !ft_strcmp(elements[0], "NO") || !ft_strcmp(elements[0], "EA"))
	{
		settexture(data, elements);
		if (checktexture(data, elements) == false)
			return (false);
		data->counter++;
	}
	else if (!ft_strcmp(elements[0], "F") || !ft_strcmp(elements[0], "C"))
	{
		if (checkrgb(data, elements) == false)
			return (false);
		data->counter++;
	}
	else
	{
		printf(ERRSYNMAP);
		return (false);
	}
	return (true);
}

bool	checkplayerstart(t_data *data)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = -1;
	while (data->secondlines[++i])
	{
		j = -1;
		while (data->secondlines[i][++j])
		{
			if (data->secondlines[i][j] == 'N' || data->secondlines[i][j] == 'S'
				|| data->secondlines[i][j] == 'W'
					|| data->secondlines[i][j] == 'E')
				player++;
		}
	}
	if (player != 1)
		return (printf(PLAYERSTART), false);
	return (true);
}

bool	parsecharsecondmap(t_data *data)
{
	int		i;
	int		j;
	char	helper;

	i = -1;
	while (data->secondlines[++i])
	{
		j = -1;
		while (data->secondlines[i][++j])
		{
			helper = data->secondlines[i][j];
			if (helper != '1' && helper != '0' && helper != 'N' && helper != 'W'
				&& helper != 'E' && helper != 'S' && helper != ' ')
				return (printf(INTRUDER), false);
		}
	}
	return (true);
}
