/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:44 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 23:41:51 by znichola         ###   ########.fr       */
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
	q->median.n = *start;
	q->median.p = findin_sorted(*start, a->s.r.solution, a->s.r.s_end);
	q->mmedian.n = *end;
	q->mmedian.p = findin_sorted(*end, a->s.r.solution, a->s.r.s_end);
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
	// ft_printf("median:%d mmedian:%d sh_a:%d len:%d\n",
	// 	q.median.n, q.mmedian.n, sh(&a->s, 'a'), q.median.p - a->s.root_a + 1);
	i = sh(&a->s, 'a');
	while (sh(&a->s, 'a') >= 4 && i--)
	{
		if (*a->s.a <= q.median.n)
		{
			doaddopp(a, PB);
			if (*a->s.b >= q.mmedian.n)
				doaddopp(a, RB);
		}
		else
			doaddopp(a, RA);
	}
	if (sh(&a->s, 'a') < 4)
	{
		// ft_printf("QUICK SORT RECURSION OUT!\n");
		return (sort3(a));
		return (0);
	}
	// print_stack(&a->s);
	if (quicksort(a) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

// int	quick_back(t_app *a)
// {
	
// }