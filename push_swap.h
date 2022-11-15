/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:23:26 by znichola          #+#    #+#             */
/*   Updated: 2022/11/14 10:16:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef DEPTH
#  define DEPTH 10
# endif

# define TEST

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

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


typedef struct s_run
{
	int	*solution;
	int	*a;
	int	*b;
	int	*sa;
	int	*sb;
	int	hight_a;
	int	hight_b;
} t_run;

typedef struct s_ops
{
	int	*root;
	int	*c;
} t_ops;

typedef struct s_stack
{
	int		size;
	int		*root_a;
	int		*root_b;
	int		*a;
	int		*b;
	t_run	r;
	t_ops	o; // chicken and egg problem also this is apointer so the real value needs to be initialised somewhere
} t_stack;

// function pointer
typedef int (*op_array)(t_stack *);

typedef struct s_oparrs
{
	op_array	opp[OPS_NUM];
	op_array	undo[OPS_NUM];
}t_oparrs;

int	process_inputdata(t_stack *stack, char *str);

// recursive solver
int	init_ops(t_stack *s);
int	write_op(int i);
int	do_next_op(t_stack *s, int i);
int	recursive_solver(t_stack *s, unsigned int *rs);

// util
int	message_ret(int sig, char *msg);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	freeret_1(int ret, void *x);
int	freeret_2(int ret, void *x, void *y);
int	freeret_3(int ret, void *x, void *y, void *z);

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

// stack ops _0
int	tg_(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *));
int	sa_(t_stack *s);
int	sb_(t_stack *s);
int	ss_(t_stack *s);

// stack ops _1
int	pa_(t_stack *s);
int	pb_(t_stack *s);
int	ra_(t_stack *s);
int	rb_(t_stack *s);
int	rr_(t_stack *s);

// stack ops _2
int	rra_(t_stack *s);
int	rrb_(t_stack *s);
int	rrr_(t_stack *s);

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