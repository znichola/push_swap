/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputdata2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:01:21 by znichola          #+#    #+#             */
/*   Updated: 2022/12/13 11:16:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countnums(char const *s)
{
	int		count;
	int		flag;
	int		old_flag;

	flag = -1;
	count = 0;
	while (*s)
	{
		old_flag = flag;
		if (*s == ' ')
			flag = 0;
		else
			flag = 1;
		if (old_flag != flag && flag == 1)
			count++;
		s++;
	}
	return (count);
}

static void	find_solution_helper(t_stack *s, int i, int *flag)
{
	int	t;

	t = s->r.solution[i];
	s->r.solution[i] = s->r.solution[i + 1];
	s->r.solution[i + 1] = t;
	*flag = 1;
}

int	find_solution(t_stack *s)
{
	int	flag;
	int	i;

	s->r.solution = (int *)malloc(sizeof(int) * s->size);
	if (!s->r.solution)
		return (ERROR);
	ft_memcpy(s->r.solution, s->root_a, s->size * sizeof(int));
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (i++ < s->size - 2)
		{
			if (s->r.solution[i] < s->r.solution[i + 1])
				find_solution_helper(s, i, &flag);
		}
	}
	s->r.s_end = s->r.solution + s->size - 1;
	return (SUCCESS);
}

static int	add_num(t_stack *s, int i, char **str)
{
	int	t;
	int	e;

	if (ft_atoi_read(&t, str))
		return (FAILURE);
	e = i;
	while (++e < s->size)
		if (s->root_a[e] == t)
			return (FAILURE);
	s->root_a[i] = t;
	return (SUCCESS);
}

int	process_inputdata_old(t_stack *stack, char *str)
{
	int	i;

	i = countnums(str);
	stack->root_a = (int *)malloc(sizeof(int) * i);
	if (!stack->root_a)
		return (ERROR);
	stack->root_b = (int *)malloc(sizeof(int) * i);
	if (!stack->root_b)
		return (freeret_1(ERROR, stack->root_a));
	stack->size = i;
	stack->a = stack->root_a + i - 1;
	stack->b = stack->root_b - 1;
	while (i--)
	{
		if (add_num(stack, i, &str))
			return (FAILURE);
		str++;
	}
	if (finish_setup(stack))
		return (freeret_2(ERROR, stack->root_a, stack->root_b));
	return (SUCCESS);
}
