/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:05 by znichola          #+#    #+#             */
/*   Updated: 2022/11/10 13:49:49 by znichola         ###   ########.fr       */
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

/** wraper with recursion logic for stack _ops */

// wrapper: return the height of stack x
int	sh(t_stack *s, char x)
{
	if (x == 'a')
		return(s->a - s->root_a + 1);
	if (x == 'b')
		return(s->b - s->root_b + 1);
	return(ERROR);
}

// wrapper: do x and y at the same time
int	tg(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *))
{
	// int	q;

	// q = x(s);

	if (x(s) + y(s) == FAILURE * 2)
	{
		write(1, &"warning: double fail .. impossible and dangerous\n", 50);
		return (FAILURE);
	}
	return (SUCCESS);
}

// wrapper: Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	sa(t_stack *s)
{
	if (*(s->a - 1) < *(s->a))
		return (FAILURE);
	return (sa_(s));
}

// wrapper: sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	sb(t_stack *s)
{
	if (*(s->b - 1) < *(s->b))
		return (FAILURE);
	return (sb_(s));
}

// wrapper: ss : sa and sb at the same time.
int	ss(t_stack *s)
{
	if (*(s->a - 1) < *(s->a) && *(s->b - 1) < *(s->b)) //TODO: tg needs to be rewritten for this
		return (FAILURE);
	return (tg(s, sa_, sb_));
}
