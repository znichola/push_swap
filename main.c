/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/17 23:06:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}

int	check_complete(t_stack *s)
{
	int	i;

	i = sh(s, 'a');
	if (i != s->size)
		return (FAILURE);
	while (i-- > 1)
		if (s->root_a[i] > s->root_a[i - 1])
			return (FAILURE);
	return (SUCCESS);
}

int	do_inputs(t_stack *stack, char **str, int n)
{
	if (n == 0)
		exit(0);
	else if (n == 1)
		return (process_inputdata_old(stack, *str));
	return (process_inputdata(stack, str, n));
}

int	main(int ac, char **av)
{
	t_app	app;

	init_app(&app);
	input_check(do_inputs(&app.s, av + 1, ac - 1));
	if (!check_complete(&app.s))
		exit(0);
	quicksort(&app);
	quick_back3(&app);
	if (app.s.o.c - app.s.o.root + 1 > 10)
	{
		opmerg(&app.s.o, &app.s.new);
		copyops_new_to_old(&app.s.o, &app.s.new);
	}
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
// python3 pyviz.py 4 67 3 87 23 99 10 TODO debug this!