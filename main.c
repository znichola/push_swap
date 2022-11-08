/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 16:42:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * recursive try
 * 
*/

#include "push_swap.h"

int	sa(t_stack *s);
int	sb(t_stack *s);
int	ss(t_stack *s);

// stack ops 1
int	pa(t_stack *s);
int	pb(t_stack *s);
int	ra(t_stack *s);
int	rb(t_stack *s);
int	rr(t_stack *s);

// stack ops 2
int	rra(t_stack *s);
int	rrb(t_stack *s);
int	rrr(t_stack *s);

void op_test(t_stack *s, int (*op)(t_stack *))
{
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
	
	printf(" op:%d\n", op(s));
	printf("a	b\n");
	for (int i = 0; i < s->size; i++)
	{
		if (s->root_a + i <= s->a)
			printf("%d", s->root_a[i]);
		printf("	");
		if (s->root_b + i <= s->b)
			printf("%d", s->root_b[i]);
		printf("\n");
	}
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

int main(int ac, char **av)
{
	t_stack	stack;
	error_check(process_inputdata(&stack, av[1]), &stack);
	printf("process:%d\n", process_inputdata(&stack, av[1]));
	// printf("opret:%d\n", sa(&stack));
	op_test(&stack, pa);
	printf("top of stack is:%d a len is:%d\n", *(stack.a), sh(&stack, 'a'));
	error_check(2, &stack);
}
