/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:39:22 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/03 19:09:30 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void dda(t_all *cub)
{
    int i;

    i = 0;
    cub->var_d.x1 = cub->player.x + (cos(cub->player.ang) * VIEW);
    cub->var_d.y1 = cub->player.y + (sin(cub->player.ang) * VIEW);

    cub->var_d.xx1  = cub->player.x;
    cub->var_d.yy1 = cub->player.y;

    if(fabs(cub->var_d.x1 - cub->player.x) > fabs(cub->var_d.y1 -  cub->player.y))
        cub->var_d.steps = fabs(cub->var_d.x1 - cub->player.x);
    else
        cub->var_d.steps = fabs(cub->var_d.y1 - cub->player.y);

    cub->var_d.xinc = (cub->var_d.x1 - cub->player.x) / cub->var_d.steps;
    cub->var_d.yinc = (cub->var_d.y1 - cub->player.y) / cub->var_d.steps;

    while(i < cub->var_d.steps)
    {
        my_mlx_pixel_put2(cub, cub->var_d.xx1 , cub->var_d.yy1, 0x00FF0000);
        cub->var_d.xx1 = cub->var_d.xx1 + cub->var_d.xinc;
        cub->var_d.yy1 = cub->var_d.yy1 + cub->var_d.yinc;
        i++;
    }
}
void dda2(t_all *cub)
{
    int i;

    i = 0;
    cub->var_d.xinc = (cub->var_d.dx) / cub->var_d.steps;
    cub->var_d.yinc = (cub->var_d.dy) / cub->var_d.steps;
    while(i <= cub->var_d.steps)
    {
        my_mlx_pixel_put2(cub, round(cub->var_d.xx1) , round(cub->var_d.yy1), 0x0000CC00);
        cub->var_d.xx1 += cub->var_d.xinc;
        cub->var_d.yy1 += cub->var_d.yinc;
        i++;
    }
}

void normalize_player(t_all *cub)
{
    cub->player.ang = fmod(cub->player.ang ,(2 * M_PI));
    if (cub->player.ang < 0) {
        cub->player.ang = (2 * M_PI) + cub->player.ang;
    }
}

void normalize_rayangle(t_all *cub)
{ 
    cub->var_d.new_angle = fmod(cub->var_d.new_angle ,(2 * M_PI));
    if (cub->var_d.new_angle < 0){
        cub->var_d.new_angle = (2 * M_PI) + cub->var_d.new_angle;
    }
}

/*
    This function  Takes the player angle and takes 30 degree from it and start creating each 
    ray by increasing the angle with a 60 / NUM RAY
*/
void make_rays(t_all *cub)
{
    int  j;
    // double width;
    double angle;
    
    j = 0;
    angle = cub->player.ang;
    cub->var_d.num_rays = WINDOW_W;
    cub->var_d.new_angle = angle - (FEILD / 2);
    normalize_rayangle(cub);
    while(j < cub->var_d.num_rays) 
    {
        horizontal_inter(cub); 
        vertical_inter(cub);
        decide_casting(cub, j);
        set_tab(j, cub);
        reset_directions(cub);
        normalize_rayangle(cub);
        cub->var_d.new_angle += (FEILD / cub->var_d.num_rays);
        normalize_rayangle(cub);
        j++;
    }
}

void set_tab(int j, t_all *cub)
{
    cub->ray[j].angle = cub->var_d.new_angle;
    cub->ray[j].x = cub->var_d.x1;
    cub->ray[j].y = cub->var_d.y1;
    cub->ray[j].distance = hypot(cub->var_d.x1 - cub->player.x, cub->var_d.y1 - cub->player.y);
    cub->ray[j].down = cub->var_d.is_down;
    cub->ray[j].left = cub->var_d.is_left;
    cub->ray[j].right = cub->var_d.is_right;
    cub->ray[j].up = cub->var_d.is_up;
}

void reset_directions(t_all *cub)
{
    cub->var_d.is_down = 0;
    cub->var_d.is_right = 0;
    cub->var_d.is_up = 0;
    cub->var_d.is_left = 0;
    cub->var_d.x1 = 0;
    cub->var_d.y1 = 0;
    cub->var_d.wallhitx = 0;
    cub->var_d.wallhity = 0;
    cub->var_d.wallhitx1 = 0;
    cub->var_d.wallhity1 = 0;
    cub->var_d.h_found_wall = 0;
    cub->var_d.v_found_wall = 0;
}

void decide_casting(t_all *cub, int j)
{
    cub->ray[j].hor = false;
    cub->var_d.distance_hor_wall = hypot(cub->var_d.wallhitx - cub->player.x, cub->var_d.wallhity - cub->player.y);
    cub->var_d.distance_ver_wall = hypot(cub->var_d.wallhitx1 - cub->player.x, cub->var_d.wallhity1 - cub->player.y);
    if (cub->var_d.h_found_wall && cub->var_d.v_found_wall)
        find_short_distance(cub, j);
    else if (cub->var_d.h_found_wall)
    {
            cub->var_d.x1 = cub->var_d.wallhitx;
            cub->var_d.y1 = cub->var_d.wallhity;
            cub->ray[j].hor = true;

    }
    else if (cub->var_d.v_found_wall)
    {
            cub->var_d.x1 = cub->var_d.wallhitx1;
            cub->var_d.y1 = cub->var_d.wallhity1;
            cub->ray[j].hor = false;
    }
    cub->var_d.xx1 = cub->player.x;
    cub->var_d.yy1 =  cub->player.y;
    
    cub->var_d.dx = cub->var_d.x1 - cub->var_d.xx1;
    cub->var_d.dy = cub->var_d.y1 - cub->var_d.yy1;
    if(fabs(cub->var_d.dx) > fabs(cub->var_d.dy))
        cub->var_d.steps = fabs(cub->var_d.dx);
    else
        cub->var_d.steps = fabs(cub->var_d.dy);
}


void find_short_distance(t_all *cub, int j)
{
    if(cub->var_d.distance_hor_wall <= cub->var_d.distance_ver_wall)
    {
        cub->var_d.x1 = cub->var_d.wallhitx;
        cub->var_d.y1 = cub->var_d.wallhity;
        cub->ray[j].hor = true;
    }
    else
    {
        cub->var_d.x1 = cub->var_d.wallhitx1;
        cub->var_d.y1 = cub->var_d.wallhity1;
        cub->ray[j].hor = false;
    }
}
void horizontal_inter(t_all *cub)
{
    begining_horizontal(cub);
    while(cub->var_d.next_x_inter >= 0 && cub->var_d.next_x_inter < cub->map_w \
    && cub->var_d.next_y_inter >= 0 && cub->var_d.next_y_inter < cub->map_h)
    {
        if (cub->var_d.is_up == 1)
        {
            if(cub->walls[(int)((cub->var_d.next_y_inter - 1) / CUBE)][(int)(cub->var_d.next_x_inter / CUBE)] == '1')
            {
                cub->var_d.h_found_wall = 1;
                cub->var_d.wallhitx = cub->var_d.next_x_inter;
                cub->var_d.wallhity = cub->var_d.next_y_inter;
                break ;
            }

        }
        if(cub->walls[(int)((cub->var_d.next_y_inter) / CUBE)][(int)(cub->var_d.next_x_inter / CUBE)] == '1')
        {
            cub->var_d.h_found_wall = 1;
            cub->var_d.wallhitx = cub->var_d.next_x_inter;
            cub->var_d.wallhity = cub->var_d.next_y_inter;
            break ;
        }  
        cub->var_d.next_x_inter += cub->var_d.xsteps;
        cub->var_d.next_y_inter += cub->var_d.ysteps;
    } 
}

void vertical_inter(t_all *cub)
{
    begining_vertical(cub);
    while(cub->var_d.next_x_inter1  >= 0 && cub->var_d.next_x_inter1  < cub->map_w \
    && cub->var_d.next_y_inter1 >= 0 && cub->var_d.next_y_inter1 < cub->map_h)
    {
        if (cub->var_d.is_left == 1)
        {
            if(cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)((cub->var_d.next_x_inter1 - 1) / CUBE)] == '1')
            {
                cub->var_d.v_found_wall = 1;
                cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
                cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
                break ;
            }
        }
        if(cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)(cub->var_d.next_x_inter1 / CUBE)] == '1')
        {
                cub->var_d.v_found_wall = 1;
                cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
                cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
                break ;   
        }
            cub->var_d.next_x_inter1 += cub->var_d.xsteps1;
            cub->var_d.next_y_inter1  += cub->var_d.ysteps1;
    }
}