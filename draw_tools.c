/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:56:32 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 13:42:53 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_player_coord(t_all *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_h / CUBE)
	{
		j = 0;
		while (j < cub->map_w / CUBE)
		{
			if (cub->walls[i][j] == 'N' || cub->walls[i][j] == 'S' \
			|| cub->walls[i][j] == 'W' || cub->walls[i][j] == 'E')
			{
				cub->player.y = (i * CUBE) + CUBE / 2;
				cub->player.x = (j * CUBE) + CUBE / 2;
			}
			j++;
		}
		i++;
	}
}

void	put_big_player_circle(t_all *cub)
{
	double	h;
	double	angle;
	double	x_big;
	double	y_big;

	h = 1;
	my_mlx_pixel_put2(cub, cub->player.x, cub->player.y, 0x00FFFFFF);
	while (h < 3)
	{
		angle = 0;
		while (angle < 360)
		{
			x_big = cos(angle) * h + cub->player.x;
			y_big = sin(angle) * h + cub->player.y;
			my_mlx_pixel_put2(cub, x_big, y_big, 0x00FFFFFF);
			angle++;
		}
		h++;
	}
	return ;
}
