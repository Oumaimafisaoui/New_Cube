/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:17:38 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 18:10:59 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*removenewline(char *str)
{
	int		i;
	char	*string;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		all_errors(ERRALLOC);
	i = -1;
	while (str[++i] && str[i] != '\n')
		string[i] = str[i];
	string[i] = '\0';
	free(str);
	return (string);
}
