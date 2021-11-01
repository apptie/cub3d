/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:40:26 by slee2             #+#    #+#             */
/*   Updated: 2021/10/04 15:57:44 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_arrow_right(double old_dir, double old_plane, t_info *info)
{
	old_dir = info->dir_x;
	info->dir_x = info->dir_x * cos(-info->rot_speed)
		- info->dir_y * sin(-info->rot_speed);
	info->dir_y = old_dir * sin(-info->rot_speed)
		+ info->dir_y * cos(-info->rot_speed);
	old_plane = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->rot_speed)
		- info->plane_y * sin(-info->rot_speed);
	info->plane_y = old_plane * sin(-info->rot_speed)
		+ info->plane_y * cos(-info->rot_speed);
}

void	key_arrow_left(double old_dir, double old_plane, t_info *info)
{
	old_dir = info->dir_x;
	info->dir_x = info->dir_x * cos(info->rot_speed)
		- info->dir_y * sin(info->rot_speed);
	info->dir_y = old_dir * sin(info->rot_speed)
		+ info->dir_y * cos(info->rot_speed);
	old_plane = info->plane_x;
	info->plane_x = info->plane_x * cos(info->rot_speed)
		- info->plane_y * sin(info->rot_speed);
	info->plane_y = old_plane * sin(info->rot_speed)
		+ info->plane_y * cos(info->rot_speed);
}
