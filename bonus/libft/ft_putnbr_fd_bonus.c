/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:51:23 by jimikim           #+#    #+#             */
/*   Updated: 2021/10/04 12:42:49 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_rec(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	ft_rec(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_rec(n * -1, fd);
	}
	else
		ft_rec(n, fd);
}
