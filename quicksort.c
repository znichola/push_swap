/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:44 by znichola          #+#    #+#             */
/*   Updated: 2022/12/10 13:29:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	doaddopp(t_app *a, int opp)
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
	q->median = *start;
	q->mmedian = *end;
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
	// ft_printf("median:%d mmedian:%d sh_a:%d\n",
	// 	q.median, q.mmedian, sh(&a->s, 'a'));
	i = sh(&a->s, 'a');
	while (sh(&a->s, 'a') >= 4 && i--)
	{
		if (*a->s.a <= q.median)
		{
			doaddopp(a, PB);
			if (*a->s.b <= q.mmedian)
			{
				doaddopp(a, RB);
				// if (sh(&a->s, 'b') > 2 && a->s.b[0] < a->s.b[-1])
				// 	doaddopp(a, SB);
			}
		}
		else
			doaddopp(a, RA);
	}
	if (sh(&a->s, 'a') < 4)
	{
		// ft_printf("QUICK SORT RECURSION OUT!\n");
		sort3(a);
		quick_back(&q, a);
		return (SUCCESS);
	}
	// print_stack(&a->s);
	if (quicksort(a) != SUCCESS)
		return (ERROR);
	quick_back(&q, a);
	return (SUCCESS);
}

int	quick_back(t_qs *q, t_app *a)
{
	int	*next;
	int	*next_b;
	int	hight_b;
	// ft_printf("q  m:%d mm:%d\n", q->median, q->mmedian);
	while (sh(&a->s, 'b') > 2)
	{
		// hight_b = sh(&a->s, 'b');
		next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
		if (!next)
			return(message_ret(ERROR, "can't find a next in solution!"));
		next += 1;
		// next_b = findin_unsorted(next[1], a->s.b, hight_b);
		if (*next == *a->s.b)
			doaddopp(a, PA);
		else if (*next == *a->s.root_b)
			ft_printf("did a cool op\n") + doaddopp(a, RRB) + doaddopp(a, PA);
		else if (*next < q->median)
			doaddopp(a, RB);
		else // if (*next > q->mmedian)
			doaddopp(a, RRB);
		// print_stack(&a->s);
		// exit(0);
		if (*next > q->median)
			break ; 
	}
	for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
		write_op(a->s.o.root[i]);
	exit(0);
	// print_stack(&a->s);
	return (SUCCESS);
}
