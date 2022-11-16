/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:58:14 by znichola          #+#    #+#             */
/*   Updated: 2022/11/16 19:06:08 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wrapper: pa (push a): Take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.
int	pa(t_stack *s)
{
	if (s->r.finish_me != EMPTY)
		return (FAILURE);
	// printf("we have data available\n");
	// for (int i = 0; i < s->size; i++)
	// 	printf("%d\n", s->r.solution[i]);
	// printf("solution pointer:%p n:%d\n", s->r.a, *s->r.a);
	// exit(1);
	// check if push breaks the order
	
	return (pa_(s));
}

// int	pa(t_stack *s)
// {
// 	if (!(s->r.finish_me == EMPTY || s->r.finish_me == PA))
// 		return (FAILURE);
// 	if (pa_(s) == FAILURE)
// 		return (FAILURE);
// 	if (s->r.b_hight > 1)
// 		s->r.finish_me = PA;
// 	else
// 		s->r.finish_me = EMPTY;
// 	return (SUCCESS);
// }

// wrapper: pb (push b): Take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.
int	pb(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY))
		return (FAILURE);
	return (pb_(s));
}

// int	pb(t_stack *s)
// {
// 	if (!(s->r.finish_me == EMPTY || s->r.finish_me == PB))
// 		return (FAILURE);
// 	if (pa_(s) == FAILURE)
// 		return (FAILURE);
// 	if (s->r.a_hight > 1)
// 		s->r.finish_me = PB;
// 	else
// 		s->r.finish_me = EMPTY;
// 	return (SUCCESS);
// }

// wrapper: ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ra(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RA))
		return (FAILURE);
	if (ra_(s) == FAILURE)
		return (FAILURE);
	if (s->r.a_hight > 1)
		s->r.finish_me = RA;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}

// TODO: these two functions, they are horribly slow, 
// I think, will see about optimisation later


// wrapper: rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RB))
		return (FAILURE);
	if (rb_(s) == FAILURE)
		return (FAILURE);
	if (s->r.b_hight > 1)
		s->r.finish_me = RB;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}

// wrapper: rr : ra and rb at the same time.
int	rr(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RR))
		return (FAILURE);
	if (tg(s, ra_, rb_) == FAILURE)
		return (FAILURE);
	if (s->r.b_hight > 1 && s->r.a_hight > 1)
		s->r.finish_me = RR;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}
