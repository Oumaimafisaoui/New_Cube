/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:32:08 by ataji             #+#    #+#             */
/*   Updated: 2023/01/14 23:00:48 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*returnline_aa(char *str, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(ft_strlen(str) + len + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
		if (!str[i])
		{
			while (len > 0)
			{
				ret[i] = ' ';
				i++;
				len--;
			}
			break ;
		}
	}
	ret[i] = '\0';
	return (ret);
}

void	addspaces(t_data *data)
{
	size_t	i;
	size_t	len;
	char	**saver;

	saver = (char **)malloc(sizeof(char *) * data->countsecondlines + 1);
	if (!saver)
		return ;
	i = 0;
	while (data->secondlines[i])
	{
		len = ft_strlen(data->secondlines[i]);
		if (len < data->biglength)
		{
			data->secondlines[i] = returnline_aa(data->secondlines[i],
					data->biglength - len);
		}
		i++;
	}
}

size_t	countecolors(char **colors)
{
	int	counter;

	counter = 0;
	while (colors[counter])
		counter++;
	return (counter);
}

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

bool	check_point(char *name)
{
	int	i;

	i = -1;
	while (name[++i])
		if (name[i] == '.')
			return (true);
	return (false);
}
