/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops__1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:58:14 by znichola          #+#    #+#             */
/*   Updated: 2022/11/10 12:06:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	pa_(t_stack *s)
{
	if (sh(s, 'b') == 0)
		return (FAILURE);
	s->a += 1;
	*s->a = *s->b;
	s->b -= 1;
	return (SUCCESS);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	pb_(t_stack *s)
{
	if (sh(s, 'a') == 0)
		return (FAILURE);
	s->b += 1;
	*s->b = *s->a;
	s->a -= 1;
	return (SUCCESS);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ra_(t_stack *s)
{
	int	t;
	int	h;
	
	h = sh(s, 'a');
	if (h <= 1)
		return (FAILURE);
	t = *s->a;
	while (h-- > 0)
		s->root_a[h] = s->root_a[h - 1];
	*s->root_a = t;
	return (SUCCESS);
}

// TODO: these two functions are horribly slow, 
// I think, will see about optimisation later


// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb_(t_stack *s)
{
	int	t;
	int	h;
	
	h = sh(s, 'b');
	if (h <= 1)
		return (FAILURE);
	t = *s->b;
	while (h-- > 0)
		s->root_b[h] = s->root_b[h - 1];
	*s->root_b = t;
	return (SUCCESS);
}

// rr : ra and rb at the same time.
int	rr_(t_stack *s)
{
	return (tg_(s, ra_, rb_));
}
