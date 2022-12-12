/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:20:43 by znichola          #+#    #+#             */
/*   Updated: 2022/12/12 10:48:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_read(int *n, char **str)
{
	int	s;

	*n = 0;
	s = 1;
	while (**str == ' ' || **str == '\f' || **str == '\n'
		|| **str == '\r' || **str == '\t' || **str == '\v')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			s = -1;
		(*str)++;
	}
	if (!(**str >= '0' && **str <= '9'))
		return (FAILURE);
	while (**str >= '0' && **str <= '9')
		*n = *n * 10 + (*(*str)++) - '0';
	*n = *n * s;
	return (SUCCESS);
}

int	init_ops(t_stack *s)
{
	s->o.root = (int *)malloc(sizeof(int) * s->size * 30);
	// ft_printf("malloced room for %d opps\n", s->size * 30);
	if (!s->o.root)
		return (ERROR);
	s->o.c = s->o.root - 1;
	return (SUCCESS);
}

int	finish_setup(t_stack *s)
{
	if (find_solution(s))
		return (ERROR);
	if (init_ops(s))
		return (freeret_1(ERROR, s->r.solution));
	s->r.a = NULL;
	s->r.b = NULL;
	s->r.a_hight = 0;
	s->r.a_hight = 0;
	s->r.finish_me = -1;
	return (SUCCESS);
}

static int	add_single_num(t_stack *s, int index, char *str)
{
	int	number;

	if (ft_atoi_read(&number, &str))
		return (FAILIUR);
	s->root_a[index] = number;
	return (SUCCESS);
}

int	process_inputdata(t_stack *stack, char **str, int n)
{
	int	i;

	if (n < 1)
		return (FAILURE);
	stack->root_a = (int *)malloc(sizeof(int) * n);
	if (!stack->root_a)
		return (ERROR);
	stack->root_b = (int *)malloc(sizeof(int) * n);
	if (!stack->root_b)
		return (freeret_1(ERROR, stack->root_a));
	stack->size = n;
	stack->a = stack->root_a + n - 1;
	stack->b = stack->root_b - 1;
	i = 0;
	while (n--)
		if (add_single_num(stack, n, str[i++]))
			return (freeret_2(ERROR, stack->root_a, stack->root_b));
	if (finish_setup(stack))
		return (freeret_2(ERROR, stack->root_a, stack->root_b));
	return (SUCCESS);
}
