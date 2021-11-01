/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:44:52 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 15:14:49 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_texture(t_wall *w)
{
	if (w->side)
	{
		if (w->ray_dir_y < 0)
			w->tex_num = EAST;
		else
			w->tex_num = WEST;
	}
	else
	{
		if (w->ray_dir_x < 0)
			w->tex_num = SOUTH;
		else
			w->tex_num = NORTH;
	}
}

void	calc_wall_position(t_wall *w, t_info *info)
{
	if (w->side == 0)
		w->wall_x = info->pos_y + w->perp_wall_dist * w->ray_dir_y;
	else
		w->wall_x = info->pos_x + w->perp_wall_dist * w->ray_dir_x;
	w->wall_x -= floor(w->wall_x);
	w->tex_x = (int)(w->wall_x * (double)TEXWIDTH);
	if (w->side == 0 && w->ray_dir_x > 0)
		w->tex_x = TEXWIDTH - w->tex_x - 1;
	if (w->side == 1 && w->ray_dir_y < 0)
		w->tex_x = TEXWIDTH - w->tex_x - 1;
	w->step = 1.0 * TEXHEIGHT / w->line_height;
	w->tex_pos = (w->draw_start - HEIGHT / 2 + w->line_height / 2) * w->step;
}
