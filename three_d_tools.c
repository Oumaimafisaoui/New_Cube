/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:46:13 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 19:17:24 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hor_texture(t_all *cub, int i, int start, double j)
{
	if (cub->ray[i].up == true)
	{
		cub->hit_x = fmod(cub->ray[i].x, CUBE) / CUBE * (double)cub->no.img_w;
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
		cub->hit_x = fmod(cub->ray[i].x, CUBE) / CUBE * cub->so.img_w;
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
		cub->hit_x1 = fmod(cub->ray[i].y, CUBE) / CUBE * cub->ea.img_w;
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
		cub->hit_x1 = fmod(cub->ray[i].y, CUBE) / CUBE * cub->we.img_w;
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
