/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:07:31 by znichola          #+#    #+#             */
/*   Updated: 2022/12/17 20:29:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	message_ret(int sig, char *msg)
{
	return (sig);
}
	// int	fd;

	// fd = 1;
	// if (sig == ERROR)
	// 	ft_putstr_fd(msg, fd);
	// else
	// 	ft_putstr_fd(msg, fd);
	// ft_putchar_fd('\n', fd);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest != NULL || src != NULL)
		while (n-- > 0)
			*d++ = *s++;
	return (dest);
}

int	freeret_1(int ret, void *x)
{
	free(x);
	return (ret);
}

int	freeret_2(int ret, void *x, void *y)
{
	free(x);
	free(y);
	return (ret);
}

int	freeret_3(int ret, void *x, void *y, void *z)
{
	free(x);
	free(y);
	free(z);
	return (ret);
}
