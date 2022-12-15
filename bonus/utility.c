/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:00:37 by znichola          #+#    #+#             */
/*   Updated: 2022/12/15 17:28:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_atoi_read(int *n, char **str)
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
	if (!(**str == ' ' || **str == '\0'))
		return (FAILURE);
	safe_multi(n, s);
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
	// if (finish_setup(stack))
	// 	return (freeret_2(ERROR, stack->root_a, stack->root_b));
	return (SUCCESS);
}

int	freeret_1(int ret, void *x)
{
	free(x);
	return (ret);
}

int	freeret_2(int ret, void *x, void *y)
{
	free(x);
	free(y);
	return (ret);
}