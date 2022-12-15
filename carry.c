/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:10:14 by znichola          #+#    #+#             */
/*   Updated: 2022/12/14 13:59:57 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	oh(t_ops *o)
{
	return (o->c - o->root + 1);
}

// calculate the longest RB in the sequence of moves.
int	longest_op_run(t_ops *o, int op)
{
	int	i;
	int	h;
	int	*start;
	int	count;
	int	biggest_count;
	int	*biggest_start;
	
	biggest_count = 0;
	count = 0;
	i = 0;
	h = oh(o);
	while (i++ < h)
	{
		if (o->root[i - 1] != op && o->root[i] == op)
		{
			if (count >= 1)
			{
				biggest_count = count;
				start = o->root + i;
			}
			count = 1;
			ft_printf("start  s:%-3d c:%-3d  ", i, count);
		}	
		else if (o->root[i] == op)
		{
			count += 1;
			ft_printf("add    s:%-3d c:%-3d  ", i, count);
		}
		else
		{
			count = 0;
			ft_printf("reset  s:%-3d c:%-3d  ", i, count);
		}
		write_op(o->root[i]); ft_printf("\n");
	}
	ft_printf("start%p biggest:%d\n", start, biggest_count);
	return (SUCCESS);
}


// int *find_longest_run(t_ops *o)
// {
// 	int	*start;
// 	int	h;
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 1;
// 	h = oh(o);
// 	while (i < h)
// 	{
// 		if 
// 		if (o->root[i] == RB && o->root[i - 1] == PA)
// 			start = o->root[i];
// 	}
// 	return (start)
// }

// int	opcarry(t_ops *o, t_ops *new)
// {
	
// }