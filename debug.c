/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:09:04 by znichola          #+#    #+#             */
/*   Updated: 2022/12/08 16:38:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void op_test(t_stack *s, int (*op)(t_stack *))
{
	printf("\n");
	if (op == sa)
		printf("sa");
	else if (op == sb)
		printf("sb");
	else if (op == ss)
		printf("ss");
	else if (op == pa)
		printf("pa");
	else if (op == pb)
		printf("pb");
	else if (op == ra)
		printf("ra");
	else if (op == rb)
		printf("rb");
	else if (op == rr)
		printf("rr");
	else if (op == rra)
		printf("rra");
	else if (op == rrb)
		printf("rrb");
	else if (op == rrr)
		printf("rrr");
	else if (op == tt)
		printf("tt");
	printf(":%d\n", op(s));
	// for (int i = s->size - 1; i >= 0; i--)
	for (int i = 0; i < s->size; i++)
	{
		if (s->root_a + i <= s->a)
			printf("%-2d", s->root_a[i]);
		printf(" ");
		if (s->root_b + i <= s->b)
			printf("%-2d", s->root_b[i]);
		printf("\n");
	}
	printf("_   _\na   b\n");
}

// TODO: rename this
void	error_check(int ip, t_stack *s)
{
	if (ip == FAILURE || ip == 2)
	{
		free(s->root_a);
		free(s->root_b); 
		// free(s->r.solution);
		// free(s->o.root);
	}
	if (ip == 2)
		exit(0);
	if (ip != 0)
	{
		write(2, &"Error\n", 7);
		exit(1);
	}
}

int	ops_executor(t_stack *s, op_array *opp)
{
	for (int i = 0; i < s->o.c - s->o.root + 1; i ++)
	{
		// printf("\ni:%d %d\n\n", i, i);
		opp[s->o.root[i]](s);
		// do_next_op(s, o->root[i]);
		// write_op(s->o->root[i]);
		// op_test(s, op_arr[o->root[i]]);
	}
	return (SUCCESS);
}

int	foo(t_stack *s, t_stack *d)
{
	d->r.solution = s->r.solution;
	d->o.root = s->o.root;
	d->o.c = s->o.c;
	return (0);
}

int	dupe_stack_a(t_stack *s, t_stack *d)
{
	int	i;

	d->size = s->size;
	d->root_a = (int *)malloc(sizeof(int) * d->size);
	if (!d->root_a)
		return (ERROR);
	d->root_b = (int *)malloc(sizeof(int) * d->size);
	if (!d->root_b)
		return (freeret_1(ERROR, d->root_a));
	i = -1;
	while (i++ < s->size - 1)
		d->root_a[i] = s->root_a[i];
	d->a = d->root_a + i - 1;
	d->b = d->root_b - 1;
	return (0);
}