/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:05 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 11:00:17 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * stack data structure
 * stack a
 * stack b
 * an array of ints, 
*/

/**
 * 4
 * 2
 * 9
 * 8
 * 7
 * 1
 * 5 <- top of stack
*/

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	sa(t_stack *s)
{
	int	t;

	if (!(sh(s, 'a') > 1))
		return (FAILURE);
	t = *(s->a);
	*(s->a) = *(s->a - 1);
	*(s->a - 1) = t;
	return (SUCCESS);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	sb(t_stack *s)
{
	int	t;

	if (!(sh(s, 'b') > 1))
		return (FAILURE);
	t = *(s->b);
	*(s->b) = *(s->b - 1);
	*(s->b - 1) = t;
	return (SUCCESS);
}

// ss : sa and sb at the same time.
int	ss(t_stack *s)
{
	int	t;

	t = sb(s);
	if (sa(s) && t)
		return (FAILURE); //should be impossible
	return (SUCCESS);
	// return (sa(s) + sb(s));
}

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
