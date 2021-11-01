/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:41:56 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 16:38:42 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "get_next_line_bonus.h"
# include "libft_bonus.h"
# include "../mlx/mlx.h"
# include "key_macos_bonus.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 1500
# define HEIGHT 1200
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_map_list	t_map_list;
typedef struct s_file		t_file;
typedef struct s_wall		t_wall;
typedef struct s_img		t_img;
typedef struct s_info		t_info;

struct	s_map_list
{
	char		*map_line;
	int			length;
	t_map_list	*next;
};

struct	s_wall
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		map_value;
};

struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
};

struct	s_file
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
};

struct	s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[HEIGHT][WIDTH];
	int		**texture;
	double	move_speed;
	double	rot_speed;
	char	**map;
	int		map_height;
	int		map_width;
	char	player_char;
	int		texNum;
	t_file	file;
	int		tex_count;
	int		f_color;
	int		c_color;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		arrow_left;
	int		arrow_right;
};

void	free_double_malloc(char **target);
void	free_map_list(t_map_list *target);
void	print_error(char *msg);
t_info	*get_info(void);
void	init_wall(t_wall *wall);
void	init_buf(t_info *info);
void	init_texture(int i, int j, t_info *info);
void	init_info(t_info *info);
void	init_map_array(t_map_list *temp, t_info *info);
int		check_key_wall(int x, int y, t_info *info);
int		check_cub_texture(char *line);
int		check_texture_file(char *file_name);
int		check_cub_rgb(char *rgb);
void	check_rgb_line(char *s);
int		check_map_sub(t_info *info, int i, int j);
int		check_map(t_info *g, int i, int j);
void	check_map_array(t_map_list *start);
int		check_name(char *arg, char *ext);
int		exit_button(void);
void	key_press_w(t_info *info);
void	key_press_s(t_info *info);
void	key_press_d(t_info *info);
void	key_press_a(t_info *info);
void	key_arrow_left(double old_dir, double old_plane, t_info *info);
void	key_arrow_right(double old_dir, double old_plane, t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
void	key_update(t_info *info);
void	set_player_pos(t_info *info);
void	set_player_north(t_info *info);
void	set_player_south(t_info *info);
void	set_player_west(t_info *info);
void	set_player_east(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	set_cub_texture(char *line, t_info *info);
void	load_texture(t_info *info);
void	set_map_array(t_map_list *start, t_info *info);
void	set_map_detail(t_map_list *temp, t_info *info);
void	set_map_list(char *s, t_map_list **before, t_map_list **start);
void	init_parse_cub(char *s, t_map_list *before, \
	t_map_list *start, t_info *info);
void	set_cub_rgb(char *line, t_info *info);
void	calc_background(t_info *info);
void	calc_set_ray_and_delta(int x, t_wall *w, t_info *info);
void	calc_set_sidedist_and_step(t_wall *w, t_info *info);
void	calc_wall_hit(t_wall *w, t_info *info);
void	calc_wall_height_line(t_wall *w, t_info *info);
void	calc_wall_texture(t_wall *w);
void	calc_wall_position(t_wall *w, t_info *info);

#endif
