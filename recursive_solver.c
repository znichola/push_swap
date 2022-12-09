/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:59:56 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 00:51:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// resursilvy check all opoerations with the 
// given stack untill one yields a result below the depth threashold

int	update_run(t_stack *s, int blh)
{
	int	i;

	// printf("a:%d sol:%d end%d\n", *s->a, *s->r.solution, *s->r.s_end);
	// for (int i = 0; i < s->size; i++)
	// 	printf("%d\n", s->r.solution[i]);

	// printf("some answer:%d\n", *findin_sorted(*s->a, s->r.solution, s->r.s_end));
	// exit(0);
	s->r.a = findin_sorted(*s->a, s->r.solution, s->r.s_end);
	s->r.b = findin_sorted(*s->b, s->r.solution, s->r.s_end);
	i = 0;
	while (s->r.a - i >= s->r.solution && s->r.a[-i] == s->a[-i])
		i++;
	// printf("wker\n");
	s->r.a_hight = i;
	i = 0;
	while (s->r.b - i >= s->r.solution && s->r.b[-i] == s->b[-i])
		i++;
	s->r.b_hight = i;
	// if (s->r.a_hight >= 6)
	// {
	// 	printf("blh:%d a:%d s0:%d sa:%d height:%d", blh, s->a[0], s->r.solution[0], s->r.a[0], s->r.a_hight);
	// 	op_test(s, tt);
	// 	printf("\n");
	// }
	// TODO: easy optimisation record the current solution op index, and compare if it's changed then run this op, might cause bugs idk.
	// s->r.a;
	return (0);
}

// can probably remove
int	do_next_op(t_stack *s, int i)
{
	update_run(s, i);
	if (i == SA)
		return (sa(s));
	else if (i == SB)
		return (sb(s));
	else if (i == SS)
		return (ss(s));
	else if (i == PA)
		return (pa(s));
	else if (i == PB)
		return (pb(s));
	else if (i == RA)
		return (ra(s));
	else if (i == RB)
		return (rb(s));
	else if (i == RR)
		return (rr(s));
	else if (i == RRA)
		return (rra(s));
	else if (i == RRB)
		return (rrb(s));
	else if (i == RRR)
		return (rrr(s));
	return (ERROR);
}

// can probably remove
int	undo_op(t_stack *s, int i)
{
	if (i == SA)
		return (sa_(s)); // sa checked
	else if (i == SB)
		return (sb_(s)); // sb checked
	else if (i == SS)
		return (ss_(s)); // ss checked
	else if (i == PA)
		return (pb_(s)); // pa checked
	else if (i == PB)
		return (pa_(s)); // pb checked
	else if (i == RA)
		return (rra_(s)); 
	else if (i == RB)
		return (rrb_(s));
	else if (i == RR)
		return (rrr_(s));
	else if (i == RRA)
		return (ra_(s));
	else if (i == RRB)
		return (rb_(s));
	else if (i == RRR)
		return (rr_(s));
	return (ERROR);
}

// TODO: funciton to update run information, used in next op.

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

int	recursive_solver(t_app *a)
{
	int	i;

	if (check_complete(&a->s) == SUCCESS)
		return (SUCCESS);
	if (a->s.o.c - a->s.o.root + 1 == DEPTH)
		return (FAILURE);
	i = -1;
	while (i++ < OPS_NUM)
	{
		// printf("op adress:%p\n", &a->opp[i]);
		// TODO: make func to update the run information, used by next op
		// if (do_next_op(&a->s, i) == SUCCESS) //TODO:remove
		// printf("lsdf\n");
		// print_stack(&a->s);
		
		if (a->opp_[i](&a->s) == SUCCESS)
		{
			a->s.o.c += 1;
			*a->s.o.c = i;
			// printf("here depth:%d\n", (int)a->s.o.c - (int)a->s.o.root + 1);
			a->recursive_steps += 1;
			if (recursive_solver(a) == SUCCESS)
				return (SUCCESS); // SUCCESS
			// write(1, &"undoing ", 8); write_op(i);
			
			if (a->undo[i](&a->s))
			// if (undo_op(&a->s, *a->s.o.c)) // TODO: remove
			// if (o.ud[i] == SUCCESS)
			/*TEST*/if (*a->s.o.c == a->s.r.finish_me)
				a->s.r.finish_me = EMPTY;
			a->s.o.c -= 1;
			// /*TEST*/if (s->o.c[-1] == RA && s->r.finish_me == RA)
			// 	printf("undid RA\n");
		}
	}
	return (ERROR);
}

