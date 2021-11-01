/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:37:30 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:14:19 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_background(t_info *info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			info->buf[y][x] = info->f_color;
			info->buf[HEIGHT - y - 1][x] = info->c_color;
		}
	}
}

void	calc_set_ray_and_delta(int x, t_wall *w, t_info *info)
{
	w->camera_x = 2 * x / (double)WIDTH - 1;
	w->ray_dir_x = info->dir_x + info->plane_x * w->camera_x;
	w->ray_dir_y = info->dir_y + info->plane_y * w->camera_x;
	w->map_x = (int)info->pos_x;
	w->map_y = (int)info->pos_y;
	w->delta_dist_x = fabs(1 / w->ray_dir_x);
	w->delta_dist_y = fabs(1 / w->ray_dir_y);
	w->hit = 0;
}

void	calc_set_sidedist_and_step(t_wall *w, t_info *info)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (info->pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - info->pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (info->pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - info->pos_y) * w->delta_dist_y;
	}
}

void	calc_wall_hit(t_wall *w, t_info *info)
{
	while (w->hit == 0)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_y += w->step_y;
			w->side = 1;
		}
		if (info->map[w->map_x][w->map_y] == 'X'
			|| info->map[w->map_x][w->map_y] == '0')
			w->map_value = 0;
		else if (info->map[w->map_x][w->map_y] == '1')
			w->map_value = 1;
		if (w->map_value > 0)
			w->hit = 1;
	}
}

void	calc_wall_height_line(t_wall *w, t_info *info)
{
	if (w->side == 0)
		w->perp_wall_dist = (w->map_x - info->pos_x
				+ (1 - w->step_x) / 2) / w->ray_dir_x;
	else
		w->perp_wall_dist = (w->map_y - info->pos_y
				+ (1 - w->step_y) / 2) / w->ray_dir_y;
	w->line_height = (int)(HEIGHT / w->perp_wall_dist);
	w->draw_start = -w->line_height / 2 + HEIGHT / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_height / 2 + HEIGHT / 2;
	if (w->draw_end >= HEIGHT)
		w->draw_end = HEIGHT - 1;
}
