/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:14:24 by znichola          #+#    #+#             */
/*   Updated: 2022/12/17 20:45:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_ps_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		b = (char *)big;
		l = (char *)little;
		i = len;
		while (*b++ == *l++ && i-- > 0)
			if (*l == '\0')
				return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

static int	find_opp(char *str, size_t len)
{
	if (len == 3 && ft_ps_strnstr(str, "sa\n", 3))
		return (SA);
	if (len == 3 && ft_ps_strnstr(str, "sb\n", 3))
		return (SB);
	if (len == 3 && ft_ps_strnstr(str, "ss\n", 3))
		return (SS);
	if (len == 3 && ft_ps_strnstr(str, "pa\n", 3))
		return (PA);
	if (len == 3 && ft_ps_strnstr(str, "pb\n", 3))
		return (PB);
	if (len == 3 && ft_ps_strnstr(str, "ra\n", 3))
		return (RA);
	if (len == 3 && ft_ps_strnstr(str, "rb\n", 3))
		return (RB);
	if (len == 3 && ft_ps_strnstr(str, "rr\n", 3))
		return (RR);
	if (len == 4 && ft_ps_strnstr(str, "rra\n", 4))
		return (RRA);
	if (len == 4 && ft_ps_strnstr(str, "rrb\n", 4))
		return (RRB);
	if (len == 4 && ft_ps_strnstr(str, "rrr\n", 4))
		return (RRR);
	return (ERROR);
}

static int	check_complete(t_stack *s)
{
	int	i;

	i = sh(s, 'a');
	if (i != s->size)
		return (FAILURE);
	while (i-- > 1)
		if (s->root_a[i] > s->root_a[i - 1])
			return (FAILURE);
	return (SUCCESS);
}

static int	do_opp7(t_stack *s, int op)
{
	if (op == SA)
		return (sa_(s));
	if (op == SB)
		return (sb_(s));
	if (op == SS)
		return (ss_(s));
	if (op == PA)
		return (pa_(s));
	if (op == PB)
		return (pb_(s));
	if (op == RA)
		return (ra_(s));
	if (op == RB)
		return (rb_(s));
	if (op == RR)
		return (rr_(s));
	if (op == RRA)
		return (rra_(s));
	if (op == RRB)
		return (rrb_(s));
	if (op == RRR)
		return (rrr_(s));
	return (ERROR);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*op;

	if (ac == 1)
		exit(0);
	if (process_inputdata(&stack, av + 1, ac - 1))
		exit(1);
	op = get_next_line(0);
	while (op != NULL)
	{
		if (do_opp7(&stack, find_opp(op, ft_strlen(op))) == ERROR)
			exit(1);
		free(op);
		op = get_next_line(0);
	}
	if (!check_complete(&stack))
		ft_putstr_fd("\033[32mOK\033[0m\n", 1);
	else
	{
		ft_putstr_fd("\033[31mKO\033[0m\n", 1);
		exit(1);
	}
	exit(0);
	return (0);
}
