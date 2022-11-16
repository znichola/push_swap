/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:39 by znichola          #+#    #+#             */
/*   Updated: 2022/11/16 18:15:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wrapper: rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	rra(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RRA))
		return (FAILURE);
	if (rra_(s) == FAILURE)
		return (FAILURE);
	if (s->r.a_hight > 1)
		s->r.finish_me = RRA;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}

// wrapper: rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RRB))
		return (FAILURE);
	if (rrb_(s) == FAILURE)
		return (FAILURE);
	if (s->r.b_hight > 1)
		s->r.finish_me = RRB;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}

// wrapper: rrr : rra and rrb at the same time.
int	rrr(t_stack *s)
{
	if (!(s->r.finish_me == EMPTY || s->r.finish_me == RRR))
		return (FAILURE);
	if (tg(s, rra_, rrb_) == FAILURE)
		return (FAILURE);
	if (s->r.b_hight > 1 && s->r.a_hight > 1)
		s->r.finish_me = RRR;
	else
		s->r.finish_me = EMPTY;
	return (SUCCESS);
}

// TODO: maybe finish this ?
// int	continuity_wrapper(t_stack *s, int fnum, int (*x)(t_stack *))
// {
// 	if (!(s->r.finish_me == EMPTY || s->r.finish_me == fnum))
// 		return (FAILURE);
// 	if (rb_(s) == FAILURE)
// 		return (FAILURE);
// 	if (s->r.b_hight > 1)
// 		s->r.finish_me = fnum;
// 	else
// 		s->r.finish_me = EMPTY;
// 	return (SUCCESS);
// }