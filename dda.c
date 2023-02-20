/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:39:22 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/18 13:40:58 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dda2(t_all *cub)
{
	int	i;

	i = 0;
	cub->var_d.xinc = (cub->var_d.dx) / cub->var_d.steps;
	cub->var_d.yinc = (cub->var_d.dy) / cub->var_d.steps;
	while (i <= cub->var_d.steps)
	{
		my_mlx_pixel_put2(cub, round(cub->var_d.xx1), \
		round(cub->var_d.yy1), 0x0000CC00);
		cub->var_d.xx1 += cub->var_d.xinc;
		cub->var_d.yy1 += cub->var_d.yinc;
		i++;
	}
}

void	make_rays(t_all *cub)
{
	int		j;
	double	angle;

	j = 0;
	angle = cub->player.ang;
	cub->var_d.num_rays = WINDOW_W;
	cub->var_d.new_angle = angle - ((FEILD * (M_PI / 180)) / 2);
	normalize_rayangle(cub);
	while (j < cub->var_d.num_rays)
	{
		horizontal_inter(cub);
		vertical_inter(cub);
		decide_casting(cub, j);
		set_tab(j, cub);
		reset_directions(cub);
		cub->var_d.new_angle += ((FEILD * (M_PI / 180)) / cub->var_d.num_rays);
		normalize_rayangle(cub);
		j++;
	}
}

void	decide_casting(t_all *cub, int j)
{
	cub->ray[j].hor = false;
	calculate_casting(cub);
	if (cub->var_d.h_found_wall && cub->var_d.v_found_wall)
		find_short_distance(cub, j);
	else if (cub->var_d.h_found_wall)
	{
		cub->var_d.x1 = cub->var_d.wallhitx;
		cub->var_d.y1 = cub->var_d.wallhity;
		cub->ray[j].hor = true;
	}
	else if (cub->var_d.v_found_wall)
	{
		cub->var_d.x1 = cub->var_d.wallhitx1;
		cub->var_d.y1 = cub->var_d.wallhity1;
	}
	cub->var_d.xx1 = cub->player.x;
	cub->var_d.yy1 = cub->player.y;
	cub->var_d.dx = cub->var_d.x1 - cub->var_d.xx1;
	cub->var_d.dy = cub->var_d.y1 - cub->var_d.yy1;
	if (fabs(cub->var_d.dx) > fabs(cub->var_d.dy))
		cub->var_d.steps = fabs(cub->var_d.dx);
	else
		cub->var_d.steps = fabs(cub->var_d.dy);
	dda2(cub);
}

void	horizontal_inter(t_all *cub)
{
	begining_horizontal(cub);
	while (cub->var_d.next_x_inter >= 0 && cub->var_d.next_x_inter < cub->map_w \
	&& cub->var_d.next_y_inter >= 0 && cub->var_d.next_y_inter < cub->map_h)
	{
		if (cub->var_d.is_up == 1)
		{
			if (cub->walls[(int)((cub->var_d.next_y_inter - 1.0) / CUBE)][(int)
			(cub->var_d.next_x_inter / CUBE)] == '1')
			{
				cub->var_d.h_found_wall = 1;
				cub->var_d.wallhitx = cub->var_d.next_x_inter;
				cub->var_d.wallhity = cub->var_d.next_y_inter;
				break ;
			}
		}
		if (cub->walls[(int)((cub->var_d.next_y_inter) / CUBE)][(int)
		(cub->var_d.next_x_inter / CUBE)] == '1')
		{
			horizontal_condition(cub);
			break ;
		}
		inter_suite(cub);
	}
}

void	vertical_inter(t_all *cub)
{
	begining_vertical(cub);
	while (cub->var_d.next_x_inter1 >= 0 && \
	cub->var_d.next_x_inter1 < cub->map_w \
	&& cub->var_d.next_y_inter1 >= 0 && \
	cub->var_d.next_y_inter1 < cub->map_h)
	{
		if (cub->var_d.is_left == 1)
		{
			if (cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)
			((cub->var_d.next_x_inter1 - 1.0) / CUBE)] == '1')
			{
				cub->var_d.v_found_wall = 1;
				cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
				cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
				break ;
			}
		}
		if (cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)
		(cub->var_d.next_x_inter1 / CUBE)] == '1')
		{
			vertical_condition(cub);
			break ;
		}
		inter_suite1(cub);
	}
}
