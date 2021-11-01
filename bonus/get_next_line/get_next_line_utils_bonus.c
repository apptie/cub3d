/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:04:20 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 12:42:15 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free_malloc(char *s)
{
	if (s)
	{
		free(s);
		s = 0;
	}
}

int	ft_strdup_static(char **static_buff, int fd, char *s)
{
	char		*result;
	int			i;

	if (!s)
		return (0);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
	{
		ft_free_malloc(static_buff[fd]);
		return (-1);
	}
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = 0;
	static_buff[fd] = result;
	return (1);
}

int	ft_strdup_line(char **line, char *s)
{
	char	*result;
	int		i;

	if (!s)
		return (0);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
	{
		ft_free_malloc(*line);
		return (-1);
	}
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = 0;
	*line = result;
	return (1);
}
