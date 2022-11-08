/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:05 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 14:38:10 by znichola         ###   ########.fr       */
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

// return the height of stack x
int	sh(t_stack *s, char x)
{
	if (x == 'a')
		return(s->a - s->root_a + 1);
	if (x == 'b')
		return(s->b - s->root_b + 1);
	return(ERROR);
}

// do x and y at the same time
int	tg(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *))
{
	if (x(s) + y(s) == FAILURE * 2)
	{
		write(1, &"double fail, impossible\n", 24);
		return (FAILURE);
	}
	return (SUCCESS);
}

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
	return (tg(s, sa, sb));
}
