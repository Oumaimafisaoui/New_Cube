/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/17 12:21:16 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hor_texture(t_all *cub, int i, int start, double j)
{
	if (cub->ray[i].up == true)
	{
		cub->hit_x = fmod(cub->ray[i].x, CUBE) * (double)cub->no.img_w / CUBE ;
		while (++j < cub->three.wall_bott_pix)
		{
			cub->hit_y = ((j - start) * cub->no.img_h) \
			/ (double)cub->three.wall_height;
			my_mlx_pixel_put3(cub, i, (int)j, \
			*((int *)(cub->no.address + ((int)cub->hit_y * \
			cub->no.img_w + (int)cub->hit_x))));
		}
	}
	else if (cub->ray[i].down == true)
	{
		cub->hit_x = fmod(cub->ray[i].x, CUBE) * cub->so.img_w / CUBE;
		while (++j < cub->three.wall_bott_pix)
		{
			cub->hit_y = ((j - start) * cub->so.img_h) / \
			(double)cub->three.wall_height;
			my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->so.address \
			+ ((int)cub->hit_y * cub->so.img_w + (int)cub->hit_x))));
		}
	}
}

void	ver_texture(t_all *cub, int i, double start, double j)
{
	if (cub->ray[i].right == true)
	{
		cub->hit_x1 = fmod(cub->ray[i].y, CUBE) * cub->ea.img_w / CUBE;
		while (++j < cub->three.wall_bott_pix)
		{
			cub->hit_y1 = ((j - start) * (cub->ea.img_h) / \
			(double)cub->three.wall_height);
			my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->ea.address + \
			((int)cub->hit_y1 * cub->ea.img_w + ((int)cub->hit_x1)))));
		}
	}
	else if (cub->ray[i].left == true)
	{
		cub->hit_x1 = fmod(cub->ray[i].y, CUBE) * cub->we.img_w / CUBE;
		while (++j < cub->three.wall_bott_pix)
		{
			cub->hit_y1 = ((j - start) * cub->we.img_h) / \
			(double)cub->three.wall_height;
			my_mlx_pixel_put3(cub, i, (int)j, \
			*((int *)(cub->we.address + ((int)cub->hit_y1 \
			* cub->we.img_w + ((int)cub->hit_x1)))));
		}
	}
}

int	trgb_integer(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	calculate_projection(t_all *cub, int i)
{
	cub->three.d_player_pro = (WINDOW_W / 2.0) / \
	tan((FEILD * (M_PI / 180)) / 2.0);
	normalize(cub, i);
	cub->three.ray_distance = cub->ray[i].distance * \
	(cos(cub->ray[i].angle - cub->player.ang));
	normalize(cub, i);
	cub->three.wall_projection = ((float)CUBE / cub->three.ray_distance) \
	* cub->three.d_player_pro;
	normalize(cub, i);
	cub->three.wall_height = (int)cub->three.wall_projection;
	cub->three.wall_top_pix = (WINDOW_H / 2) - \
		(cub->three.wall_height / 2);
	cub->three.wall_bott_pix = (WINDOW_H / 2) \
	+ (cub->three.wall_height / 2);
}

void	generate_3d(t_all *cub)
{
	int	i;
	int	y2;
	int	y1;

	i = -1;
	while (++i < cub->var_d.num_rays)
	{
		calculate_projection(cub, i);
		y1 = -1;
		while (++y1 < cub->three.wall_top_pix)
			my_mlx_pixel_put3(cub, i, y1, \
			trgb_integer(1, ft_atoi(cub->map->ceil[0]), \
			ft_atoi(cub->map->ceil[1]), ft_atoi(cub->map->ceil[2])));
		generate_textures(cub, i);
		y2 = cub->three.wall_bott_pix;
		while (y2 < WINDOW_H)
		{
			my_mlx_pixel_put3(cub, i, y2, \
			trgb_integer(1, ft_atoi(cub->map->floor[0]), \
			ft_atoi(cub->map->floor[1]), ft_atoi(cub->map->floor[2])));
			y2++;
		}
	}
}
