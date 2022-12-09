/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops__0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:05 by znichola          #+#    #+#             */
/*   Updated: 2022/12/08 18:54:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** only stack opperation */

// do x and y at the same time
int	tg_(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *))
{
	if (x(s) + y(s) == FAILURE * 2)
	{
		// write(1, &"_warning: double fail .. impossible and dangerous\n", 51); //TODO: important things happen here
		return (FAILURE);
	}
	return (SUCCESS);
}
// this funciton above is liable to be tricky
// must be carefull to understand it's output
// if there are 3 numbers or less it will always trigger the double fail.
// don't get fooled by this again!

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

	// ft_printf("ksjhdf\n");
	// print_stack(s);
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
