/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:45:50 by znichola          #+#    #+#             */
/*   Updated: 2022/12/12 23:00:22 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	merg_test(int *op, int left, int right, int ret)
{
	if ((op[-1] == left && op[0] == right)
		|| (op[-1] == right && op[0] == left))
		return (ret);
	return (-1);
}

static void	addopp(t_ops *o, int opp)
{
	// ft_printf("merged: "); write_op(opp); ft_printf("\n");
	o->c += 1;
	*o->c = opp;
}

static void	addopps(t_ops *o, int opp1, int opp2)
{
	// ft_printf("trying to add: "); write_op(opp1); ft_printf(" "); write_op(opp2); ft_printf("\n");
	// ft_printf("skjdhf\n");
	o->c += 1;
	*o->c = opp1;
	o->c += 1;
	*o->c = opp2;
}

static int new_merged(t_ops *new, t_ops *o, int i, int ret)
{
	// if (ret == -1)
	// 	addopps(new, o->root[i - 1], o->root[i]);
	if (ret == -1)
		return (FAILIUR);
	// ft_printf("compressed "); write_op(ret); ft_printf("\n");
	addopp(new, ret);
	return (SUCCESS);
}

int	opmerg(t_ops *o, t_ops *new)
{
	int	h;
	int	i;
	
	h = o->c - o->root + 1;
	i = 0;
	while (i++ < h - 1)
	{
		// ft_printf("h:%d i:%d	", h, i - 1); write_op(o->root[i - 1]); ft_printf("	i:%d	", i); write_op(o->root[i]); ft_printf("\n");
		if (new_merged(new, o, i, merg_test(o->root + i, RA, RB, RR))
			+ new_merged(new, o, i, merg_test(o->root + i, RRA, RRB, RRR))
			+ new_merged(new, o, i, merg_test(o->root + i, SA, SB, SS))
			!= FAILIUR * 3)
			i = i + 1;
		else
			addopp(new, o->root[i - 1]);
		// i += 1;
	}
	// return ((o->c - o->root + 1) - (o->c - o->root + 1) - (new->c - new->root + 1));
	return ((o->c - o->root + 1) - (new->c - new->root + 1));
}
