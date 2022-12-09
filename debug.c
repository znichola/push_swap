/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:09:04 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 20:21:25 by znichola         ###   ########.fr       */
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

int	ops_executor(t_app *a)
{
	for (int i = 0; i < a->d.o.c - a->d.o.root + 1; i ++)
	{
		// printf("i:%d ", i);
		// print_stack(&a->d);
		write_op(a->best_sol.root[i]);
		a->opp[a->best_sol.root[i]](&a->d);
	}

	// for (int i = 0; i < s->o.c - s->o.root + 1; i ++)
	// {
	// 	// printf("\ni:%d %d\n\n", i, i);
	// 	opp[s->o.root[i]](s);
	// 	// do_next_op(s, o->root[i]);
	// 	// write_op(s->o->root[i]);
	// 	// op_test(s, op_arr[o->root[i]]);
	// }
	return (SUCCESS);
}

// TODO: remove redundent function
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

void	write_op_row(int i)
{
	if (i == SA)
		ft_printf("sa");
	else if (i == SB)
		ft_printf("sb");
	else if (i == SS)
		ft_printf("ss");
	else if (i == PA)
		ft_printf("pa");
	else if (i == PB)
		ft_printf("pb");
	else if (i == RA)
		ft_printf("ra");
	else if (i == RB)
		ft_printf("rb");
	else if (i == RR)
		ft_printf("rr");
	else if (i == RRA)
		ft_printf("rra");
	else if (i == RRB)
		ft_printf("rrb");
	else if (i == RR)
		ft_printf("rrr");
	ft_printf(" ");
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