/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 15:47:28 by oufisaou         ###   ########.fr       */
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
	double	j;
	double	start;

	start = cub->three.wall_top_pix;
	j = cub->three.wall_top_pix - 1;
	if (cub->ray[i].hor == true)
		hor_texture(cub, i, start, j);
	else
		ver_texture(cub, i, start, j);
	return ;
}