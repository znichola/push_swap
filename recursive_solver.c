/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:59:56 by znichola          #+#    #+#             */
/*   Updated: 2022/11/09 17:29:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// resursilvy check all opoerations with the 
// given stack untill one yields a result below the depth threashold

int	init_ops(t_stack *s, t_ops *o)
{
	o->root = (int *)malloc(sizeof(int) * s->size * 4);
	if (!o)
		return (ERROR);
	o->c = o->root - 1;
	return (SUCCESS);
}

int	write_op(int i)
{
	if (i == 0)
		write(1, &"sa\n", 3);
	else if (i == 1)
		write(1, &"sb\n", 3);
	else if (i == 2)
		write(1, &"ss\n", 3);
	else if (i == 3)
		write(1, &"pa\n", 3);
	else if (i == 4)
		write(1, &"pb\n", 3);
	else if (i == 5)
		write(1, &"ra\n", 3);
	else if (i == 6)
		write(1, &"rb\n", 3);
	else if (i == 7)
		write(1, &"rr\n", 3);
	else if (i == 8)
		write(1, &"rra\n", 4);
	else if (i == 9)
		write(1, &"rrb\n", 4);
	else if (i == 10)
		write(1, &"rrr\n", 4);
	return (SUCCESS);
}

int	do_next_op(t_stack *s, int i)
{
	if (i == 0)
		return (sa(s));
	else if (i == 1)
		return (sb(s));
	else if (i == 2)
		return (ss(s));
	else if (i == 3)
		return (pa(s));
	else if (i == 4)
		return (pb(s));
	else if (i == 5)
		return (ra(s));
	else if (i == 6)
		return (rb(s));
	else if (i == 7)
		return (rr(s));
	else if (i == 8)
		return (rra(s));
	else if (i == 9)
		return (rrb(s));
	else if (i == 10)
		return (rrr(s));
	return (ERROR);
}

int	undo_op(t_stack *s, int i)
{
	if (i == 0)
		return (sa(s)); // sa checked
	else if (i == 1)
		return (sb(s)); // sb checked
	else if (i == 2)
		return (ss(s)); // ss checked
	else if (i == 3)
		return (pb(s)); // pa checked
	else if (i == 4)
		return (pa(s)); // pb checked
	else if (i == 5)
		return (rra(s)); 
	else if (i == 6)
		return (rrb(s));
	else if (i == 7)
		return (rrr(s));
	else if (i == 8)
		return (ra(s));
	else if (i == 9)
		return (rb(s));
	else if (i == 10)
		return (rr(s));
	return (ERROR);
}

int	check_complete(t_stack *s)
{
	int	i;

	i = sh(s, 'a');
	if (i != s->size)
		return (FAILURE);
	while (i-- > 1)
		if (s->root_a[i] > s->root_a[i - 1])
			return (FAILURE);
	return (SUCCESS);
}

int	recursive_solver(t_stack *s, t_ops *o, int *rs)
{
	int	i;

	if (check_complete(s) == SUCCESS)
		return (SUCCESS);
	if (o->c - o->root + 1 == DEPTH)
		return (FAILURE);
	i = -1;
	while (i++ <= 10)
	{
		if (do_next_op(s, i) == SUCCESS)
		{
			o->c += 1;
			*o->c = i;
			// printf("here depth:%d\n", o->c - o->root + 1);
			*rs += 1;
			if (recursive_solver(s, o, rs) == SUCCESS)
				return (SUCCESS); // SUCCESS
			// write(1, &"undoing ", 8);
			// write_op(i);
			if (undo_op(s, *o->c))
				return (ERROR);
			o->c -= 1;
		}
	}
	return (ERROR);
}