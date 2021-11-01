/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:57:23 by jimikim           #+#    #+#             */
/*   Updated: 2021/09/13 00:57:53 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = c;
	while (*s != to_find)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
