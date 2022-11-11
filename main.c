/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/11/10 14:10:44 by znichola         ###   ########.fr       */
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
		printf("__");
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
	}
	if (ip == 2)
		exit(0);
	if (ip != 0)
	{
		write(2, &"Error\n", 7);
		exit(1);
	}
}

int	ops_executor(t_stack *s, t_ops *o, op_array op_arr[OPS_NUM])
{
	for (int i = 0; i < o->c - o->root + 1; i ++)
	{
		op_arr[o->root[i]](s);
		// do_next_op(s, o->root[i]);
		// write_op(o->root[i]);
		// op_test(s, op_arr[o->root[i]]);
	}
	return (SUCCESS);
}

int	fill_opperations(op_array arr[OPS_NUM])
{
	arr[0] = sa;
	arr[1] = sb;
	arr[2] = ss;
	arr[3] = pa;
	arr[4] = pb;
	arr[5] = ra;
	arr[6] = rb;
	arr[7] = rr;
	arr[8] = rra;
	arr[9] = rrb;
	arr[10] = rrr;
	return (SUCCESS);
}

int main(int ac, char **av)
{
	t_stack			stack;
	t_stack			dupe;
	t_ops			ops;
	op_array		op_arr[OPS_NUM];
	unsigned int	recursive_steps = 0;
	

	error_check(process_inputdata(&stack, av[1]), &stack);
	process_inputdata(&dupe, av[1]);
	init_ops(&stack, &ops);
	
	int rs = recursive_solver(&stack, &ops, &recursive_steps);
	fill_opperations(op_arr);
	
# ifdef TEST
	printf("recursion:%d\n", rs);
	op_test(&stack, tt);
	printf("it took %d steps and there are %d instructions\n", recursive_steps, ops.c - ops.root + 1);
	op_test(&dupe, tt);
	ops_executor(&dupe, &ops, op_arr);
# endif

	for (int i = 0; i < ops.c - ops.root + 1; i++)
		write_op(ops.root[i]);
	// printf("top of stack is:%d len_a:%d len_b:%d\n", *(stack.a), sh(&stack, 'a'), sh(&stack, 'b'));
	// error_check(2, &stack);
}
