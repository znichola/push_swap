/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_recursive_solver.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:33:43 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 14:40:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	slow_optimiser(t_app *a)
{
	a->max_depth = a->s.o.c - a->s.o.root;

	if (DEBUG_TEST)
	{
		ft_printf("\nsolution < steps:%d depth:%d >",
		a->recursive_steps, a->s.o.c - a->s.o.root + 1);
		for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
		{
			write_op_row(a->s.o.root[i]);
		}
		ft_printf("\n");
	}
	// return (slow_recursive_solver(a));
	return (0);
}

int	copy_solution(t_app *a)
{
	int	i;

	i = a->s.o.c - a->s.o.root + 1;
	a->best_sol.c = a->best_sol.root + i - 1;
	while(i--)
	{
		a->best_sol.root[i] = a->s.o.root[i];
	}
	return(0);
}

// #ifndef DEBUG
// # define DEBUG
// #endif
// #undef DEBUG_TEST
// #define DEBUG_TEST 1

int	slow_recursive_solver(t_app *a)
{
	int	i;

	if (a->s.o.c - a->s.o.root + 1 == a->max_depth)
		return (FAILURE);
	if (check_complete(&a->s) == SUCCESS)
		return (SUCCESS);
	i = -1;
	// if (DEBUG_TEST)
	// {
	// 	ft_printf("\n");
	// 	for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
	// 		ft_printf(" ");
	// 	ft_printf("%d: ", a->s.o.c - a->s.o.root + 1);
	// }
	while (++i < OPS_NUM)
	{
		// ft_printf("%d \n", i);
		if (a->opp_mod[i](&a->s) == SUCCESS)
		{
			// ft_printf("%d \n", i);
			// if (DEBUG_TEST)
			// {
				// if (a->s.o.c - a->s.o.root + 1 != a->max_depth - 1)
					ft_printf("\n");
				for (int i = 0; i < a->s.o.c - a->s.o.root + 1; i++)
					ft_printf(" ");
				// if (a->s.o.c - a->s.o.root + 1 != a->max_depth - 1)
					ft_printf("%d: ", a->s.o.c - a->s.o.root + 1);
				write_op_row(i);
			// }
			// if (DEBUG_TEST) {ft_printf("%d:", i); write_op_row(i); }
			// ft_printf("%d ", i);
			a->s.o.c += 1;
 			*a->s.o.c = i;
			a->recursive_steps += 1;
			if (slow_recursive_solver(a) == SUCCESS)
			{
				copy_solution(a);
				// if (DEBUG_TEST)
				// {
				// 	ft_printf("\nsolution copy :			   ");
				// 	for (int i = 0; i < a->best_sol.c - a->best_sol.root + 1; i++)
				// 	{
				// 		write_op_row(a->best_sol.root[i]);
				// 	}
				// }
				slow_optimiser(a);
				if (a->undo[i](&a->s))
					return (ft_printf("steps:%u i:%d ", a->recursive_steps, i)
						+ message_ret(ERROR, "undoing error\n"));
				a->s.o.c -= 1;
				return(FAILIUR);
			}
			if (a->undo[i](&a->s))
				return (ft_printf("steps:%u i:%d ", a->recursive_steps, i)
					+ message_ret(ERROR, "undoing error\n"));
			a->s.o.c -= 1;
		}
	}
	return (ERROR);
}
