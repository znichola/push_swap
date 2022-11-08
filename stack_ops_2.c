/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:39 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:03 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	rra(t_stack *s)
{
	int	t;

	if (sh(s, 'a') == 0)
		return (FAILURE);
	t = *s->root_a;
	*s->root_a = *s->a;
	*s->a = t;
	return (SUCCESS);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb(t_stack *s)
{
	int	t;

	if (sh(s, 'b') == 0)
		return (FAILURE);
	t = *s->root_b;
	*s->root_b = *s->b;
	*s->b = t;
	return (SUCCESS);
}

// rrr : rra and rrb at the same time.
int	rrr(t_stack *s)
{
	return (tg(s, ra, rb));
}