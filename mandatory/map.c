/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:23:07 by jimikim           #+#    #+#             */
/*   Updated: 2021/09/28 14:17:58 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ptr(t_map_list **before, t_map_list *now, t_map_list **start)
{
	if (!*before)
	{
		*before = now;
		*start = *before;
	}
	else
	{
		(*before)->next = now;
		*before = (*before)->next;
	}
}

void	set_map_list(char *s, t_map_list **before, t_map_list **start)
{
	t_map_list	*map_list;

	map_list = malloc(sizeof(t_map_list));
	if (!map_list)
		print_error("malloc failed");
	map_list->next = NULL;
	map_list->map_line = ft_strdup(s);
	map_list->length = ft_strlen(s);
	set_ptr(before, map_list, start);
}

void	set_map_detail_sub(t_map_list *temp, int i, int *j, int *k)
{
	t_info	*info;

	info = get_info();
	while (temp->map_line[++(*j)])
	{
		if (temp->map_line[(*j)] == ' ')
			info->map[i][(*k)] = 'X';
		else
			info->map[i][(*k)] = temp->map_line[(*j)];
		(*k)++;
	}
}

void	set_map_detail(t_map_list *temp, t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		k = 0;
		set_map_detail_sub(temp, i, &j, &k);
		if (temp->length < info->map_width)
		{
			j = temp->length - 1;
			while (++j < info->map_width)
			{
				info->map[i][k] = 'X';
				k++;
			}
		}
		info->map[i][k] = 0;
		temp = temp->next;
	}
	info->map[i] = NULL;
}

void	set_map_array(t_map_list *start, t_info *info)
{
	t_map_list	*temp;
	int			width_map;
	int			height_map;
	int			length;

	width_map = ft_strlen(start->map_line);
	height_map = 1;
	temp = start->next;
	while (temp)
	{
		height_map++;
		length = ft_strlen(temp->map_line);
		if (width_map < length)
			width_map = length;
		temp = temp->next;
	}
	info->map_height = height_map;
	info->map_width = width_map;
	check_map_array(start);
	init_map_array(start, info);
	free_map_list(start);
	if (check_map(info, -1, -1))
		print_error("invalid map");
}
