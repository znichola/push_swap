/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:56:49 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 04:03:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check overflow and underflow return is 0 if safe
// place the resul in a

static int	check_biga(int *a, int b)
{
	if (b == 0 || *a == 0)
	{
		*a = 0;
		return (SUCCESS);
	}
	if (*a > 0)
	{
		if (b > 0)
		{
			if (*a > (FT_INT_MAX / b))
				return (FAILURE);
		}
		else
			if ((b < 0) && b < (FT_INT_MIN / *a))
				return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_bigb(int *a, int b)
{
	if (!(*a > 0))
	{
		if (b > 0)
		{
			if (*a < (FT_INT_MIN / b))
				return (FAILURE);
		}
		else
			if (b < (FT_INT_MAX / *a))
				return (FAILURE);
	}
	return (SUCCESS);
}

int	safe_multi(int *a, int b)
{
	if (b == 0 || *a == 0)
	{
		*a = 0;
		return (SUCCESS);
	}
	if (check_biga(a, b) == FAILURE)
		return (FAILURE);
	if (check_bigb(a, b) == FAILURE)
		return (FAILURE);
	*a = *a * b;
	return (SUCCESS);
}

int	safe_add(int *a, int b)
{
	if (a > 0 && b > FT_INT_MAX - *a)
		return (FAILURE);
	else if (a < 0 && b < FT_INT_MIN - *a)
		return (FAILURE);
	*a = *a + b;
	return (SUCCESS);
}
