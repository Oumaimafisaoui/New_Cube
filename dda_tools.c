/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:56:34 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 12:17:33 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	normalize_player(t_all *cub)
{
	cub->player.ang = fmod(cub->player.ang, (2 * M_PI));
	if (cub->player.ang < 0)
		cub->player.ang = (2 * M_PI) + cub->player.ang;
}

void	normalize_rayangle(t_all *cub)
{
	cub->var_d.new_angle = fmod(cub->var_d.new_angle, (2 * M_PI));
	if (cub->var_d.new_angle < 0)
		cub->var_d.new_angle = (2 * M_PI) + cub->var_d.new_angle;
}

void	set_tab(int j, t_all *cub)
{
	cub->ray[j].angle = cub->var_d.new_angle;
	cub->ray[j].x = cub->var_d.x1;
	cub->ray[j].y = cub->var_d.y1;
	cub->ray[j].distance = sqrt((cub->var_d.x1 - cub->player.x) * \
	(cub->var_d.x1 - cub->player.x) + \
	((cub->var_d.y1 - cub->player.y) * (cub->var_d.y1 - cub->player.y)));
	cub->ray[j].down = cub->var_d.is_down;
	cub->ray[j].left = cub->var_d.is_left;
	cub->ray[j].right = cub->var_d.is_right;
	cub->ray[j].up = cub->var_d.is_up;
}

void	reset_directions(t_all *cub)
{
	cub->var_d.is_down = 0;
	cub->var_d.is_right = 0;
	cub->var_d.is_up = 0;
	cub->var_d.is_left = 0;
	cub->var_d.x1 = 0;
	cub->var_d.y1 = 0;
	cub->var_d.wallhitx = 0;
	cub->var_d.wallhity = 0;
	cub->var_d.wallhitx1 = 0;
	cub->var_d.wallhity1 = 0;
	cub->var_d.h_found_wall = 0;
	cub->var_d.v_found_wall = 0;
}

void	find_short_distance(t_all *cub, int j)
{
	if (cub->var_d.distance_hor_wall <= cub->var_d.distance_ver_wall)
	{
		cub->var_d.x1 = cub->var_d.wallhitx;
		cub->var_d.y1 = cub->var_d.wallhity;
		cub->ray[j].hor = true;
	}
	else
	{
		cub->var_d.x1 = cub->var_d.wallhitx1;
		cub->var_d.y1 = cub->var_d.wallhity1;
		cub->ray[j].hor = false;
	}
}
