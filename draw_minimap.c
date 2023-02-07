/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 13:41:40 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put2(t_all *cub, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < cub->map_w) && (y >= 0 && y < cub->map_h))
	{
		dst = cub->addr + ((y * cub->line_length) + \
		(x * (cub->bits_per_pixel / 8)));
		*(unsigned int *)dst = color + (20 << 24);
	}
}

void	my_mlx_pixel_put3(t_all *cub, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WINDOW_W) && (y >= 0 && y < WINDOW_H))
	{
		dst = cub->addr1 + ((y * cub->line_length1) + \
		(x * (cub->bits_per_pixel1 / 8)));
		*(unsigned int *)dst = color;
	}
}

void	draw_grid(t_all *cub, int grid, int fill)
{
	cub->map_x = cub->map_j * CUBE;
	while (cub->map_x < (cub->map_j * CUBE) + CUBE)
	{
		if (cub->map_y % CUBE == 0 || cub->map_x % CUBE == 0) // put black line
			my_mlx_pixel_put2(cub, cub->map_x, cub->map_y, grid);
		else
			my_mlx_pixel_put2(cub, cub->map_x, cub->map_y, fill);
		cub->map_x++;
	}
	cub->map_y++;
}

void draw_minimap(t_all *cub)
{
	while (cub->map_i < cub->map_h / CUBE) 
	{
		cub->map_j = 0;
		while (cub->map_j < cub->map_w / CUBE)
		{
			cub->map_y = cub->map_i * CUBE;
			if (cub->walls[cub->map_i][cub->map_j] == '1')
			{
				while (cub->map_y < (cub->map_i * CUBE) + CUBE)
					draw_grid(cub, cub->black, cub->yellow);
			}
			else
			{
				while (cub->map_y < (cub->map_i * CUBE) + CUBE)
					draw_grid(cub, cub->black, cub->black);
			}
			cub->map_j++;
		}
		cub->map_i++;
	}
	reset_variables(cub);
	return ;
}

void	reset_variables(t_all *cub)
{
	cub->map_i = 0;
	cub->map_j = 0;
	cub->map_x = 0;
	cub->map_y = 0;
}
