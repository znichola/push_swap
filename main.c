/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 12:36:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * recursive try
 * 
*/

#include "push_swap.h"

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
	printf(" op:%d\n", op(s));
	printf("a	b\n");
	for (int i = 0; i < 4; i++)
	{
		if (s->root_a + i <= s->a)
			printf("%d", s->root_a[i]);
		printf("	");
		if (s->root_b + i <= s->b)
			printf("%d", s->root_b[i]);
		printf("\n");
	}
}

int main(int ac, char **av)
{
	t_stack	stack;
	process_inputdata(&stack, av[1]);
	// printf("opret:%d\n", sa(&stack));
	op_test(&stack, pa);
	printf("top of stack is:%d a len is:%d\n", *(stack.a), sh(&stack, 'a'));
	return (0);
}
