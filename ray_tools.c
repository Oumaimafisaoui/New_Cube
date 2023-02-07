/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:26:29 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 14:29:55 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	what_direction(t_all *cub)
{
	if (cub->var_d.new_angle >= 0 && cub->var_d.new_angle <= M_PI)
		cub->var_d.is_down = 1;
	else if (cub->var_d.new_angle > M_PI && cub->var_d.new_angle < 2 * M_PI)
		cub->var_d.is_up = 1;
	if (cub->var_d.new_angle <= M_PI / 2.0 || \
	cub->var_d.new_angle > 3.0 * M_PI / 2.0)
		cub->var_d.is_right = 1;
	else if (cub->var_d.new_angle >= M_PI / 2 && \
	cub->var_d.new_angle < 3 * M_PI / 2)
		cub->var_d.is_left = 1;
}

void	is_down(t_all *cub)
{
	if (cub->var_d.is_down == 1)
		cub->var_d.yinter += CUBE;
	else
		cub->var_d.yinter += 0;
}

void	is_right(t_all *cub)
{
	if (cub->var_d.is_right == 1)
		cub->var_d.xinter1 += CUBE;
	else
		cub->var_d.xinter1 += 0;
}

void	is_up(t_all *cub)
{
	if (cub->var_d.is_up == 1 && cub->var_d.ysteps > 0)
		cub->var_d.ysteps *= -1;
	if (cub->var_d.is_down == 1 && cub->var_d.ysteps < 0)
		cub->var_d.ysteps *= -1;
}

void	is_left(t_all *cub)
{
	if (cub->var_d.is_left == 1 && cub->var_d.xsteps > 0)
		cub->var_d.xsteps *= -1;
	if (cub->var_d.is_right == 1 && cub->var_d.xsteps < 0)
		cub->var_d.xsteps *= -1;
}
