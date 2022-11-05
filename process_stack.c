/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:20:43 by znichola          #+#    #+#             */
/*   Updated: 2022/11/05 20:54:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	s;
	int	n;

	n = 0;
	s = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (ft_isdigit(*str))
		n = n * 10 + *str++ - '0';
	return ((int)n * s);
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

static int	nextnumber(char **str)
{
	int		ret;

	while (**str == ' ' && **str != '\0')
		(*str)++;
	ret = ft_atoi(*str);
	while (**str == ' ' && **str != '\0')
		(*str)++;
	return (ret);
}

int	*process_inputdata(char *str)
{
	int	*stack;

	stack = (int *)malloc(sizeof(int) * countnums(str));
	while ()
}
