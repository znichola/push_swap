/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:11 by znichola          #+#    #+#             */
/*   Updated: 2022/12/11 01:08:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	sort2(t_app *a)
// {
// 	if (sh(&a->s, 'a') != 2)
// 		return (FAILURE);
// 	if (*a->s.root_a > *a->s.a)
// 		dop(a, SA);
// 	return (SUCCESS);
// }

int	sort3(t_app *a)
{
	if (sh(&a->s, 'a') == 1)
		return (SUCCESS);
	if (sh(&a->s, 'a') == 2)
	{
		if (*a->s.root_a < *a->s.a)
			dop(a, SA);
		return (SUCCESS);
	}
	if (sh(&a->s, 'a') != 3)
		return (FAILURE);
	if (a->s.a[0] < a->s.a[-1] && a->s.a[-1] < a->s.a[-2])
		return (SUCCESS);
	if (a->s.a[0] < a->s.a[-1] && a->s.a[0] < a->s.a[-2])
		return (dop(a, RRA) + dop(a, SA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[0] < a->s.a[-2])
		return(dop(a, SA));
	if (a->s.a[0] < a->s.a[-1] && a->s.a[0] > a->s.a[-2])
		return(dop(a, RRA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[-1] < a->s.a[-2])
		return(dop(a, RA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[0] > a->s.a[-2])
		return (dop(a, RA) + dop(a, SA));
	return (FAILURE);
}

int	back_sort3(t_app *a)
{
	if (sh(&a->s, 'b') == 1)
		return (dop(a, PA));
	if (sh(&a->s, 'b') == 2)
	{
		if (*a->s.root_b < *a->s.b)
			dop(a, SA);
		return (dop(a, PA) + dop(a, PA)); 
	}
	if (sh(&a->s, 'b') != 3)
		return (FAILURE);
	if (a->s.b[0] < a->s.b[-1] && a->s.b[-1] < a->s.b[-2])
		return (dop(a, RB) + dop(a, SB) + dop(a, PA) + dop(a, PA) + dop(a, PA));
	if (a->s.b[0] < a->s.b[-1] && a->s.b[0] < a->s.b[-2])
		return (dop(a, RB) + dop(a, PA) + dop(a, PA) + dop(a, PA));
	if (a->s.b[0] > a->s.b[-1] && a->s.b[0] < a->s.b[-2])
		return (dop(a, RRB) + dop(a, PA) + dop(a, PA) + dop(a, PA));
	if (a->s.b[0] < a->s.b[-1] && a->s.b[0] > a->s.b[-2])
		return (dop(a, SB) + dop(a, PA) + dop(a, PA) + dop(a, PA));
	if (a->s.b[0] > a->s.b[-1] && a->s.b[-1] < a->s.b[-2])
		return (dop(a, PA) + dop(a, RB) + dop(a, PA) + dop(a, PA));
	if (a->s.b[0] > a->s.b[-1] && a->s.b[0] > a->s.b[-2])
		return (dop(a, PA) + dop(a, PA) + dop(a, PA));
	return (FAILURE);
}