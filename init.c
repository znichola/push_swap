/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:26 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 14:24:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	fill_opperations(op_array arr[OPS_NUM])
void	fill_opps(op_array *o)
{
	o[0] = sa;
	o[1] = sb;
	o[2] = ss;
	o[3] = pa;
	o[4] = pb;
	o[5] = ra;
	o[6] = rb;
	o[7] = rr;
	o[8] = rra;
	o[9] = rrb;
	o[10] = rrr;
}

void	fill_opps_(op_array *o)
{
	o[0] = sa_;
	o[1] = sb_;
	o[2] = ss_;
	o[3] = pa_;
	o[4] = pb_;
	o[5] = ra_;
	o[6] = rb_;
	o[7] = rr_;
	o[8] = rra_;
	o[9] = rrb_;
	o[10] = rrr_;
}

void	fill_undo(op_array *o)
{
	o[0] = sa_;
	o[1] = sb_;
	o[2] = ss_;
	o[3] = pb_;
	o[4] = pa_;
	o[5] = rra_;
	o[6] = rrb_;
	o[7] = rrr_;
	o[8] = ra_;
	o[9] = rb_;
	o[10] = rr_;
}

void	fill_mod(op_array *o)
{
	o[0] = sa_;
	o[1] = tt;
	o[2] = tt;
	o[3] = pa_;
	o[4] = pb_;
	o[5] = ra_;
	o[6] = tt;
	o[7] = tt;
	o[8] = rra_;
	o[9] = tt;
	o[10] = tt;
}

void	init_app(t_app *a)
{
	fill_opps(a->opp);
	fill_opps_(a->opp_);
	fill_undo(a->undo);
	fill_mod(a->opp_mod);
	a->max_depth = DEPTH;
	a->recursive_steps = 0;
	a->best_sol.root = (int *)malloc(sizeof(int) * OPS_NUM);
	// if (!a->best_sol.root)
		// return(NULL); //TODO: reactivate this malloc
	a->best_sol.c = a->best_sol.root;
}
