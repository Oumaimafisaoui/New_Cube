/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:11:46 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 20:12:27 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkfirstofmap(t_data *data)
{
	if (data->we < 1 || data->no < 1 || data->ea < 1 || data->so < 1
		|| data->f < 1 || data->c < 1)
		all_errors(MISSKEY);
	if (data->we > 1 || data->no > 1 || data->ea > 1 || data->so > 1
		|| data->f > 1 || data->c > 1)
		all_errors(ERRKEYS);
	if (data->flag > 6)
		all_errors(ERRINTR);
	return (true);
}

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
	data->flag = 0;
}

int	calculatewithoutn(t_data *data, char **lines)
{
	int		len;
	int		i;

	len = -1;
	i = 0;
	(void)lines;
	while (data->firstlines[++len])
		if (data->firstlines[len][0] == '\n')
			i++;
	len = len - i;
	return (len);
}

int	count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
