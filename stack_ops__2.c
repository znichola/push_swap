/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops__2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:39 by znichola          #+#    #+#             */
/*   Updated: 2022/12/11 19:39:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
//TODO: ! some deep problem here! to come back to, make && ./push_swap 3 2 1
int	rra_(t_stack *s)
{
	int	t;
	int	h;
	int	i;

	h = sh(s, 'a');
	if (h < 3)
		return (FAILURE);
	t = *s->root_a;
	i = -1;
	while (++i < h - 1)
		s->root_a[i] = s->root_a[i + 1];
	*s->a = t;
	return (SUCCESS);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb_(t_stack *s)
{
	int	t;
	int	h;
	int	i;

	h = sh(s, 'b');
	if (h < 2)
		return (FAILURE);
	t = *s->root_b;
	i = -1;
	while (++i < h - 1)
		s->root_b[i] = s->root_b[i + 1];
	*s->b = t;
	return (SUCCESS);
}

// rrr : rra and rrb at the same time.
int	rrr_(t_stack *s)
{
	return (tg_(s, rra_, rrb_));
}

int	tt(t_stack *s)
{
	s->size = s->size;
	return (FAILURE);
}
