/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividingmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:31:16 by ataji             #+#    #+#             */
/*   Updated: 2023/01/15 13:23:20 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first(t_data *data)
{
	data->norm = 0;
	while (data->norm < data->countfirstlines)
	{
		data->firstlines[data->norm] = ft_strdup(data->allmap[data->norm]);
		data->norm++;
	}
	data->firstlines[data->norm] = NULL;
}

void	second(t_data *data)
{
	data->norm = 0;
	data->nor = data->countfirstlines;
	while (data->norm < data->countsecondlines)
	{
		data->secondlines[data->norm] = ft_strdup(data->allmap[data->nor]);
		data->norm++;
		data->nor++;
	}
	data->secondlines[data->norm] = NULL;
}

bool	dividingmap(t_data *data)
{
	data->firstlines = (char **)malloc(sizeof(char *) \
		* (data->countfirstlines + 1));
	data->secondlines = (char **)malloc(sizeof(char *) \
		* (data->countsecondlines + 1));
	if (!data->firstlines || !data->secondlines)
		return (false);
	first(data);
	second(data);
	if (!data->countsecondlines || !data->countfirstlines)
		return (printf(BIGERR), false);
	return (true);
}
