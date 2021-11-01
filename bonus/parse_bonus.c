/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:36:38 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:30:39 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_cub_attr(char *line, int target, t_info *info)
{
	if (target != info->tex_count)
		print_error("invalid cub file");
	if (line[0] == 'N' && line[1] == 'O')
		info->file.no = ft_strdup(line);
	else if (line[0] == 'S' && line[1] == 'O')
		info->file.so = ft_strdup(line);
	else if (line[0] == 'W' && line[1] == 'E')
		info->file.we = ft_strdup(line);
	else if (line[0] == 'E' && line[1] == 'A')
		info->file.ea = ft_strdup(line);
	else if (line[0] == 'F')
		info->file.floor = ft_strdup(line);
	else if (line[0] == 'C')
		info->file.ceiling = ft_strdup(line);
}

void	find_and_set_alphabet(char *line, t_info *info, int *count)
{
	(*count)++;
	info->tex_count++;
	if (line[0] == 'N' && line[1] == 'O')
		set_cub_attr(line, 1, info);
	else if (line[0] == 'S' && line[1] == 'O')
		set_cub_attr(line, 2, info);
	else if (line[0] == 'W' && line[1] == 'E')
		set_cub_attr(line, 3, info);
	else if (line[0] == 'E' && line[1] == 'A')
		set_cub_attr(line, 4, info);
	else if (line[0] == 'F')
		set_cub_attr(line, 5, info);
	else if (line[0] == 'C')
		set_cub_attr(line, 6, info);
	else
		print_error("invalid texture");
}

int	init_parse_cub_fd(char *s, int *result, int *count)
{
	int	fd;

	*result = 1;
	*count = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		print_error("invalid cub file");
	return (fd);
}

void	init_parse_cub(char *s, t_map_list *before,
		t_map_list *start, t_info *info)
{
	char	*line;
	int		result;
	int		fd;
	int		count;

	fd = init_parse_cub_fd(s, &result, &count);
	while (result == 1)
	{
		line = 0;
		result = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		if (count < 6)
			find_and_set_alphabet(line, info, &count);
		else
			set_map_list(line, &before, &start);
		free(line);
	}
	close(fd);
	set_map_array(start, info);
}
