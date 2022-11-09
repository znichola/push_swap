/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:23:26 by znichola          #+#    #+#             */
/*   Updated: 2022/11/09 17:25:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// typedef struct s_bt
// {
// 	int	data;
// 	t_bt	*right_node;
// 	t_bt	*left_node;
// } t_bt;

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

# ifndef DEPTH
#  define DEPTH 10
# endif

typedef struct s_stack
{
	int	size;
	int	*root_a;
	int	*root_b;
	int	*a;
	int	*b;
} t_stack;

typedef struct s_ops
{
	int	*root;
	int	*c;
} t_ops;

int	process_inputdata(t_stack *stack, char *str);

// stack ops 0
int	sh(t_stack *s, char x);
int	tg(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *));
int	sa(t_stack *s);
int	sb(t_stack *s);
int	ss(t_stack *s);

// stack ops 1
int	pa(t_stack *s);
int	pb(t_stack *s);
int	ra(t_stack *s);
int	rb(t_stack *s);
int	rr(t_stack *s);

// stack ops 2
int	rra(t_stack *s);
int	rrb(t_stack *s);
int	rrr(t_stack *s);

// recursive solver
int	init_ops(t_stack *s, t_ops *o);
int	write_op(int i);
int	recursive_solver(t_stack *s, t_ops *o, int *rs);

#endif /* push swap*/



// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.