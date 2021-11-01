/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:10:19 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 16:38:22 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_press_w(t_info *info)
{
	if (info->map[(int)(info->pos_x + info->dir_x
			* info->move_speed)][(int)(info->pos_y)] == '0')
		info->pos_x += info->dir_x * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
				+ info->dir_y * info->move_speed)] == '0')
		info->pos_y += info->dir_y * info->move_speed;
}

void	key_press_s(t_info *info)
{
	if (info->map[(int)(info->pos_x - info->dir_x
			* info->move_speed)][(int)(info->pos_y)] == '0')
		info->pos_x -= info->dir_x * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
				- info->dir_y * info->move_speed)] == '0')
		info->pos_y -= info->dir_y * info->move_speed;
}

void	key_press_d(t_info *info)
{
	if (info->map[(int)(info->pos_x + info->dir_y
			* info->move_speed)][(int)(info->pos_y)] == '0')
		info->pos_x += info->dir_y * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
				- info->dir_x * info->move_speed)] == '0')
		info->pos_y -= info->dir_x * info->move_speed;
}

void	key_press_a(t_info *info)
{
	if (info->map[(int)(info->pos_x - info->dir_y
			* info->move_speed)][(int)(info->pos_y)] == '0')
		info->pos_x -= info->dir_y * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
				+ info->dir_x * info->move_speed)] == '0')
		info->pos_y += info->dir_x * info->move_speed;
}

void	key_update(t_info *info)
{
	if (info->key_w)
		key_press_w(info);
	if (info->key_s)
		key_press_s(info);
	if (info->key_d)
		key_press_d(info);
	if (info->key_a)
		key_press_a(info);
	if (info->arrow_left)
		key_arrow_left(0, 0, info);
	if (info->arrow_right)
		key_arrow_right(0, 0, info);
}
