/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/11/06 20:01:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * recursive try
 * 
*/

#include "push_swap.h"

int main(int ac, char **av)
{
	printf("hello world!\n");
	t_stack	stack;
	process_inputdata(&stack, av[1]);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", stack.a[i]);
	}
	return (0);
}
