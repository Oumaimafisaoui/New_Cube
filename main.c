/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:37 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/07 18:59:15 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
	t_all	cub;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (allparsing(ac, av, data) == false)
		return (1);
	cub.map = data;
	cub.walls = data->secondlines;
	cub.map_w = cub.map->biglength * CUBE;
	cub.map_h = cub.map->countsecondlines * CUBE;
	init(&cub);
	launch_mlx(&cub);
}