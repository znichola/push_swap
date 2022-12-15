/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_back3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:55:26 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 03:01:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *s)
{
	int	i;

	i = sh(s, 'a');
	while (i-- > 1)
		if (s->root_a[i] > s->root_a[i - 1])
			return (FAILURE);
	return (SUCCESS);
}

int	isreset(t_stack *s)
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

int	try(t_app *a, int *next)
{
	while (1)
	{
		if (*a->s.b < *a->s.a && *a->s.b > *a->s.root_a && *a->s.b != *next && *a->s.b > a->s.r.s_end[-3])
		{
			dop(a, PA);
			dop(a, RA);
			// ft_printf("2 a_root:%d\n", *a->s.root_a);
		}
		else 
			return (1);
	}
	
}

int	quick_back3(t_app *a)
{
	int	*next;
	int	hight_b;
	int	*next_b;
	int	i;

	hight_b = sh(&a->s, 'b');
	while (hight_b > 4 )// && check_sorted(&a->s) == )
	{
		hight_b = sh(&a->s, 'b');
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (!next)
			return (message_ret(ERROR, "can't find a next in solution!"));
		if (next == a->s.r.solution)
			return (message_ret(ERROR, "next is solution!") + backroot(a) + back_sort3(a));
		next += 1;
		if (*a->s.root_a == *next)
		{
			dop(a, RRA);
			// print_stack(&a->s);
			next += 1;
		}
		next_b = findin_unsorted(*next, a->s.root_b, hight_b);
		if (!next_b)
		{
			// dop(a, RRA);
			// ft_printf("a_root:%d next:%d\n", *a->s.root_a, *next);
			// print_stack(&a->s);
			// if (*a->s.root_a == *next)
			// 	dop(a, RRA);
			// print_stack(a);
			return (message_ret(ERROR, "can't find a next in stack b!"));
		}
		// above must remain
		


		// if (*a->s.root_a == *a->s.r.solution)
		if (*a->s.b < *a->s.a && !isreset(&a->s) && *a->s.b != *next && *a->s.b > a->s.r.s_end[-3])
		{
			dop(a, PA);
			dop(a, RA);
			// ft_printf("1 a_root:%d\n", *a->s.root_a);
		}
		// try(a, next);
		// if (*a->s.b < *a->s.a && *a->s.b > *a->s.root_a && *a->s.b != *next && *a->s.b > a->s.r.s_end[-3])
		// {
		// 	dop(a, PA);
		// 	dop(a, RA);
		// 	// ft_printf("2 a_root:%d\n", *a->s.root_a);
		// }
		i = next_b - a->s.root_b + 1;
		if (i > hight_b / 2)
			quick_back_helper(a, next, RB);
		else
			quick_back_helper(a, next, RRB);
		if (*a->s.root_a == *next)
		{
			ft_printf("bug!\n");
			dop(a, RRA);
		}

		// write_ops_row(a); ft_printf("\n");
	}
	return (message_ret(SUCCESS, "finish quickback2!") + backroot(a) + back_sort3(a));
}