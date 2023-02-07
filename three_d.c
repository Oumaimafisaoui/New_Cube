/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 15:34:07 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	calculate_projection(t_all *cub, int i)
{
	cub->three.d_player_pro = (WINDOW_W / 2.0) / tan(FEILD / 2.0);
	normalize(cub, i);
	cub->three.ray_distance = cub->ray[i].distance * \
	(cos(cub->ray[i].angle - cub->player.ang));
	cub->ray[i].angle = fmod(cub->ray[i].angle, (2 * M_PI));
	normalize(cub, i);
	cub->three.wall_projection = ((float)CUBE / cub->three.ray_distance) \
	* cub->three.d_player_pro;
	cub->ray[i].angle = fmod(cub->ray[i].angle, (2 * M_PI));
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
	int	y;
	int	x;

	i = -1;
	while (++i < cub->var_d.num_rays)
	{
		calculate_projection(cub, i);
		x = -1;
		while (++x < cub->three.wall_top_pix)
			my_mlx_pixel_put3(cub, i, x, \
			create_trgb(1, atoi(cub->map->ceil[0]), \
			atoi(cub->map->ceil[1]), atoi(cub->map->ceil[2])));
		generate_textures(cub, i);
		y = cub->three.wall_bott_pix;
		while (y < WINDOW_H)
		{
			my_mlx_pixel_put3(cub, i, y, \
			create_trgb(1, atoi(cub->map->floor[0]), \
			atoi(cub->map->floor[1]), atoi(cub->map->floor[2])));
			y++;
		}
	}
}

void	normalize(t_all *cub, int i)
{
	cub->ray[i].angle = fmod(cub->ray[i].angle, (2 * M_PI));
	if (cub->ray[i].angle < 0)
	{
		cub->ray[i].angle = (2 * M_PI) + cub->ray[i].angle;
	}
}



void	generate_textures(t_all *cub, int i)
{
	double	hit_x;
	double	hit_y;
	double	start;
	double	j;
	
	j= cub->three.wall_top_pix;
	start = cub->three.wall_top_pix;

	if (cub->ray[i].hor == true)
	{
		if (cub->ray[i].up == true)
		{
			hit_x = fmod(cub->ray[i].x, CUBE) / CUBE * (double)cub->no.img_w;
			while (j < cub->three.wall_bott_pix)
			{
				hit_y = ((j - start) * cub->no.img_h) / (double)cub->three.wall_height;
				my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->no.address + ((int)hit_y * cub->no.img_w + (int)hit_x))));
				j++;
			}
		}
		else if (cub->ray[i].down == true)
		{
			hit_x = fmod(cub->ray[i].x, CUBE) / CUBE * cub->so.img_w;
			while (j < cub->three.wall_bott_pix)
			{
				hit_y = ((j - start) * cub->so.img_h) / (double)cub->three.wall_height;
				my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->so.address + ((int)hit_y * cub->so.img_w + (int)hit_x))));
				j++;
			}
		}
	}
	else
	{
		if (cub->ray[i].right == true)
		{
			hit_x = fmod(cub->ray[i].y, CUBE) / CUBE * cub->ea.img_w;
			while (j < cub->three.wall_bott_pix)
			{
				hit_y = ((j - start) * (cub->ea.img_h) / (double)cub->three.wall_height);
				my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->ea.address + ((int)hit_y * cub->ea.img_w + ((int)hit_x)))));
				j++;
			}
		}
		else if (cub->ray[i].left == true)
		{
			hit_x = fmod(cub->ray[i].y, CUBE) / CUBE * cub->we.img_w;
			while (j < cub->three.wall_bott_pix)
			{
				hit_y = ((j - start) * cub->we.img_h) / (double)cub->three.wall_height;
				my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->we.address + ((int)hit_y * cub->we.img_w + ((int)hit_x)))));
				j++;
			}
		}
	}
	return;
}