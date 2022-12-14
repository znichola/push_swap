/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:56:08 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 05:22:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// assuming the list is biggest to smallest
int	*findin_sorted(int x, int *arr, int *arr_end)
{
	int	*t;

	t = arr + ((arr_end - arr) / 2);
	if (*arr_end == x)
		return (arr_end);
	if (*arr == x)
		return (arr);
	if (*t == x)
		return (t);
	if (arr_end - arr <= 1)
		return (NULL);
	if (*t > x)
		return (findin_sorted(x, t + 1, arr_end));
	return (findin_sorted(x, arr, t - 1));
}

int	*findin_unsorted(int x, int *arr, int size)
{
	while (size-- > 0)
		if (arr[size] == x)
			return (arr + size);
	return (NULL);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	f;
	int	t;

	f = 1;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			t = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = t;
			f = 0;
		}
		i++;
	}
	if (f == 1)
	{
		return ;
	}
	bubble_sort(tab, size);
}

int	qb3_helper(t_app *a, int *next)
{
	next = findin_sorted(*a->s.a, a->s.r.solution, a->s.r.s_end);
	if (!next)
		return (message_ret(ERROR, "can't find a next in solution!"));
	if (next == a->s.r.solution)
		return (message_ret(ERROR, "next is solution!")
			+ backroot(a) + back_sort3(a));
	return (SUCCESS);
}

void	qb3_helper2(t_app *a, int *next)
{
	dop(a, RRA);
	next += 1;
}
