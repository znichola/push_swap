/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_back3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:55:26 by znichola          #+#    #+#             */
/*   Updated: 2022/12/17 20:29:05 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_sorted(t_stack *s)
// {
// 	int	i;

// 	i = sh(s, 'a');
// 	while (i-- > 1)
// 		if (s->root_a[i] > s->root_a[i - 1])
// 			return (FAILURE);
// 	return (SUCCESS);
// }

static int	isreset(t_stack *s)
{
	if (*s->root_a == *s->r.solution)
		return (0);
	return (1);
}

int	backroot(t_app *a)
{
	while (isreset(&a->s))
		dop(a, RRA);
	return (SUCCESS);
}

static int	stay_looping(t_app *a)
{
	int	*next;

	next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
	if (!next)
		return (message_ret(ERROR, "can't find a next in solution!"));
	if (next == a->s.r.solution)
		return (message_ret(ERROR, "next is solution!")
			+ backroot(a) + back_sort3(a));
	next += 1;
	while (*next == *a->s.root_a)
	{
		dop(a, RRA);
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (!next)
			return (message_ret(ERROR, "can't find a next in solution!"));
		if (next == a->s.r.solution)
			return (message_ret(ERROR, "next is solution!")
				+ backroot(a) + back_sort3(a));
		next += 1;
	}
	return (SUCCESS);
}

static int	quick_back_helper3(t_app *a, int *next, int op)
{
	while (*a->s.b != *next)
	{
		if (*a->s.b < *a->s.a && !isreset(&a->s) && *a->s.b
			!= *next && *a->s.b > a->s.r.s_end[-3])
		{
			dop(a, PA);
			dop(a, RA);
		}
		else if (*a->s.b < *a->s.a && *a->s.b > *a->s.root_a
			&& *a->s.b != *next && *a->s.b > a->s.r.s_end[-3])
		{
			dop(a, PA);
			dop(a, RA);
		}
		else
			dop(a, op);
	}
	dop(a, PA);
	return (SUCCESS);
}

int	quick_back3(t_app *a)
{
	int	*next;
	int	hight_b;
	int	*next_b;

	hight_b = sh(&a->s, 'b');
	while (hight_b > 3)
	{
		hight_b = sh(&a->s, 'b');
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (qb3_helper(a, next) != SUCCESS)
			return (FAILURE);
		next += 1;
		if (*a->s.root_a == *next)
			qb3_helper2(a, next);
		next_b = findin_unsorted(*next, a->s.root_b, hight_b);
		if (!next_b)
			return (message_ret(ERROR, "can't find a next in stack b!"));
		if (next_b - a->s.root_b + 1 > hight_b / 2)
			quick_back_helper3(a, next, RB);
		else
			quick_back_helper3(a, next, RRB);
		stay_looping(a);
	}
	return (backroot(a) + back_sort3(a));
}
