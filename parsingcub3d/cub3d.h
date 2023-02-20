/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:28:32 by ataji             #+#    #+#             */
/*   Updated: 2023/02/19 20:20:56 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<stdbool.h>
# include<fcntl.h>
# include<limits.h>
# include<math.h>
# include<mlx.h>

# define BUFFER_SIZE 1024 

# define ERRARGUMENTS "ERROR : You should write two arguments\n"
# define ERRFIRSTMAP "ERROR : Somthing wrong in first part of map\n"
# define ERRNAME "ERROR : The map must be named like that \"*.cub\"\n"
# define ERRIMGNAME "ERROR : The map must be named like that \"*.xpm\"\n"
# define ERRSYNMAP "ERROR : The map must had 'SO', 'EA', 'WE', 'NO', 'F', 'C'\n"
# define ERRNUMCOLOR "ERROR : You should write three numbers in RGB color\n"
# define ERRSYNCOLOR "ERROR : The color must be in RGB color system and\
 the number sandwiched between 0 and 255\n"
# define INVMAP "ERROR : Invalid map\n"
# define PLAYERSTART "ERROR : You should write one start of player\n"
# define INTRUDER "ERROR : Attention we have an intruder in second part of map\n"
# define MISSKEY "ERROR : Attention you missing a key\n"
# define ERRKEYS "ERROR : Attention you duplicate a key\n"
# define ERRINTR "ERROR : Attention we have an intruder in first part of map\n"
# define BIGERR "ERROR : Attention don't have first part of map or\
 second part of map\n"
# define ERRFILE "ERROR : No such file or directory\n"
# define ERREMPTY "ERROR : Empty map\n"
# define ERRALLOC "ERROR : Bad allocation\n"

# define IMG_SIZE 9
# define SIZE_MINI 10
# define WALL_STR_WIDTH 1
# define WIDTH 1920
# define HEIGHT 1080

enum
{
	EA,
	WE,
	SO,
	NO
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
}	t_img;

typedef struct s_data
{
	int				flag;
	int				norm;
	int				nor;
	char			**allmap;
	char			**firstlines;
	char			**texturecolor;
	char			**texturecolorkey;
	char			**texturecolorone;
	char			**secondlines;
	int				countlines;
	int				countfirstlines;
	int				countsecondlines;
	int				i;
	int				so;
	int				ea;
	int				no;
	int				we;
	int				c;
	int				f;
	char			**ceil;
	char			**floor;
	int				counter;
	int				x;
	size_t			biglength;
	size_t			smalllength;
	int				p_i;
	int				p_j;
	double			fov_angle;
	double			xx;
	double			yy;
	int				num_rays;
	int				ray_color;
	int				square_color;
	double			hor_dis;
	double			ver_dis;
	double			dis;
	int				scal;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	unsigned int	wall_color;
	double			max_dis;
	int				path_img_width;
	int				path_img_heigth;
	long long		mouse;
	char			*texture[4];
	t_img			textureimg[4];
}t_data;

char	*removenewline(char *str);

/**************************** libft ****************************/
size_t	ft_strlen(char const *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_words(const char *str, char c);
char	**ft_freeing(char **tab);
char	**set_words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**set_wordsnewline(char const *s, char c);
char	**ft_splitnewline(char const *s, char c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

/**************************** get_next_line ****************************/
int		get_back_slash_n(char *store_line);
char	*get_line_file(char *static_line, int fd);
char	*rest_line(char *static_line);
char	*get_line_static(char *static_line);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);

/**************************** cub3d.c ****************************/
size_t	countdoublepoint(char **tab);
bool	check_arguments(int numofargs, char *mapname);
bool	readfromfile(char *mapname, t_data *data);
bool	parsemap(t_data *data);
bool	allparsing(int ac, char **av, t_data *data);

/**************************** cub3d_utils.c ****************************/
char	*returnline_aa(char *str, size_t len);
void	addspaces(t_data *data);
size_t	countecolors(char **colors);
void	ft_free(char **tab);
bool	check_point(char *name);

/**************************** compass_colore.c ****************************/
bool	checkrgb(t_data *data, char *elements, char *colors);
bool	checkfile(char *elements);
bool	checknumbers(t_data *data, char **colors);
bool	checkcoloref(t_data *data, char *elements);
bool	checkcolorec(t_data *data, char *elements);

/**************************** counters.c ****************************/
void	all_errors(char *str);
int		countargs(char *firstline);
int		countlinesfirstmap(t_data *data);
int		countlinessecondmap(t_data *data);
int		countlines(char *mapname);

/**************************** parser.c ****************************/
bool	checktexture(t_data *data);
void	settexture(t_data *data, int i);
bool	checkkeys(t_data *data);
bool	checkplayerstart(t_data *data);
bool	parsecharsecondmap(t_data *data);

/**************************** dividingmap.c ****************************/
void	first(t_data *data);		
void	second(t_data *data);
bool	dividingmap(t_data *data);

/**************************** checkzero.c ****************************/
bool	checkrightleftchar(char *line);
bool	checkfirstandlastline(char **line, t_data *data);
bool	checkbottomtopchar(char **line, t_data *data);
bool	checkfirstchar(t_data *data);
bool	checkchar(t_data *data);

/**************************** norm.c ****************************/
bool	checkfirstofmap(t_data *data);
void	initdirectioncolor(t_data *data);
int		calculatewithoutn(t_data *data, char **lines);
int		count(char **tab);

/**************************** parsetwopartsofmap.c ****************************/
void	checkduplicate(t_data *data);
void	filltexturecolorenorm(t_data *data, int i, int j);
void	filltexturecolore(t_data *data);
bool	parsefirstofmap(t_data *data);
bool	parsesecondofmap(t_data *data);

#endif
