/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:28:14 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 15:07:20 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_left2(t_all *cub)
{
	if (cub->var_d.is_left == 1 && cub->var_d.xsteps1 > 0)
		cub->var_d.xsteps1 *= -1;
	if (cub->var_d.is_right == 1 && cub->var_d.xsteps1 < 0)
		cub->var_d.xsteps1 *= -1;
}

void	is_up2(t_all *cub)
{
	if ((cub->var_d.is_up == 1 && cub->var_d.ysteps1 > 0) || \
		(cub->var_d.is_down == 1 && cub->var_d.ysteps1 < 0))
		cub->var_d.ysteps1 *= -1;
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (p == 0)
		return (p);
	ft_bzero(p, num * size);
	return (p);
}

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}
