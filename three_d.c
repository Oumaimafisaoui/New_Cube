/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/03 10:58:08 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void generate_3d(t_all *cub)
{
     int i;
     i = 0; 
     init_textures(cub);
     while(i < cub->var_d.num_rays)
     {
          cub->three.d_player_pro = (WINDOW_W / 2) / tan(FEILD / 2);
          cub->ray[i].angle = fmod(cub->ray[i].angle,(2 * M_PI));
          cub->three.ray_distance = cub->ray[i].distance * (cos(cub->ray[i].angle - cub->player.ang));
          cub->ray[i].angle = fmod(cub->ray[i].angle,(2 * M_PI));
          cub->three.wall_projection = (CUBE / cub->three.ray_distance) * cub->three.d_player_pro;
          cub->ray[i].angle = fmod(cub->ray[i].angle,(2 * M_PI));
          cub->three.wall_height = (int)cub->three.wall_projection;
          cub->three.wall_top_pix  = (WINDOW_H / 2) - (cub->three.wall_height / 2);
          cub->three.wall_bott_pix = (WINDOW_H / 2) + (cub->three.wall_height / 2);
          int x = -1;
          while(++x < cub->three.wall_top_pix)
                my_mlx_pixel_put3(cub, i, x, create_trgb(1 ,atoi(cub->map->ceil[0]), atoi(cub->map->ceil[1]), atoi(cub->map->ceil[2])));
          generate_textures(cub, i);
          for(int y = cub->three.wall_bott_pix; y < WINDOW_H; y++)
          {
               my_mlx_pixel_put3(cub, i, y, create_trgb(1 ,atoi(cub->map->floor[0]), atoi(cub->map->floor[1]), atoi(cub->map->floor[2])));
          }
          i++;
     }
}

void generate_textures(t_all *cub, int i)
{
     double hit_x;
     double hit_y;
     double start = cub->three.wall_top_pix;
     double j = cub->three.wall_top_pix;
 
     
      if (cub->ray[i].hor == true)
      {
          if(cub->ray[i].up == true)
          {
               hit_x = fmod(cub->ray[i].x , CUBE);
               hit_x = hit_x / CUBE * cub->no.img_w; //hasroha bin l 0 w l wall instead of the TTL
               while (j < cub->three.wall_bott_pix)
               {
                    // j - start :  the distance betcub->text->n the j and the top pixel
                    hit_y = ((j - start) * cub->no.img_h) / cub->three.wall_height;
                    my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->no.address + ((int)hit_y * cub->no.img_w + ((int)hit_x)))));
                    j++;
               }
          }
          else if (cub->ray[i].down == true)
          {
               hit_x = fmod(cub->ray[i].x , CUBE);
               hit_x = hit_x / CUBE * cub->so.img_w; //hasroha bin l 0 w l wall instead of the TTL
               while (j < cub->three.wall_bott_pix)
               {
                    // j - start :  the distance betcub->text->n the j and the top pixel
                    hit_y = ((j - start) * cub->so.img_h) / cub->three.wall_height;
                    my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->so.address + ((int)hit_y * cub->so.img_w + ((int)hit_x)))));
                    j++;
               }
          }
      }
      else
      {
          if(cub->ray[i].right == true)
          {
               hit_x = fmod(cub->ray[i].y , CUBE);
               hit_x = hit_x / CUBE * cub->ea.img_w; //hasroha bin l 0 w l wall instead of the TTL
               while (j < cub->three.wall_bott_pix)
               {
                    // j - start :  the distance betcub->text->n the j and the top pixel
                    hit_y = ((j - start) * cub->ea.img_h) / cub->three.wall_height;
                    my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->ea.address + ((int)hit_y * cub->ea.img_w + ((int)hit_x)))));
                    j++;
               }
          }
          else if (cub->ray[i].right == false)
          {
               hit_x = fmod(cub->ray[i].y , CUBE);
               hit_x = hit_x / CUBE * cub->we.img_w; //hasroha bin l 0 w l wall instwed of the TTL
               while (j < cub->three.wall_bott_pix)
               {
                    // j - start :  the distance betcub->text->n the j and the top pixel
                    hit_y = ((j - start) * cub->we.img_h) / cub->three.wall_height;
                    my_mlx_pixel_put3(cub, i, (int)j, *((int *)(cub->we.address + ((int)hit_y * cub->we.img_w + ((int)hit_x)))));
                    j++;
               }
          }
      }
     return ;
}