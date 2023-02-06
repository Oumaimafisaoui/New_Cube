/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/06 11:52:20 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void event_left_right(t_all *cub, int key)
{
    double angle;

    angle = cub->player.ang + (90.0 * (M_PI / 180.0));
    if (angle > 2 * M_PI)
        angle -= (2 * M_PI);
    if (angle < 0)
        angle += (2 * M_PI);
	if (key == RIGHT) 
        check_walls1(cub, 1, angle);
	else if (key == LEFT) 
        check_walls1(cub, 0, angle);
}


void event_up_down(t_all *cub, int key)
{
	if (key == UP)
        check_walls2(cub, 1);
	else if(key == DOWN)
        check_walls2(cub, 0);
}

void rotate_player(int key, t_all *cub)
{
    if(key == 123)
        cub->player.ang -= cub->player.rotation_speed;
    else if (key == 124)
        cub->player.ang += cub->player.rotation_speed;
}

int	mouvements(int key, t_all *cub)
{
    normalize_player(cub);
	if (key == RIGHT || key == LEFT)
		event_left_right(cub, key);
	else if (key == UP || key == DOWN)
		event_up_down(cub, key);
    else if (key == 53)
		exit_program(cub);
    else
        rotate_player(key, cub);
    normalize_player(cub);
    draw_minimap(cub);
    put_big_player_circle(cub);
    make_rays(cub);
    // puts("rays");
    mlx_clear_window(cub->mlx, cub->mlx_win);
    generate_3d(cub);
    // puts("3D");
    // dda(cub);
    // puts("D/DA");
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img1, 0, 0); //image of window
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0); //img of minimap
    return (1);
}
