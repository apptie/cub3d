/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:53:09 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/05 09:26:41 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	set_cub_texture(char *line, t_info *info)
{
	t_img	img;
	char	**file_split;
	int		index;

	index = check_cub_texture(line);
	if (index == -1)
		print_error("invalid texture");
	file_split = ft_split(line, ' ');
	if (!file_split)
		print_error("malloc failed");
	if (ft_array_count(file_split) != 2)
		print_error("invalid texture");
	if (check_texture_file(file_split[1]))
		print_error("invalid texture");
	load_image(info, info->texture[index], file_split[1], &img);
	free_double_malloc(file_split);
}

void	load_texture(t_info *info)
{
	if (check_name(info->file.no, "xpm") == 0)
		print_error("invalid texture");
	if (check_name(info->file.so, "xpm") == 0)
		print_error("invalid texture");
	if (check_name(info->file.we, "xpm") == 0)
		print_error("invalid texture");
	if (check_name(info->file.ea, "xpm") == 0)
		print_error("invalid texture");
	set_cub_texture(info->file.no, info);
	set_cub_texture(info->file.so, info);
	set_cub_texture(info->file.we, info);
	set_cub_texture(info->file.ea, info);
}
