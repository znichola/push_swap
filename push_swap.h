/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:33:30 by znichola          #+#    #+#             */
/*   Updated: 2022/12/14 17:02:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

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

# define FT_INT_MAX 0x7fffffff
# define FT_INT_MIN (-1-0x7fffffff)

typedef struct s_run
{
	int	*solution;
	int	*s_end;
}	t_run;

typedef struct s_trim
{
	int	rb_s;
	int	rrb_s;
}	t_trim;

typedef struct s_ops
{
	int	*root;
	int	*c;
}	t_ops;

typedef struct s_qs
{
	int	m;
	int	mm;
}	t_qs;

typedef struct s_stack
{
	int		size;
	int		*root_a;
	int		*root_b;
	int		*a;
	int		*b;
	t_qs	pivot;
	t_run	r;
	t_ops	o;
	t_ops	new;
}	t_stack;
// chicken and egg problem also this is apointer so the
// real value needs to be initialised somewhere

/* main */
void	exit_error(int code);

/* function pointer */
typedef int	(*t_op_array)(t_stack *);

typedef struct s_app
{
	t_stack			s;
	t_op_array		opp_[OPS_NUM];
	t_op_array		undo[OPS_NUM];
	t_op_array		opp_mod[OPS_NUM];
}	t_app;


/* process inputdata */

int		ft_atoi_read(int *n, char **str);
int		init_ops(t_stack *s);
int		finish_setup(t_stack *s);
int		process_inputdata(t_stack *stack, char **str, int n);

/* process inputdate 2 */

int		find_solution(t_stack *s);
int		process_inputdata_old(t_stack *stack, char *str);

/* init */

void	init_app(t_app *a);

/* quicksort */

int		dop(t_app *a, int opp);
int		calc_pivot(t_app *a, t_qs *q, int *start, int *end);
int		quicksort(t_app *a);
// int		quick_back(t_qs *q, t_app *a);
int		quick_back_helper(t_app *a, int *next, int op);
int		quick_back2(t_app *a);
/* quick_back3 */

int	quick_back3(t_app *a);

/* basic sort */

int		sort3(t_app *a);
int		back_sort3(t_app *a);

/* stack data */

int		print_stack(t_stack *s);

/* merg */

int		opmerg(t_ops *o, t_ops *new);
void	copyops_new_to_old(t_ops *old, t_ops *new);

/* carry */

int		longest_op_run(t_ops *o, int op);

/* util */

int		message_ret(int sig, char *msg);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		freeret_1(int ret, void *x);
int		freeret_2(int ret, void *x, void *y);
int		freeret_3(int ret, void *x, void *y, void *z);

/* util 2 */

int		*findin_sorted(int x, int *arr, int *arr_end);
int		*findin_unsorted(int x, int *arr, int size);
void	bubble_sort(int *tab, int size);
int		safe_multi(int *a, int b);
int		safe_add(int *a, int b);

/* debug */

void	input_check(int ip, t_stack *s);
void	write_op(int i);
void	write_ops_row(t_app *a);
void	write_ops_column(t_app *a);

/* stack ops _0 */

int		sh(t_stack *s, char x);
int		tg_(t_stack *s, int (*x)(t_stack *), int (*y)(t_stack *));
int		sa_(t_stack *s);
int		sb_(t_stack *s);
int		ss_(t_stack *s);

/* stack ops _1 */

int		pa_(t_stack *s);
int		pb_(t_stack *s);
int		ra_(t_stack *s);
int		rb_(t_stack *s);
int		rr_(t_stack *s);

/* stack ops _2 */

int		rra_(t_stack *s);
int		rrb_(t_stack *s);
int		rrr_(t_stack *s);
int		tt(t_stack *s);

#endif /* push swap*/
