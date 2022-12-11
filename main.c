/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/11 17:45:24 by znichola         ###   ########.fr       */
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
	quick_back2(&app);
	// TODO trim the list of ops using some rules
	// consecutive ra followed by consecutive rb should be combined to rr
	// ra ra > rr
	// rra rrb > rrr
	// sa sb > ss
	// rb rb rb pa rrb rrb rbb pa rb rb rb
	// rb pa rrb pa rb
	write_ops_column(&app);
	return (0);
}
