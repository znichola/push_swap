/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:58:14 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 14:38:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	pa(t_stack *s)
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
int	pb(t_stack *s)
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
int	ra(t_stack *s)
{
	int	t;

	if (sh(s, 'a') == 0)
		return (FAILURE);
	t = *s->a;
	*s->a = *s->root_a;
	*s->root_a = *s->a;
	return (SUCCESS);
}


// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb(t_stack *s)
{
	int	t;

	if (sh(s, 'b') == 0)
		return (FAILURE);
	t = *s->b;
	*s->b = *s->root_b;
	*s->root_b = *s->b;
	return (SUCCESS);
}

// rr : ra and rb at the same time.
int	rr(t_stack *s)
{
	return (tg(s, ra, rb));
}