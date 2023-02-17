/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:37 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/17 13:48:05 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// void	f(){
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_all	cub;
	t_data	*data;

	// atexit(f);
	if (WINDOW_H > 2000 || WINDOW_W > 5000)
		ft_error("Invalid window dimension\n");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (allparsing(ac, av, data) == false)
	{
		free(data->allmap);
		free(data->firstlines);
		free(data->secondlines);
		return (1);
	}

	cub.map = data;
	cub.walls = data->secondlines;
	cub.map_w = cub.map->biglength * CUBE;
	cub.map_h = cub.map->countsecondlines * CUBE;
	init(&cub);
	launch_mlx(&cub);
}
