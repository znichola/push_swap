/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:20:43 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 12:50:44 by znichola         ###   ########.fr       */
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

// static int	ft_atoi_read(int *n, char **str)
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
		*n = *n * 10 + (*(*str)++) - '0';
	*n = *n * s;
	return (SUCCESS);
}

static int	add_num(t_stack *s, int i, char **str)
{
	int	t;
	int	e;
	
	if (ft_atoi_read(&t, str))
	{
		// write(1, &"input nu@ error\n", 17);
		return (FAILURE);
	}
	e = i;
	while (++e < s->size) //TODO: swapped to ++e instead of e++
		if (s->root_a[e] == t)
		{
			// write(1, &"duplicate num\n", 14);
			return (FAILURE);
		}
	s->root_a[i] = t;
	return (SUCCESS);
}

int	find_solution(t_stack *s)
{
	int	flag;
	int	i;
	int	t;

	s->r.solution = (int *)malloc(sizeof(int) * s->size);
	if (!s->r.solution)
		return (ERROR);
	ft_memcpy(s->r.solution, s->root_a, s->size * sizeof(int));
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (i++ < s->size - 2) // overflow checked here!
			if (s->r.solution[i] < s->r.solution[i + 1]) // overflow check
			{
				t = s->r.solution[i];
				s->r.solution[i] = s->r.solution[i + 1];
				s->r.solution[i + 1] = t;
				flag = 1;
			}
	}
	s->r.s_end = s->r.solution + s->size - 1;
	return (SUCCESS);
}

int	init_ops(t_stack *s)
{
	s->o.root = (int *)malloc(sizeof(int) * s->size * 4);
	if (!s->o.root)
		return (ERROR);
	s->o.c = s->o.root - 1;
	// *s->o.c = 0; //TODO: this seems bad? and not needed and an overflow
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

int	process_inputdata_old(t_stack *stack, char *str)
{
	int	i;
	// int	t;
	
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

int	add_single_num(t_stack *s, int index, char *str)
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
			// return (FAILURE); //TODO: what about free?
	if (finish_setup(stack))
		return (freeret_2(ERROR, stack->root_a, stack->root_b));
	return (SUCCESS);
}
