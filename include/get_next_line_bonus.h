/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:52:54 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 12:40:02 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft_bonus.h"
# include <fcntl.h>

# define BUFFER_SIZE 1

int				get_next_line(int fd, char **line);

int				ft_strdup_static(char **static_buff, int fd, char *s);
void			ft_free_malloc(char *s);
int				ft_strdup_line(char **line, char *s);

#endif
