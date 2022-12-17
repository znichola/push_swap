/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:32:41 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 17:42:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// # include "../push_swap/push_swap.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEBUG 

# include "../libft/libft.h"

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1
# define EMPTY -1

# define SA 0 
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define OPS_NUM 11

typedef struct s_stack
{
	int		size;
	int		*root_a;
	int		*root_b;
	int		*a;
	int		*b;
	int		*solution;
	int		*ops;
	int		*ops_root;
}	t_stack;

int		process_inputdata(t_stack *stack, char **str, int n);

int		safe_add(int *a, int b);
int		safe_multi(int *a, int b);

int		freeret_1(int ret, void *x);
int		freeret_2(int ret, void *x, void *y);
int		freeret_3(int ret, void *x, void *y, void *z);

// // stack ops _0
int		sh(t_stack *s, char x);
int		tg_(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *));
int		sa_(t_stack *s);
int		sb_(t_stack *s);
int		ss_(t_stack *s);

// stack ops _1
int		pa_(t_stack *s);
int		pb_(t_stack *s);
int		ra_(t_stack *s);
int		rb_(t_stack *s);
int		rr_(t_stack *s);

// stack ops _2
int		rra_(t_stack *s);
int		rrb_(t_stack *s);
int		rrr_(t_stack *s);

#endif /* checker */
