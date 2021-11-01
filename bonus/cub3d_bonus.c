/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:31:46 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 12:40:33 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info, t_wall w, int x, int y)
{
	calc_background(info);
	while (x < WIDTH)
	{
		calc_set_ray_and_delta(x, &w, info);
		calc_set_sidedist_and_step(&w, info);
		calc_wall_hit(&w, info);
		calc_wall_height_line(&w, info);
		calc_wall_texture(&w);
		calc_wall_position(&w, info);
		y = w.draw_start - 1;
		while (++y < w.draw_end)
		{
			w.tex_y = (int)w.tex_pos & (TEXHEIGHT - 1);
			w.tex_pos += w.step;
			w.color = info->texture[w.tex_num][TEXHEIGHT * w.tex_y + w.tex_x];
			info->buf[y][x] = w.color;
		}
		x++;
	}
}

int	main_loop(t_info *info)
{
	t_wall	wall;

	init_wall(&wall);
	calc(info, wall, 0, 0);
	draw(info);
	key_update(info);
	return (0);
}

void	set_player(t_info *info)
{
	set_player_pos(info);
	if (info->player_char == 'N')
		set_player_north(info);
	else if (info->player_char == 'S')
		set_player_south(info);
	else if (info->player_char == 'E')
		set_player_east(info);
	else if (info->player_char == 'W')
		set_player_west(info);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 2)
		print_error("too few arguments");
	else if (argc > 2)
		print_error("too many arguments");
	info = get_info();
	if (check_name(argv[1], "cub") == 0)
		print_error("invalid .cub file");
	init_parse_cub(argv[1], 0, 0, info);
	set_player(info);
	set_cub_rgb(info->file.floor, info);
	set_cub_rgb(info->file.ceiling, info);
	init_info(info);
	load_texture(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3D");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
			&info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &exit_button, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &key_release, info);
	mlx_loop(info->mlx);
}
