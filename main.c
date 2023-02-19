/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:37 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/19 20:21:26 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_all	cub;
	t_data	*data;

	if (WINDOW_H > 2000 || WINDOW_W > 5000)
		ft_error("Invalid window dimension\n");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	allparsing(ac, av, data);
	ft_free(data->allmap);
	ft_free(data->firstlines);
	ft_free(data->texturecolorkey);
	ft_free(data->texturecolorone);
	cub.map = data;
	cub.walls = data->secondlines;
	cub.map_w = cub.map->biglength * CUBE;
	cub.map_h = cub.map->countsecondlines * CUBE;
	init(&cub);
	launch_mlx(&cub);
}
