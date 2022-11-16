/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:58:14 by znichola          #+#    #+#             */
/*   Updated: 2022/11/16 13:58:33 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wrapper: pa (push a): Take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.
int	pa(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	// printf("we have data available\n");
	// for (int i = 0; i < s->size; i++)
	// 	printf("%d\n", s->r.solution[i]);
	// printf("solution pointer:%p n:%d\n", s->r.a, *s->r.a);
	// exit(1);
	// check if push breaks the order
	
	return (pa_(s));
}

// wrapper: pb (push b): Take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.
int	pb(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (pb_(s));
}

// wrapper: ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ra(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (ra_(s));
}

// TODO: these two functions, they are horribly slow, 
// I think, will see about optimisation later


// wrapper: rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (rb_(s));
}

// wrapper: rr : ra and rb at the same time.
int	rr(t_stack *s)
{
	if (s->r.completion != EMPTY)
		return (FAILURE);
	return (tg(s, ra_, rb_));
}
