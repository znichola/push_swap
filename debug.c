/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:09:04 by znichola          #+#    #+#             */
/*   Updated: 2022/12/17 23:05:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: rename this
void	input_check(int ip)
{
	if (ip != 0 || ip == 2)
	{
		exit_error(42);
	}
}

void	write_op(int i)
{
	if (i == SA)
		ft_printf("sa");
	else if (i == SB)
		ft_printf("sb");
	else if (i == SS)
		ft_printf("ss");
	else if (i == PA)
		ft_printf("pa");
	else if (i == PB)
		ft_printf("pb");
	else if (i == RA)
		ft_printf("ra");
	else if (i == RB)
		ft_printf("rb");
	else if (i == RR)
		ft_printf("rr");
	else if (i == RRA)
		ft_printf("rra");
	else if (i == RRB)
		ft_printf("rrb");
	else if (i == RRR)
		ft_printf("rrr");
	else
		ft_printf("something else :%d", i);
}

void	write_ops_row(t_app *a)
{
	int	i;
	int	h;

	h = a->s.o.c - a->s.o.root + 1;
	i = 0;
	while (i < h)
	{
		write_op(a->s.o.root[i]);
		ft_printf(" ");
		i++;
	}
}

void	write_ops_column(t_app *a)
{
	int	i;
	int	h;

	h = a->s.o.c - a->s.o.root + 1;
	i = 0;
	while (i < h)
	{
		write_op(a->s.o.root[i]);
		ft_printf("\n");
		i++;
	}
}

// printf the stack going top down, the root is at the top of the terminal
//  top of stack is near the end.
int	print_stack(t_stack *s)
{
	int	i;

	i = -1;
	while (i++ < s->size)
	{
		if (s->root_a + i <= s->a)
			ft_printf("%-2d", s->root_a[i]);
		else
			ft_printf("  ");
		ft_printf(" ");
		if (s->root_b + i <= s->b)
			ft_printf("%-2d", s->root_b[i]);
		ft_printf("\n");
	}
	return (SUCCESS);
}
