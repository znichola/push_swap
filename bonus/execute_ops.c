/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:23:19 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 14:21:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	do_op(t_stack *s, int op)
{
	if (op == SA)
		return (sa_(s));
	if (op == SB)
		return (sb_(s));
	if (op == SS)
		return (ss_(s));
	if (op == PA)
		return (pa_(s));
	if (op == PB)
		return (pb_(s));
	if (op == RA)
		return (ra_(s));
	if (op == RB)
		return (rb_(s));
	if (op == RR)
		return (rr_(s));
	if (op == RRA)
		return (rra_(s));
	if (op == RRB)
		return (rrb_(s));
	if (op == RRR)
		return (rrr_(s));
	return (ERROR);
	print_stack(s);
}

int	print_stack(t_stack *s)
{
	int	i;

	i = -1;
	ft_printf("a  b\n");
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

int	execute_ops(t_stack *s)
{
	int	i;

	i = 0;
	while (s->ops_root + i < s->ops)
	{	
		ft_printf("doing: ");
		write_ops(s->ops_root[i]);
		if (do_op(s, s->ops_root[i++]))
			return (message_ret(ERROR, 2, "ops exe error"));
		print_stack(s);
	}
	i = 0;
	while (s->solution[i] == s->root_a[i] && i < s->size && s->root_a + i <= s->a)
		i++;
	if (DEBUG_TEST)
	{
		ft_printf("final stack state:\n");
		print_stack(s);
		ft_printf("evaluation: ");
	}
	if (i == s->size)
		return (SUCCESS);
	return (FAILURE);
}
