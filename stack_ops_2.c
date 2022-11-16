/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:39 by znichola          #+#    #+#             */
/*   Updated: 2022/11/16 13:59:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wrapper: rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	rra(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (rra_(s));
}

// wrapper: rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (rrb_(s));
}

// wrapper: rrr : rra and rrb at the same time.
int	rrr(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (tg(s, rra_, rrb_));
}
