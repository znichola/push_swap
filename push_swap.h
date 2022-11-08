/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:23:26 by znichola          #+#    #+#             */
/*   Updated: 2022/11/08 10:30:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
// typedef struct s_bt
// {
// 	int	data;
// 	t_bt	*right_node;
// 	t_bt	*left_node;
// } t_bt;

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

typedef struct s_stack
{
	int	size;
	int	*root_a;
	int	*root_b;
	int	*a;
	int	*b;
} t_stack;

int	process_inputdata(t_stack *stack, char *str);

// stack ops
int	sh(t_stack *s, char x);
int	sa(t_stack *s);
int	sb(t_stack *s);
int	ss(t_stack *s);
int	pa(t_stack *s);
int	pb(t_stack *s);

#endif /* push swap*/