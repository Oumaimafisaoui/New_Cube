/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:13:23 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 16:01:49 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	init_suite2(t_all *cub)
{
	cub->ea.img_w = 0;
	cub->ea.img_h = 0;
	cub->ea.bits_per_pixel = 0;
	cub->ea.line_length = 0;
	cub->ea.endian = 0;
	cub->ea.img2 = 0;
	cub->ea.address = 0;
	cub->no.img_w = 0;
	cub->no.img_h = 0;
	cub->no.bits_per_pixel = 0;
	cub->no.line_length = 0;
	cub->no.endian = 0;
	cub->no.img2 = 0;
	cub->no.address = 0;
	cub->so.img_w = 0;
	cub->so.img_h = 0;
	cub->so.bits_per_pixel = 0;
	cub->so.line_length = 0;
	cub->so.endian = 0;
	cub->so.img2 = 0;
	cub->so.address = 0;
	cub->three.wall_bott_pix = 0;
	cub->three.wall_top_pix = 0;
	cub->three.wall_height = 0;
}
void init_suite(t_all *cub)
{
	cub->black = 0x00000000;
	cub->yellow = 0x00FFFF00;
	cub->red = 0x00FF3333;
	cub->purple = 0x009966FF;
	cub->var_d.xsteps = 0;
	cub->var_d.ysteps = 0;
	cub->var_d.xinter = 0;
	cub->var_d.yinter = 0;
	cub->var_d.is_down = 0;
	cub->var_d.is_up = 0;
	cub->var_d.is_right = 0;
	cub->var_d.is_left = 0;
	cub->three.wall_projection = 0;
	cub->three.ray_distance = 0;
	cub->bits_per_pixel1 = 0;
	cub->line_length1 = 0;
	cub->endian1 = 0;
	init_suite1(cub);
}

void	init_suite0(t_all *cub)
{
	cub->var_d.x1 = 0;
	cub->var_d.y1 = 0;
	cub->var_d.xx1 = 0;
	cub->var_d.yy1 = 0;
	cub->var_d.xinc = 0;
	cub->var_d.yinc = 0;
	cub->var_d.steps = 0;
	cub->var_d.dx = 0;
	cub->var_d.dy = 0;
	cub->player.view = FEILD;
	cub->map_i = 0;
	cub->map_j = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->var_d.num_rays = 0;
	cub->three.d_player_pro = 0;
	cub->ray = calloc(sizeof(t_ray), WINDOW_W);
	cub->ray->down = 0;
	cub->ray->angle = 0;
	cub->ray->up = 0;
	cub->ray->left = 0;
	cub->ray->right = 0;
	cub->ray->distance = 0;
}

void	init_suite1(t_all *cub)
{
	cub->var_d.wallhitx = 0;
	cub->var_d.wallhity = 0;
	cub->var_d.distance = 0;
	cub->var_d.h_found_wall = 0;
	cub->var_d.xsteps1 = 0;
	cub->var_d.ysteps1 = 0;
	cub->var_d.xinter1 = 0;
	cub->var_d.yinter1 = 0;
	cub->var_d.wallhitx1 = 0;
	cub->var_d.wallhity1 = 0;
	cub->var_d.distance1 = 0;
	cub->var_d.v_found_wall = 0;
	cub->var_d.next_x_inter = 0;
	cub->var_d.next_y_inter = 0;
	cub->var_d.next_x_inter1 = 0;
	cub->var_d.next_y_inter1 = 0;
	cub->var_d.distance_hor_wall = 0;
	cub->var_d.distance_ver_wall = 0;
	cub->hit_x = 0;
	cub->hit_y = 0;
	cub->hit_x1 = 0;
	cub->hit_y1 = 0;
}

int	ref(int key, t_all *cub)
{
	(void)cub;
	if (key == 13 || key == 1 || key == 0 || key == 2)
		key = -1;
	return (0);
}
