/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/12 23:03:05 by znichola         ###   ########.fr       */
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
	quicksort(&app);
	if (quick_back2(&app) != SUCCESS)
		ft_printf("\nerror in quickback2!");
	// print_stack(&app.s);
	// write_ops_column(&app);
	// ft_printf("opps saved:%d\n", opmerg(&app.s.o, &app.s.new));
	// opmerg(&app.s.o, &app.s.new);
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
