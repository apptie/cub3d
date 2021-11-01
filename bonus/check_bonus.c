/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:02:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:31:01 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_key_wall(int x, int y, t_info *info)
{
	int	result;

	result = 1;
	if (x + 1 >= info->map_height || y + 1 >= info->map_width
		|| x - 1 < 0 || y - 1 < 0)
		return (0);
	if (!info->map[x + 1][y] || info->map[x + 1][y] == 'X')
		result = 0;
	if (!info->map[x - 1][y] || info->map[x - 1][y] == 'X')
		result = 0;
	if (!info->map[x + 1][y + 1] || info->map[x + 1][y + 1] == 'X')
		result = 0;
	if (!info->map[x + 1][y - 1] || info->map[x + 1][y - 1] == 'X')
		result = 0;
	if (!info->map[x][y + 1] || info->map[x][y + 1] == 'X')
		result = 0;
	if (!info->map[x][y - 1] || info->map[x][y - 1] == 'X')
		result = 0;
	if (!info->map[x - 1][y - 1] || info->map[x - 1][y - 1] == 'X')
		result = 0;
	if (!info->map[x - 1][y + 1] || info->map[x - 1][y + 1] == 'X')
		result = 0;
	return (result);
}

int	check_cub_texture(char *line)
{
	int	result;

	result = -1;
	if (ft_strlen(line) < 3)
		return (result);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		result = 0;
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		result = 1;
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		result = 2;
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		result = 3;
	return (result);
}

int	check_texture_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_cub_rgb(char *rgb)
{
	int	result;

	result = -1;
	if (ft_strlen(rgb) < 2)
		return (result);
	if (rgb[0] == 'F' && rgb[1] == ' ')
		result = 0;
	else if (rgb[0] == 'C' && rgb[1] == ' ')
		result = 1;
	return (result);
}

void	check_rgb_line(char *s)
{
	int	i;

	if (!s || ft_strlen(s) == 0)
		print_error("invalid rgb");
	i = 0;
	while (s[i])
	{
		if (!ft_strchr("0123456789", s[i]))
			print_error("invalid rgb");
		i++;
	}
}
