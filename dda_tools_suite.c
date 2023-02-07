/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_tools_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:34:08 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 19:34:35 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	inter_suite(t_all *cub)
{
	cub->var_d.next_x_inter += cub->var_d.xsteps;
	cub->var_d.next_y_inter += cub->var_d.ysteps;
}

void	inter_suite1(t_all *cub)
{
	cub->var_d.next_x_inter1 += cub->var_d.xsteps1;
	cub->var_d.next_y_inter1 += cub->var_d.ysteps1;
}

void	vertical_condition(t_all *cub)
{
	cub->var_d.v_found_wall = 1;
	cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
	cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
}

void	horizontal_condition(t_all *cub)
{
	cub->var_d.h_found_wall = 1;
	cub->var_d.wallhitx = cub->var_d.next_x_inter;
	cub->var_d.wallhity = cub->var_d.next_y_inter;
}
