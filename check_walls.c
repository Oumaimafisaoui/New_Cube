/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:49:34 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 11:55:21 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_wall(t_all *cub, double x, double y)
{
	if (cub->walls[(int)(y / CUBE)][(int)(x / CUBE)] == '1' ||
	(cub->walls[(int)(y / CUBE)][(int)(cub->player.x / CUBE)] == '1' &&
	cub->walls[(int)(cub->player.y / CUBE)][(int)(x / CUBE)] == '1'))
		return ;
	else
		cub->player.x = x;
	cub->player.y = y;
}

void	check_walls1(t_all *cub, int flag, double angle)
{
	double	x;
	double	y;

	if (flag == 1)
	{
		x = cub->player.x + (cos(angle) * cub->player.speed);
		y = cub->player.y + (sin(angle) * cub->player.speed);
		find_wall(cub, x, y);
	}
	else if (flag == 0)
	{
		x = (cub->player.x - cos(angle) * cub->player.speed);
		y = (cub->player.y - sin(angle) * cub->player.speed);
		find_wall(cub, x, y);
	}
}

void	check_walls2(t_all *cub, int flag)
{
	double	x;
	double	y;

	if (flag == 1)
	{
		x = cub->player.x + (cos(cub->player.ang) * cub->player.speed);
		y = cub->player.y + (sin(cub->player.ang) * cub->player.speed);
		find_wall(cub, x, y);
	}
	else if (flag == 0)
	{
		x = cub->player.x - (cos(cub->player.ang) * cub->player.speed);
		y = cub->player.y - (sin(cub->player.ang) * cub->player.speed);
		find_wall(cub, x, y);
	}
}