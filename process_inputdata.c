/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:20:43 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 03:47:57 by znichola         ###   ########.fr       */
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
	{
		if (!(safe_multi(n, 10) + safe_add(n, **str - '0') == SUCCESS))
			return (FAILURE);
		(*str)++;
	}
	// ft_printf("last char is:%d\n", **str);
	if (!(**str == ' ' || **str == '\0'))
		return (FAILURE);
	safe_multi(n, s);
	return (SUCCESS);
}

int	init_ops(t_stack *s)
{
	s->o.root = (int *)malloc(sizeof(int) * s->size * 30);
	if (!s->o.root)
		return (ERROR);
	s->o.c = s->o.root - 1;
	s->new.root = (int *)malloc(sizeof(int) * s->size * 30);
	if (!s->new.root)
		return (freeret_1(ERROR, s->o.root));
	s->new.c = s->new.root - 1;
	return (SUCCESS);
}
	// ft_printf("malloced room for %d opps\n", s->size * 30);

int	finish_setup(t_stack *s)
{
	if (find_solution(s))
		return (ERROR);
	if (init_ops(s))
		return (freeret_1(ERROR, s->r.solution));
	// ft_printf("\nstack size:%d\n", s->size);
	if (s->size <= 150)
		s->pivot = (t_qs){2, 4};
	else if (s->size <= 300)
		s->pivot = (t_qs){3, 6};
	else
		s->pivot = (t_qs){4, 8};
	return (SUCCESS);
}

static int	add_single_num(t_stack *s, int index, char *str)
{
	int	number;
	int	e;

	if (ft_atoi_read(&number, &str))
		return (FAILIUR);
	e = index;
	while (++e < s->size)
		if (s->root_a[e] == number)
			return (FAILURE);
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
