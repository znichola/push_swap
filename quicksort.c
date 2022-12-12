/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:44 by znichola          #+#    #+#             */
/*   Updated: 2022/12/12 13:11:45 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dop(t_app *a, int opp)
{
	a->s.o.c += 1;
	*a->s.o.c = opp;
	return (a->opp_[opp](&a->s));
}

int	calc_pivot(t_qs *q, int *start, int *end)
{
	int	*list;
	int	i;

	*q = (t_qs){(*start), (*end)};
	if (start == end)
		return (SUCCESS);
	list = (int *)malloc(sizeof(int) * (end - start + 1));
	if (!list)
		return (ERROR);
	i = -1;
	while (start + i++ != end)
		list[i] = start[i];
	bubble_sort(list, i);
	if (end - start > 20)
		*q = (t_qs){(*(list + i / 6)), (*(list + i / 12))};
	else if (end - start <= 20 && start != end)
		*q = (t_qs){(*(list + i - 3)), (*(list + (i - 3) / 2))};
	return (freeret_1(SUCCESS, list));
}

int	quicksort(t_app *a)
{
	t_qs	q;
	int		i;

	i = sh(&a->s, 'a');
	if (i < 4)
	{
		// print_stack(&a->s);
		return (message_ret(ERROR, "\nhere out!\n") + sort3(a));
	}
	if (calc_pivot(&q, a->s.root_a, a->s.a) == ERROR)
		return (ERROR);
	while (i--)
	{
		if (*a->s.a < q.m)
		{
			dop(a, PB);
			if (*a->s.b <= q.mm)
				dop(a, RB);
		}
		else
			dop(a, RA);
	}
	if (quicksort(a) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
	// ft_printf("median:%d \nmmedian:%d \nsh_a:%d\n",
	// 	q.m, q.mm, sh(&a->s, 'a'));

// int	quick_back(t_qs *q, t_app *a)
// {
// 	int	*next;
// 	int	*next_b;
// 	int	hight_b;

// 	while (sh(&a->s, 'b') > 10)
// 	{
// 		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
// 		if (!next)
// 			return (message_ret(ERROR, "can't find a next in solution!"));
// 		next += 1;
// 		if (!(*next >= q->mm))
// 			break ;
// 		if (*next == *a->s.b)
// 			dop(a, PA);
// 		else if (*next >= q->m)
// 			dop(a, RRB);
// 		else
// 			dop(a, RB);
// 	}
// 	return (SUCCESS);
// }
		// ft_printf("q  m:%d mm:%d\n", q->m, q->mm);
		// printf("next is:%d\n", *next);
		// print_stack(&a->s);
		// next_b = findin_unsorted(next[1], a->s.b, hight_b);

static int	quick_back_helper(t_app *a, int *next, int op)
{
	
	while (*a->s.b != *next)
	{
		// ft_printf("going:"); write_op(op);
		// ft_printf("	before:%p op:%d", a->s.o.c, *a->s.o.c);
		// ft_printf("	status:%d", dop(a, op));
		// ft_printf("	after:%p op:%d\n", a->s.o.c, *a->s.o.c);
		dop(a, op);
	}
	// ft_printf("going:"); write_op(PA); ft_printf("	status:%d\n", dop(a, PA));
	dop(a, PA);
	return (SUCCESS);
}

int	quick_back2(t_app *a)
{
	int	*next;
	int	hight_b;
	int	*next_b;
	int	i;

	hight_b = sh(&a->s, 'b');
	while (hight_b > 4)
	{
		hight_b = sh(&a->s, 'b');
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (!next)
			return (message_ret(ERROR, "can't find a next in solution!"));
		if (next == a->s.r.solution)
			return (message_ret(ERROR, "next is solution!") + back_sort3(a));
		next += 1;
		next_b = findin_unsorted(*next, a->s.root_b, hight_b);
		if (!next_b)
			return (message_ret(ERROR, "can't find a next in stack b!"));
		i = next_b - a->s.root_b + 1;
		if (i > hight_b / 2)
			quick_back_helper(a, next, RB);
		else
			quick_back_helper(a, next, RRB);
		// write_ops_row(a); ft_printf("\n");
	}
	return (message_ret(SUCCESS, "finish quickback2!") + back_sort3(a));
}
		// ft_printf("next is:%d next_b:%d next_b-hight:%d\n",
		// *next, *next_b, next_b - a->s.root_b + 1);
		// print_stack(&a->s);
	// print_stack(&a->s);
	// for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
	// 	write_op_row(a->s.o.root[i]);