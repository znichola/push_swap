/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:44 by znichola          #+#    #+#             */
/*   Updated: 2022/12/10 23:33:30 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dop(t_app *a, int opp)
{
	a->s.o.c += 1;
	*a->s.o.c = opp;
	return (a->opp_[opp](&a->s));
}

int	calc_median(t_app *a, t_qs *q, int *start, int *end)
{
	int	*list;
	int	i;
	
	if (start != end)
	{
		list = (int *)malloc(sizeof(int) * (end - start + 1));
		if (!list)
			return (ERROR);
		i = -1;
		while (start + i++ != end)
			list[i] = start[i];
		bubble_sort(list, i);
		start = list + i / 2;
		end = list + i / 4;
	}
	// ft_printf("calc median i:%d m:%d mm%d\n", i/2, *start, *end);
	q->m = *start;
	q->mm = *end;
	if (start == end)
		return (SUCCESS);
	return (freeret_1(SUCCESS, list));
}

int	quicksort(t_app *a)
{
	t_qs	q;
	int		i;
	
	if (calc_median(a, &q, a->s.root_a, a->s.a) == ERROR)
		return (ERROR);
	// ft_printf("median:%d \nmmedian:%d \nsh_a:%d\n",
	// 	q.m, q.mm, sh(&a->s, 'a'));
	i = sh(&a->s, 'a');
	if (i < 4)
	{
		// ft_printf("QUICK SORT RECURSION OUT!\n");
		sort3(a);
		// quick_back(&q, a);
		// print_stack(&a->s);
		return (SUCCESS);
	}
	while (/*sh(&a->s, 'a') >= 4 &&*/ i--)
	{
		if (*a->s.a < q.m)
		{
			dop(a, PB);
			if (*a->s.b <= q.mm)
			{
				dop(a, RB);
				// if (sh(&a->s, 'b') > 2 && a->s.b[0] < a->s.b[-1])
				// 	dop(a, SB);
			}
		}
		else
			dop(a, RA);
	}
	// print_stack(&a->s);
	// if (sh(&a->s, 'a') < 4)
	// {
	// 	// ft_printf("QUICK SORT RECURSION OUT!\n");
	// 	sort3(a);
	// 	// quick_back(&q, a);
	// 	return (SUCCESS);
	// }
	// print_stack(&a->s);
	if (quicksort(a) != SUCCESS)
		return (ERROR);
	// quick_back(&q, a);
	return (SUCCESS);
}

int	quick_back(t_qs *q, t_app *a)
{
	int	*next;
	int	*next_b;
	int	hight_b;
	// ft_printf("new quickback\n");
	while (sh(&a->s, 'b') > 10)
	{
		// hight_b = sh(&a->s, 'b');
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (!next)
			return(message_ret(ERROR, "can't find a next in solution!"));
		next += 1;
		// ft_printf("q  m:%d mm:%d\n", q->m, q->mm);
		// printf("next is:%d\n", *next);
		// print_stack(&a->s);
		// next_b = findin_unsorted(next[1], a->s.b, hight_b);
		if (!(*next >= q->mm))
			break;
		if (*next == *a->s.b)
			dop(a, PA);
		else if (*next >= q->m)
		{
			dop(a, RRB);
		}
		else
			dop(a, RB);
		
		// else if (!(*next >= q->mm && *next <= q->m))
			// break;
	}
	// for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
	// 	write_op(a->s.o.root[i]);
	// exit(0);
	// print_stack(&a->s);
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
			return(message_ret(ERROR, "can't find a next in solution!"));
		// ft_printf("behrw ");
		// ft_printf("next is:%d", *next);
		// ft_printf(" a.root_b:%d", *a->s.root_b);
		// ft_printf(" hight_b:%d\n", hight_b);
		if (next == a->s.r.solution)
			return (SUCCESS);
		next += 1;
		next_b = findin_unsorted(*next, a->s.root_b, hight_b);
		if (!next_b)
			return(message_ret(ERROR, "can't find a next in solution!"));
		i = next_b - a->s.root_b + 1;
		// ft_printf("next is:%d next_b:%d next_b-hight:%d\n", *next, *next_b, next_b - a->s.root_b + 1);
		// print_stack(&a->s);
		if (i > hight_b / 2)
		{
			while (*a->s.b != *next)
				dop(a, RB);
			dop(a, PA);
		}
		else
		{
			while (*a->s.b != *next)
				dop(a, RRB);
			dop(a, PA);
		}
		// print_stack(&a->s);
		// break;
	}
	return (SUCCESS);
}