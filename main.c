/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/12 13:02:11 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Recursive last huraa.
 * rerite to allow for proper function selection for recursive solving.
 *
*/

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_app	app;

	init_app(&app);
	input_check(process_inputdata(&app.s, av + 1, ac - 1), &app.s);
	// for (int i = app.s.size - 1; i >= 0; i--)
	// 	ft_printf("%d ", app.s.root_a[i]);
	quicksort(&app);
	// int i = -1;
	// while (i++ < 30)
	// {
	// 	if (app.s.root_a + i <= app.s.a)
	// 		ft_printf("%-2d", app.s.root_a[i]);
	// 	else
	// 		ft_printf("  ");
	// 	ft_printf(" ");
	// 	if (app.s.root_b + i <= app.s.b)
	// 		ft_printf("%-2d", app.s.root_b[i]);
	// 	ft_printf("\n");
	// }
	// print_stack(&app.s);
	if (quick_back2(&app) != SUCCESS)
		ft_printf("\nerror in quickback2!");
	// print_stack(&app.s);
	write_ops_column(&app);
	exit(0);
	return (0);
}
	// TODO trim the list of ops using some rules
	// consecutive ra followed by consecutive rb should be combined to rr
	// ra ra > rr
	// rra rrb > rrr
	// sa sb > ss
	// rb rb rb pa rrb rrb rbb pa rb rb rb
	// rb pa rrb pa rb
