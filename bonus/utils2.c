/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:55:47 by znichola          #+#    #+#             */
/*   Updated: 2022/12/05 11:12:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	message_ret(int sig, int fd, char *msg)
{
	ft_putstr_fd(msg, fd);
	write(fd, &"\n", 1);
	return (sig);
}

int	ft_freeret_1(int ret, void *x)
{
	free(x);
	return (ret);
}

int	ft_freeret_2(int ret, void *x, void *y)
{
	free(x);
	free(y);
	return (ret);
}

int	ft_freeret_3(int ret, void *x, void *y, void *z)
{
	free(x);
	free(y);
	free(z);
	return (ret);
}

int	write_ops(int i)
{
	if (i == 0)
		write(1, &"sa\n", 3);
	else if (i == 1)
		write(1, &"sb\n", 3);
	else if (i == 2)
		write(1, &"ss\n", 3);
	else if (i == 3)
		write(1, &"pa\n", 3);
	else if (i == 4)
		write(1, &"pb\n", 3);
	else if (i == 5)
		write(1, &"ra\n", 3);
	else if (i == 6)
		write(1, &"rb\n", 3);
	else if (i == 7)
		write(1, &"rr\n", 3);
	else if (i == 8)
		write(1, &"rra\n", 4);
	else if (i == 9)
		write(1, &"rrb\n", 4);
	else if (i == 10)
		write(1, &"rrr\n", 4);
	return (SUCCESS);
}
