/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops__0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:05 by znichola          #+#    #+#             */
/*   Updated: 2022/11/10 12:19:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** only stack opperation */

// do x and y at the same time
int	tg_(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *))
{
	if (x(s) + y(s) == FAILURE * 2)
	{
		write(1, &"warning: double fail .. impossible and dangerous\n", 50);
		return (FAILURE);
	}
	return (SUCCESS);
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	sa_(t_stack *s)
{
	int	t;

	if (!(sh(s, 'a') > 1))
		return (FAILURE);
	t = *(s->a);
	*(s->a) = *(s->a - 1);
	*(s->a - 1) = t;
	return (SUCCESS);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	sb_(t_stack *s)
{
	int	t;

	if (!(sh(s, 'b') > 1))
		return (FAILURE);
	t = *(s->b);
	*(s->b) = *(s->b - 1);
	*(s->b - 1) = t;
	return (SUCCESS);
}

// ss : sa and sb at the same time.
int	ss_(t_stack *s)
{
	return (tg_(s, sa_, sb_));
}
