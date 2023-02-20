/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:49 by oufisaou          #+#    #+#             */
/*   Updated: 2023/02/18 11:02:41 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include	<mlx.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stddef.h>
# include	<string.h>
# include	<math.h>
# include	<stdio.h>
# include	"parsingcub3d/cub3d.h"
# include	<math.h>

# define CUBE 10
# define VIEW 100
# define FEILD 60
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define WINDOW_W 1080
# define WINDOW_H 720

typedef struct s_player
{
	double	x;
	double	y;
	double	ang;
	double	speed;
	double	rotation_speed;
}	t_player;

typedef struct s_ddavar
{
	double	x1;
	double	y1;
	double	xx1;
	double	yy1;
	double	xinc;
	double	yinc;
	double	steps;
	double	new_angle;
	double	dx;
	double	dy;

	double	xsteps;
	double	ysteps;
	double	xinter;
	double	yinter;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	double	wallhitx;
	double	wallhity;
	double	distance;
	int		h_found_wall;	
	double	xsteps1;
	double	ysteps1;
	double	xinter1;
	double	yinter1;	
	double	next_x_inter;
	double	next_y_inter;	
	double	next_x_inter1;
	double	next_y_inter1;	
	double	wallhitx1;
	double	wallhity1;
	double	distance1;
	int		v_found_wall;	
	double	num_rays;
	double	distance_hor_wall;
	double	distance_ver_wall;

}	t_ddavar;

typedef struct s_three
{
	double	d_player_pro;	
	double	wall_projection;
	float	ray_distance;
	double	wall_top_pix;
	double	wall_bott_pix;
	int		wall_height;
}	t_three;

typedef struct t_text
{
	void			*img2;
	int				img_w;
	int				img_h;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	*address;
}	t_text;

typedef struct s_ray
{
	double	x;
	double	y;
	double	angle;
	int		left;
	int		right;
	int		up;
	int		down;
	double	distance;
	bool	hor;
}	t_ray;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*img1;
	char		*addr1;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			bits_per_pixel1;
	int			line_length1;
	int			endian1;
	double		map_w;
	double		map_h;
	t_player	player;
	char		**walls;
	t_ddavar	var_d;
	t_three		three;
	t_ray		*ray;
	int			map_i;
	int			map_j;
	int			map_x;
	int			map_y;
	int			black;
	int			yellow;
	int			red;
	int			purple;
	double		hit_x;
	double		hit_y;
	double		hit_x1;
	double		hit_y1;
	t_data		*map;
	t_text		we;
	t_text		ea;
	t_text		no;
	t_text		so;
}	t_all;

void	init(t_all *cub);
void	init_suite(t_all *cub);
void	ft_error(char *str);
void	launch_mlx(t_all *cub);
void	draw_minimap(t_all *cub);
void	my_mlx_pixel_put(t_all *cub, int x, int y, int color);
void	get_player_coord(t_all *cub);
int		mouvements(int key, t_all *cub);
void	dda(t_all *cub);
void	set_direction(t_all *cub);
int		exit_program(t_all *cub);
void	event_left_right(t_all *cub, int key);
void	check_walls2(t_all *cub, int flag);
void	check_walls1(t_all *cub, int flag, double angle);
void	my_mlx_pixel_put2(t_all *cub, int x, int y, int color);
void	init2(t_all *cub);
void	make_rays(t_all *cub);
void	calculate_projection(t_all *cub, int i);
void	draw_grid(t_all *cub, int grid, int fill);
void	what_direction(t_all *cub);
void	fix_angle(t_all *cub);
void	is_down(t_all *cub);
void	is_up(t_all *cub);
void	is_left(t_all *cub);
void	what_direction1(t_all *cub);
void	is_right(t_all *cub);
void	is_left(t_all *cub);
void	is_up2(t_all *cub);
void	is_left2(t_all *cub);
void	normalize_player(t_all *cub);
void	normalize_rayangle(t_all *cub);
void	reset_directions(t_all *cub);
void	decide_casting(t_all *cub, int j);
void	vertical_inter(t_all *cub);
void	normalize_and_direction(t_all *cub);
void	begining_horizontal(t_all *cub);
void	begining_vertical(t_all *cub);
void	find_short_distance(t_all *cub, int j);
void	init_suite1(t_all *cub);
void	init_suite0(t_all *cub);
void	find_wall(t_all *cub, double x, double y);
void	reset_variables(t_all *cub);
void	generate_3d(t_all *cub);
void	dda2(t_all *cub);
void	put_big_player_circle(t_all *cub);
void	horizontal_inter(t_all *cub);
void	set_tab(int j, t_all *cub);
void	my_mlx_pixel_put3(t_all *cub, int x, int y, int color);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *str, size_t n);
void	init_suite2(t_all *cub);
void	generate_textures(t_all *cub, int i);
void	init_textures(t_all *cub);
void	normalize(t_all *cub, int i);
void	launch_norm(t_all *cub);
void	inter_suite(t_all *cub);
void	inter_suite1(t_all *cub);
void	vertical_condition(t_all *cub);
void	horizontal_condition(t_all *cub);
void	hor_texture(t_all *cub, int i, int start, double j);
void	ver_texture(t_all *cub, int i, double start, double j);
void	calculate_casting(t_all *cub);
#endif