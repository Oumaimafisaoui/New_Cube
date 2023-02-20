/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:57:34 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/17 13:51:03 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init(t_all *cub)
{
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->img = NULL;
	cub->addr = NULL;
	cub->img1 = NULL;
	cub->addr1 = NULL;
	cub->bits_per_pixel = 0;
	cub->line_length = 0;
	cub->endian = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	cub->player.ang = M_PI;
	cub->player.speed = 3.0;
	cub->player.rotation_speed = 3 * (M_PI / 180);
	cub->we.img_w = 0;
	cub->we.img_h = 0;
	cub->we.bits_per_pixel = 0;
	cub->we.line_length = 0;
	cub->we.endian = 0;
	cub->we.img2 = 0;
	cub->we.address = 0;
	init_suite1(cub);
	init_suite0(cub);
	init_suite(cub);
}

void	init_textures(t_all *cub)
{
	cub->no.img2 = mlx_xpm_file_to_image(cub->mlx, "xpmfile/NO.xpm", \
	&cub->no.img_w, &cub->no.img_h);
	if (!cub->no.img2)
		exit(1);
	cub->no.address = (unsigned int *)mlx_get_data_addr(cub->no.img2, \
	&cub->no.bits_per_pixel, &cub->no.line_length, &cub->we.endian);
	cub->so.img2 = mlx_xpm_file_to_image(cub->mlx, "xpmfile/SO.xpm", \
	&cub->so.img_w, &cub->so.img_h);
	if (!cub->so.img2)
		exit(1);
	cub->so.address = (unsigned int *)mlx_get_data_addr(cub->so.img2, \
	&cub->so.bits_per_pixel, &cub->so.line_length, &cub->we.endian);
	cub->ea.img2 = mlx_xpm_file_to_image(cub->mlx, "xpmfile/EA.xpm", \
	&cub->ea.img_w, &cub->ea.img_h);
	if (!cub->ea.img2)
		exit(1);
	cub->ea.address = (unsigned int *)mlx_get_data_addr(cub->ea.img2, \
	&cub->ea.bits_per_pixel, &cub->ea.line_length, &cub->we.endian);
	cub->we.img2 = mlx_xpm_file_to_image(cub->mlx, "xpmfile/WE.xpm", \
	&cub->we.img_w, &cub->we.img_h);
	if (!cub->we.img2)
		exit(1);
	cub->we.address = (unsigned int *)mlx_get_data_addr(cub->we.img2, \
	&cub->we.bits_per_pixel, &cub->we.line_length, &cub->we.endian);
}

void	set_direction(t_all *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_h / CUBE)
	{
		j = 0;
		while (j < cub->map_w / CUBE)
		{
			if (cub->walls[i][j] == 'N')
				cub->player.ang = (3 * M_PI) / 2;
			else if (cub->walls[i][j] == 'S')
				cub->player.ang = M_PI / 2;
			else if (cub->walls[i][j] == 'E')
				cub->player.ang = 0;
			else if (cub->walls[i][j] == 'W')
				cub->player.ang = M_PI;
			j++;
		}
		i++;
	}
}

void	launch_norm(t_all *cub)
{
	draw_minimap(cub);
	get_player_coord(cub);
	put_big_player_circle(cub);
	set_direction(cub);
	make_rays(cub);
	init_textures(cub);
	generate_3d(cub);
}

void	launch_mlx(t_all *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		ft_error("mlx_init failed\n");
	cub->mlx_win = mlx_new_window(cub->mlx, WINDOW_W, WINDOW_H, "Cub3D");
	if (cub->mlx_win == NULL)
		ft_error("mlx_new_window failed\n");
	cub->img = mlx_new_image(cub->mlx, cub->map_w, cub->map_h);
	cub->addr = mlx_get_data_addr(cub->img, \
	&cub->bits_per_pixel, &cub->line_length, \
	&cub->endian);
	cub->img1 = mlx_new_image(cub->mlx, WINDOW_W, WINDOW_H);
	cub->addr1 = mlx_get_data_addr(cub->img1, \
	&cub->bits_per_pixel1, &cub->line_length1, \
	&cub->endian1);
	launch_norm(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img1, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	mlx_hook(cub->mlx_win, 2, 0, mouvements, cub);
	mlx_hook(cub->mlx_win, 17, 0, exit_program, cub);
	mlx_loop(cub->mlx);
}
