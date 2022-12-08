/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:59:56 by znichola          #+#    #+#             */
/*   Updated: 2022/12/08 13:52:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// resursilvy check all opoerations with the 
// given stack untill one yields a result below the depth threashold

int	write_op(int i)
{
	if (i == 0)
		write(1, &"sa\n", 3);
	else if (i == 1)
		write(1, &"sb\n", 3);
	else if (i == 2)
		write(1, &"ss\n", 3);
	else if (i == 3)
		write(1, &"pa\n", 3);
	else if (i == 4)
		write(1, &"pb\n", 3);
	else if (i == 5)
		write(1, &"ra\n", 3);
	else if (i == 6)
		write(1, &"rb\n", 3);
	else if (i == 7)
		write(1, &"rr\n", 3);
	else if (i == 8)
		write(1, &"rra\n", 4);
	else if (i == 9)
		write(1, &"rrb\n", 4);
	else if (i == 10)
		write(1, &"rrr\n", 4);
	return (SUCCESS);
}

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

int	recursive_solver(t_stack *s, unsigned int *rs)
{
	int	i;

	if (check_complete(s) == SUCCESS)
		return (SUCCESS);
	if (s->o.c - s->o.root + 1 == DEPTH)
		return (FAILURE);
	i = -1;
	while (i++ < OPS_NUM)
	{
		// TODO: make func to update the run information, used by next op
		if (do_next_op(s, i) == SUCCESS) //TODO:remove
		// if (o.op[i] == SUCCESS)
		{
			s->o.c += 1;
			*s->o.c = i;
			// printf("here depth:%d\n", o.c - o.root + 1);
			*rs += 1;
			if (recursive_solver(s, rs) == SUCCESS)
				return (SUCCESS); // SUCCESS
			// write(1, &"undoing ", 8); write_op(i);
			if (undo_op(s, *s->o.c)) // TODO: remove
			// if (o.ud[i] == SUCCESS)
				return (message_ret(ERROR, "undoing error\n"));
			/*TEST*/if (*s->o.c == s->r.finish_me)
				s->r.finish_me = EMPTY;
			s->o.c -= 1;
			
			// /*TEST*/if (s->o.c[-1] == RA && s->r.finish_me == RA)
			// 	printf("undid RA\n");
		}
	}
	return (ERROR);
}

