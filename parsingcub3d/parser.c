/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:54:51 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 18:11:47 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checktexture(t_data *data)
{
	int	i;

	i = -1;
	while (data->texturecolorkey[++i])
	{
		if (!ft_strcmp(data->texturecolorkey[i], "WE"))
			checkfile(data->texturecolorone[i]);
		if (!ft_strcmp(data->texturecolorkey[i], "SO"))
			checkfile(data->texturecolorone[i]);
		if (!ft_strcmp(data->texturecolorkey[i], "NO"))
			checkfile(data->texturecolorone[i]);
		if (!ft_strcmp(data->texturecolorkey[i], "EA"))
			checkfile(data->texturecolorone[i]);
	}
	return (true);
}

void	settexture(t_data *data, int i)
{
	if (!ft_strcmp(data->texturecolorkey[i], "EA"))
		data->texture[EA] = ft_strdup(data->texturecolorone[i]);
	else if (!ft_strcmp(data->texturecolorkey[i], "WE"))
		data->texture[WE] = ft_strdup(data->texturecolorone[i]);
	else if (!ft_strcmp(data->texturecolorkey[i], "SO"))
		data->texture[SO] = ft_strdup(data->texturecolorone[i]);
	else if (!ft_strcmp(data->texturecolorkey[i], "NO"))
		data->texture[NO] = ft_strdup(data->texturecolorone[i]);
}

bool	checkkeys(t_data *data)
{
	int	i;

	i = -1;
	while (data->texturecolorkey[++i])
	{
		if (!ft_strcmp(data->texturecolorkey[i], "WE")
			|| !ft_strcmp(data->texturecolorkey[i], "SO")
			|| !ft_strcmp(data->texturecolorkey[i], "NO")
			|| !ft_strcmp(data->texturecolorkey[i], "EA"))
		{
			settexture(data, i);
			checktexture(data);
		}
		else if (!ft_strcmp(data->texturecolorkey[i], "F")
			|| !ft_strcmp(data->texturecolorkey[i], "C"))
			checkrgb(data, data->texturecolorkey[i], data->texturecolorone[i]);
		else
			all_errors(ERRSYNMAP);
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
		all_errors(PLAYERSTART);
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
				all_errors(INTRUDER);
		}
	}
	return (true);
}
