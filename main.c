/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:49:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/10 13:20:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Recursive last huraa.
 * rerite to allow for proper function selection for recursive solving.
 * 
*/

#include "push_swap.h"

int main(int ac, char **av)
{
	t_app	app;
	
	init_app(&app);

	error_check(process_inputdata(&app.s, av + 1, ac - 1), &app.s);
	dupe_stack_a(&app.s, &app.d);
	// int rs = recursive_solver(&app);
	// int rs = slow_recursive_solver(&app);
	int rs = 0;

	// ft_printf("before stack\n");
	// print_stack(&app.s);
	quicksort(&app);
	// t_qs foo = {1, 1};
	// quick_back(&foo, &app);
	// TODO add back sorter!
	// app.s.o.rec_root = app.s.o.c;
	// app.s.size = sh(&app.s, 'a');
	// ft_printf("after stack\n");
	// print_stack(&app.s);
	// slow_recursive_solver(&app);
	for (int i = 0; i < app.s.o.c -app.s.o.root + 1; i++)
		write_op(app.s.o.root[i]);
		
// # undef TEST
// #define TEST
# ifdef TEST
	printf("recursion:%d\n", rs);
	op_test(&app.s, tt);
	printf("it took %d steps and there are %ld instructions\n", app.recursive_steps, app.best_sol.c - app.best_sol.root + 1);
	// process_inputdata(&dupe, av + 1, ac - 1);
	printf("test[%s]\n", av[1]);
	op_test(&app.d, tt);
	foo(&app.s, &app.d);
	ops_executor(&app); // TODO: it's buggged
	op_test(&app.d, tt);
	printf("\n");
# endif

	for (int i = 0; i < app.best_sol.c - app.best_sol.root + 1; i++)
		write_op(app.best_sol.root[i]);
	// printf("top of stack is:%d len_a:%d len_b:%d\n", *(stack.a), sh(&stack, 'a'), sh(&stack, 'b'));
	// error_check(2, &stack);
	return (0);
}
