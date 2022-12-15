/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:54:15 by znichola          #+#    #+#             */
/*   Updated: 2022/12/07 09:21:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// TODO: for today
/**
 *  overall program flow
 * [x] args check
 * [x] process nums
 * [x] process ops
 * [x] check ops exicution
 * [x] display ops
 * [ ] something ..
 * 
 * [x] have a checker that i can test and works
 * [ ] write todo for the pushswap 
 */

int	main(int argc, char ** argv)
{
	t_stack	stack;
	
	if (argc != 3)
		return (message_ret(FAILURE, 1, "ags error"));
	if (process_input_nums(&stack, argv[2]))
		return (message_ret(1, 1, "num error"));
	if (process_input_ops(&stack, argv[1]))
		return(ft_freeret_3(0, stack.root_a, stack.root_b, stack.solution) + 
			message_ret(1, 1, "ops error"));
	if (DEBUG_TEST)
	{
		ft_printf("\nstack after process:\n");
		print_stack(&stack);
	}
	if (execute_ops(&stack) == SUCCESS)
		return (message_ret(SUCCESS, 1, "\033[32mOK\033[0m"));
	else
		return (message_ret(SUCCESS, 1, "\033[31mKO\033[0m"));
	ft_printf("test post\n");
	return (0);
}
 