/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetwopartsofmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:10:20 by ataji             #+#    #+#             */
/*   Updated: 2023/01/14 23:04:53 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initdirectioncolor(t_data *data)
{
	data->counter = 0;
	data->c = 0;
	data->f = 0;
	data->we = 0;
	data->ea = 0;
	data->so = 0;
	data->no = 0;
	data->x = 0;
}

bool	checkfirstofmap(t_data *data)
{
	if (data->we < 1 || data->no < 1 || data->ea < 1 || data->so < 1
		|| data->f < 1 || data->c < 1)
		return (printf(MISSKEY), false);
	if (data->we > 1 || data->no > 1 || data->ea > 1 || data->so > 1
		|| data->f > 1 || data->c > 1)
		return (printf(ERRKEYS), false);
	if (data->counter > 6)
		return (printf(ERRINTR), false);
	return (true);
}

bool	parsefirstofmap(t_data *data)
{
	char	**texturecolor;

	initdirectioncolor(data);
	texturecolor = (char **)malloc(sizeof(char *) * 7);
	if (!texturecolor)
		return (false);
	while (data->x < data->countfirstlines)
	{
		while (data->firstlines[data->x]
			&& data->firstlines[data->x][0] == '\n')
			data->x++;
		if (data->x < data->countfirstlines)
		{
			if (countargs(data->firstlines[data->x]) != 2)
				return (printf(ERRFIRSTMAP), false);
			texturecolor = ft_split(data->firstlines[data->x], ' ');
			texturecolor[1] = ft_strcpy(texturecolor[1], texturecolor[1]);
			if (checkkeys(data, texturecolor) == false)
				return (false);
			ft_free(texturecolor);
		}
		data->x++;
	}
	return (checkfirstofmap(data));
}

bool	parsesecondofmap(t_data *data)
{
	int		i;
	int		j;
	size_t	len;

	i = -1;
	data->biglength = 0;
	data->smalllength = SIZE_MAX;
	while (data->secondlines[++i])
	{
		j = 0;
		if (i < data->countsecondlines)
			data->secondlines[i] = ft_strcpy(data->secondlines[i],
					data->secondlines[i]);
		len = ft_strlen(data->secondlines[i]);
		if (len > data->biglength)
			data->biglength = len;
		if (len < data->smalllength)
			data->smalllength = len;
	}
	addspaces(data);
	if (checkchar(data) == false)
		return (false);
	if (checkplayerstart(data) == false)
		return (false);
	return (true);
}
