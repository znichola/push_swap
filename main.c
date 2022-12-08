/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/08 14:16:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * recursive try
 * 
*/

#include "push_swap.h"

int	tt(t_stack *s)
{
	return(0);
}

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

int	ops_executor(t_stack *s, t_oparrs *op_arr)
{
	for (int i = 0; i < s->o.c - s->o.root + 1; i ++)
	{
		// printf("\ni:%d %d\n\n", i, i);
		op_arr->opp[s->o.root[i]](s);
		// do_next_op(s, o->root[i]);
		// write_op(s->o->root[i]);
		// op_test(s, op_arr[o->root[i]]);
	}
	return (SUCCESS);
}

// int	fill_opperations(op_array arr[OPS_NUM])
int	fill_opperations(t_oparrs *o)
{
	o->opp[0] = sa;
	o->opp[1] = sb;
	o->opp[2] = ss;
	o->opp[3] = pa;
	o->opp[4] = pb;
	o->opp[5] = ra;
	o->opp[6] = rb;
	o->opp[7] = rr;
	o->opp[8] = rra;
	o->opp[9] = rrb;
	o->opp[10] = rrr;
	o->undo[0] = sa_;
	o->undo[1] = sb_;
	o->undo[2] = ss_;
	o->undo[3] = pb_;
	o->undo[4] = pa_;
	o->undo[5] = rra_;
	o->undo[6] = rrb_;
	o->undo[7] = rrr_;
	o->undo[8] = ra_;
	o->undo[9] = rb_;
	o->undo[10] = rr_;
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

int main(int ac, char **av)
{
	t_stack			stack;
	t_stack			dupe;
	t_oparrs		op_arr;
	unsigned int	recursive_steps = 0;

	error_check(process_inputdata(&stack, av + 1, ac - 1), &stack);
	fill_opperations(&op_arr);
	dupe_stack_a(&stack, &dupe);
	int rs = recursive_solver(&stack, &recursive_steps);

# ifdef TEST
	printf("recursion:%d\n", rs);
	op_test(&stack, tt);
	printf("it took %d steps and there are %ld instructions\n", recursive_steps, stack.o.c - stack.o.root + 1);
	// process_inputdata(&dupe, av + 1, ac - 1);
	printf("test[%s]\n", av[1]);
	op_test(&dupe, tt);
	foo(&stack, &dupe);
	ops_executor(&dupe, &op_arr);
	op_test(&dupe, tt);
	printf("\n");
# endif

	for (int i = 0; i < stack.o.c - stack.o.root + 1; i++)
		write_op(stack.o.root[i]);
	// printf("top of stack is:%d len_a:%d len_b:%d\n", *(stack.a), sh(&stack, 'a'), sh(&stack, 'b'));
	// error_check(2, &stack);
	return (0);
}
