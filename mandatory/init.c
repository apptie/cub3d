/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:51:27 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 17:01:29 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall(t_wall *wall)
{
	wall->camera_x = 0;
	wall->ray_dir_x = 0;
	wall->ray_dir_y = 0;
	wall->map_x = 0;
	wall->map_y = 0;
	wall->side_dist_x = 0;
	wall->side_dist_y = 0;
	wall->delta_dist_x = 0;
	wall->delta_dist_y = 0;
	wall->perp_wall_dist = 0;
	wall->step_x = 0;
	wall->step_y = 0;
	wall->hit = 0;
	wall->side = 0;
	wall->line_height = 0;
	wall->draw_start = 0;
	wall->draw_end = 0;
	wall->tex_num = 0;
	wall->wall_x = 0;
	wall->tex_x = 0;
	wall->step = 0;
	wall->tex_pos = 0;
	wall->tex_y = 0;
	wall->color = 0;
	wall->map_value = 0;
}

void	init_buf(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			info->buf[i][j] = 0;
		}
	}
}

void	init_texture(int i, int j, t_info *info)
{
	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
		print_error("malloc failed");
	while (++i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!info->texture[i])
			print_error("malloc failed");
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
		{
			info->texture[i][j] = 0;
		}
	}
}

void	init_info(t_info *info)
{
	info->mlx = mlx_init();
	init_buf(info);
	init_texture(-1, -1, info);
	info->move_speed = 0.06;
	info->rot_speed = 0.06;
	info->tex_count = 0;
	info->key_w = 0;
	info->key_a = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->arrow_left = 0;
	info->arrow_right = 0;
}

void	init_map_array(t_map_list *temp, t_info *info)
{
	int	i;

	info->map = malloc(sizeof(char *) * (info->map_height + 1));
	if (!info->map)
		print_error("malloc failed");
	i = 0;
	while (i < info->map_height)
	{
		info->map[i] = malloc(sizeof(char) * (info->map_width + 1));
		if (!info->map[i])
			print_error("malloc failed");
		i++;
	}
	set_map_detail(temp, info);
}
