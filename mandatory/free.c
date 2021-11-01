/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:34:12 by jimikim           #+#    #+#             */
/*   Updated: 2021/09/28 01:06:16 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_malloc(char **target)
{
	int	i;

	i = 0;
	while (target[i])
		free(target[i++]);
	free(target);
}

void	free_map_list(t_map_list *target)
{
	t_map_list	*temp;

	temp = target;
	while (temp)
	{
		free(temp->map_line);
		target = temp;
		temp = temp->next;
		free(target);
	}
}
