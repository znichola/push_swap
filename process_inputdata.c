/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:20:43 by znichola          #+#    #+#             */
/*   Updated: 2022/11/06 20:05:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (-1);
	while (**str >= '0' && **str <= '9')
		*n = *n * 10 + (*(*str)++) - '0';
	*n = *n * s;
	return (0);
}

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

// static int	nextnumber(char **str)
// {
// 	int	ret;

// 	while (**str == ' ' && **str != '\0')
// 		(*str)++;
// 	ret = ft_atoi(*str);
// 	printf("here:%d\n", ret);
// 	while (**str != ' ' && **str != '\0')
// 		(*str)++;
// 	return (ret);
// }

int	process_inputdata(t_stack *stack, char *str)
{
	int	i;
	int	e;
	
	i = countnums(str);
	printf("there are %d numbers\n", i);
	stack->a = (int *)malloc(sizeof(int) * i);
	if (!stack->a)
		return (0);
	stack->b = (int *)malloc(sizeof(int) * i);
	if (!stack->b)
	{
		free(stack->a);
		return (0);
	}
	while (i--)
	{
		printf("num %c\n", *str);
		if (ft_atoi_read(&stack->a[i], &str))
			printf("input num error %c\n", *str);
		str++;
		printf("num is%d\n", stack->a[i]);
		e = 0;
	}
	return (1);
}
