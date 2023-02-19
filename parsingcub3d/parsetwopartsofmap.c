/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetwopartsofmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:10:20 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 20:12:23 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkduplicate(t_data *data)
{
	int	i;

	i = -1;
	while (data->texturecolorkey[++i])
	{
		if (!ft_strcmp(data->texturecolorkey[i], "SO"))
			data->so++;
		else if (!ft_strcmp(data->texturecolorkey[i], "NO"))
			data->no++;
		else if (!ft_strcmp(data->texturecolorkey[i], "EA"))
			data->ea++;
		else if (!ft_strcmp(data->texturecolorkey[i], "WE"))
			data->we++;
		else if (!ft_strcmp(data->texturecolorkey[i], "F"))
			data->f++;
		else if (!ft_strcmp(data->texturecolorkey[i], "C"))
			data->c++;
		data->flag++;
	}
}

void	filltexturecolorenorm(t_data *data, int i, int j)
{
	data->texturecolor = ft_split(data->firstlines[i], ' ');
	if (count(data->texturecolor) != 2)
		all_errors(INVMAP);
	data->texturecolor[1] = removenewline(data->texturecolor[1]);
	data->texturecolorone[j] = ft_strdup(data->texturecolor[1]);
	data->texturecolorkey[j] = ft_strdup(data->texturecolor[0]);
	ft_free(data->texturecolor);
}

void	filltexturecolore(t_data *data)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = calculatewithoutn(data, data->firstlines);
	data->texturecolorkey = (char **)malloc(sizeof(char *) * (len + 1));
	data->texturecolorone = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->texturecolorkey || !data->texturecolorone)
		all_errors(ERRALLOC);
	j = 0;
	while (++i < data->countfirstlines)
	{
		while (data->firstlines[i] && data->firstlines[i][0] == '\n')
			i++;
		if (i < data->countfirstlines)
		{
			filltexturecolorenorm(data, i, j);
			j++;
		}
	}
	data->texturecolorkey[j] = NULL;
	data->texturecolorone[j] = NULL;
}

bool	parsefirstofmap(t_data *data)
{
	int	i;

	i = -1;
	initdirectioncolor(data);
	filltexturecolore(data);
	checkduplicate(data);
	checkfirstofmap(data);
	checkkeys(data);
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
			data->secondlines[i] = removenewline(data->secondlines[i]);
		len = ft_strlen(data->secondlines[i]);
		if (len > data->biglength)
			data->biglength = len;
		if (len < data->smalllength)
			data->smalllength = len;
	}
	addspaces(data);
	checkchar(data);
	checkplayerstart(data);
	return (true);
}
