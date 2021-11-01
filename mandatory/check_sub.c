/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:02:13 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:23:47 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_sub(t_info *info, int i, int j)
{
	if (!info->map[i][j - 1] || info->map[i][j - 1] == 'X')
		return (1);
	else if (!info->map[i][j + 1] || info->map[i][j + 1] == 'X')
		return (1);
	else if (!info->map[i + 1][j] || info->map[i + 1][j] == 'X')
		return (1);
	else if (!info->map[i - 1][j] || info->map[i - 1][j] == 'X')
		return (1);
	else if (!info->map[i - 1][j - 1] || info->map[i - 1][j - 1] == 'X')
		return (1);
	else if (!info->map[i - 1][j + 1] || info->map[i - 1][j + 1] == 'X')
		return (1);
	else if (!info->map[i + 1][j - 1] || info->map[i + 1][j - 1] == 'X')
		return (1);
	else if (!info->map[i + 1][j + 1] || info->map[i + 1][j + 1] == 'X')
		return (1);
	return (0);
}

int	check_map(t_info *g, int i, int j)
{
	while (++i < g->map_height)
	{
		j = -1;
		while (++j < g->map_width)
		{
			if (g->map[i][j] != 'X' && g->map[i][j] != '1')
				if (check_map_sub(g, i, j))
					return (1);
		}
	}
	return (0);
}

void	check_map_array(t_map_list *start)
{
	t_map_list	*temp;
	int			i;

	temp = start;
	while (temp)
	{
		i = 0;
		while (temp->map_line[i])
		{
			if (!ft_strchr("1 0NSEW", temp->map_line[i]))
				print_error("invalid map");
			i++;
		}
		temp = temp->next;
	}
}

int	check_name(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1]
		&& arg[i - 3] == ext[0] && arg[i - 4] == '.')
		return (1);
	return (0);
}
