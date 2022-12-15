/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:32:17 by znichola          #+#    #+#             */
/*   Updated: 2022/11/16 22:05:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

static int	add_num(t_stack *s, int i, char **str)
{
	int	t;
	int	e;
	
	if (ft_atoi_read(&t, str))
		return (FAILURE);
	e = i;
	while (e++ < s->size)
		if (s->root_a[e] == t)
			return (FAILURE);
	s->root_a[i] = t;
	return (SUCCESS);
}

static int	find_solution(t_stack *s)
{
	int	flag;
	int	i;
	int	t;

	s->solution = (int *)malloc(sizeof(int) * s->size);
	if (!s->solution)
		return (ERROR);
	ft_memcpy(s->solution, s->root_a, s->size * sizeof(int));
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (i++ < s->size - 1)
			if (s->solution[i] < s->solution[i + 1])
			{
				t = s->solution[i];
				s->solution[i] = s->solution[i + 1];
				s->solution[i + 1] = t;
				flag = 1;
			}
	}
	return (SUCCESS);
}

int	process_input_nums(t_stack *stack, char *str)
{
	int	i;
	int	t;
	
	i = ft_count_args(str);
	stack->root_a = (int *)malloc(sizeof(int) * i);
	if (!stack->root_a)
		return (ERROR);
	stack->root_b = (int *)malloc(sizeof(int) * i);
	if (!stack->root_b)
		return (ft_freeret_1(ERROR, stack->root_a));
	stack->size = i;
	stack->a = stack->root_a + i - 1;
	stack->b = stack->root_b - 1;
	while (i--)
	{
		if (add_num(stack, i, &str))
			return (FAILURE);
		str++;
	}
	if (find_solution(stack))
		return (ft_freeret_2(ERROR, stack->root_a, stack->root_b));
	return (SUCCESS);
}
