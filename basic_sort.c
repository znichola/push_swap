/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:11 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 23:52:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	sort2(t_app *a)
// {
// 	if (sh(&a->s, 'a') != 2)
// 		return (FAILURE);
// 	if (*a->s.root_a > *a->s.a)
// 		doaddopp(a, SA);
// 	return (SUCCESS);
// }

int	sort3(t_app *a)
{
	if (sh(&a->s, 'a') == 1)
		return (SUCCESS);
	if (sh(&a->s, 'a') == 2)
	{
		if (*a->s.root_a > *a->s.a)
			doaddopp(a, SA);
		return (SUCCESS);
	}
	if (sh(&a->s, 'a') != 3)
		return (FAILURE);
	if (a->s.a[0] < a->s.a[-1] && a->s.a[-1] < a->s.a[-2])
		return (SUCCESS);
	if (a->s.a[0] < a->s.a[-1] && a->s.a[0] < a->s.a[-2])
		return (doaddopp(a, RRA) + doaddopp(a, SA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[0] < a->s.a[-2])
		return(doaddopp(a, SA));
	if (a->s.a[0] < a->s.a[-1] && a->s.a[0] > a->s.a[-2])
		return(doaddopp(a, RRA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[-1] < a->s.a[-2])
		return(doaddopp(a, RA));
	if (a->s.a[0] > a->s.a[-1] && a->s.a[0] > a->s.a[-2])
		return (doaddopp(a, RA) + doaddopp(a, SA));
	return (FAILURE);
}
