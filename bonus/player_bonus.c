/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:46:07 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 12:41:38 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_player_north(t_info *info)
{
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
}

void	set_player_south(t_info *info)
{
	info->dir_x = 1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = -0.66;
}

void	set_player_west(t_info *info)
{
	info->dir_x = 0;
	info->dir_y = -1;
	info->plane_x = -0.66;
	info->plane_y = 0;
}

void	set_player_east(t_info *info)
{
	info->dir_x = 0;
	info->dir_y = 1;
	info->plane_x = 0.66;
	info->plane_y = 0;
}

void	set_player_pos(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (ft_strchr("NSEW", info->map[i][j]))
			{
				if (flag)
					print_error("wrong map charset");
				info->pos_x = i;
				info->pos_y = j;
				info->player_char = info->map[i][j];
				info->map[i][j] = '0';
				flag = 1;
			}
			j++;
		}
		i++;
	}
}
