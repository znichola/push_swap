/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:23:26 by znichola          #+#    #+#             */
/*   Updated: 2022/11/06 19:12:58 by znichola         ###   ########.fr       */
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

typedef struct s_stack
{
	int	*a;
	int	*b;
} t_stack;

int	process_inputdata(t_stack *stack, char *str);

#endif /* push swap*/