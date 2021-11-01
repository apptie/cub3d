/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:50:43 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:21:48 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cub_rgb_sub(char **rgb_split, char **file_split,
		int result, t_info *info)
{
	int	r;
	int	g;
	int	b;

	check_rgb_line(rgb_split[0]);
	check_rgb_line(rgb_split[1]);
	check_rgb_line(rgb_split[2]);
	r = ft_atoi(rgb_split[0]);
	g = ft_atoi(rgb_split[1]);
	b = ft_atoi(rgb_split[2]);
	free_double_malloc(rgb_split);
	free_double_malloc(file_split);
	if (result == 0)
		info->f_color = (r << 16) | (g << 8) | b;
	else if (result == 1)
		info->c_color = (r << 16) | (g << 8) | b;
}

void	set_cub_rgb(char *line, t_info *info)
{
	char	**file_split;
	char	**rgb_split;
	int		result;

	result = check_cub_rgb(line);
	if (result == -1)
		print_error("invalid rgb value");
	file_split = ft_split(line, ' ');
	if (!file_split)
		print_error("malloc failed");
	if (ft_array_count(file_split) != 2)
		print_error("invalid rgb value");
	if (ft_word_count(file_split[1], ',') != 2)
		print_error("invalid rgb value");
	rgb_split = ft_split(file_split[1], ',');
	if (!rgb_split)
		print_error("malloc failed");
	set_cub_rgb_sub(rgb_split, file_split, result, info);
}
