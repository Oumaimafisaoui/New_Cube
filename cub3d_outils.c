/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:53:36 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/19 20:10:07 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
	return ;
}

int	exit_program(t_all *cub)
{
	int	index;

	index = 0;
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	while (index < cub->map_h / CUBE)
	{
		free(cub->walls[index]);
		index++;
	}
	free(cub->walls);
	free(cub->ray);
	ft_free(cub->map->ceil);
	ft_free(cub->map->floor);
	exit(0);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	calculate_casting(t_all *cub)
{
	cub->var_d.distance_hor_wall = sqrt((cub->var_d.wallhitx - cub->player.x) \
	* (cub->var_d.wallhitx - cub->player.x) + \
	((cub->var_d.wallhity - cub->player.y) \
	* (cub->var_d.wallhity - cub->player.y)));
	cub->var_d.distance_ver_wall = sqrt((cub->var_d.wallhitx1 - cub->player.x) \
	* (cub->var_d.wallhitx1 - cub->player.x) + \
	((cub->var_d.wallhity1 - cub->player.y) \
	* (cub->var_d.wallhity1 - cub->player.y)));
}
