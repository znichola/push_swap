/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:30 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 00:53:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_ps_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;

	// printf("\nlen:%lu big<%s> little<%s>\n", len, big, little);
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

static int find_opp(char *str, size_t len)
{
	if (len == 2 && ft_ps_strnstr(str, "sa", 2))
		return (SA);
	if (len == 2 && ft_ps_strnstr(str, "sb", 2))
		return (SB);
	if (len == 2 && ft_ps_strnstr(str, "ss", 2))
		return (SS);
	if (len == 2 && ft_ps_strnstr(str, "pa", 2))
		return (PA);
	if (len == 2 && ft_ps_strnstr(str, "pb", 2))
		return (PB);
	if (len == 2 && ft_ps_strnstr(str, "ra", 2))
		return (RA);
	if (len == 2 && ft_ps_strnstr(str, "rb", 2))
		return (RB);
	if (len == 2 && ft_ps_strnstr(str, "rr", 2))
		return (RR);
	if (len == 3 && ft_ps_strnstr(str, "rra", 3))
		return (RRA);
	if (len == 3 && ft_ps_strnstr(str, "rrb", 3))
		return (RRB);
	if (len == 3 && ft_ps_strnstr(str, "rrr", 3))
		return (RRR);
	return (ERROR);
}

static int addopp(t_stack *s, char **str)
{
	char	*end;
	size_t	len;
	int		opp;

	while (ft_isspace(**str) && **str != '\0')
		(*str)++;
	end = (char *)*str;
	while (!ft_isspace(*end) && *end != '\0')
		end++;
	len = end - *str;
	// printf("s:<%c> e:<%c> len:%ld\n", **str, *end, len);
	if (len > 1)
	{
		opp = find_opp(*str, len);
		if (opp == ERROR)
			return (message_ret(FAILURE, 2, "find op error"));
		*s->ops = opp;
		s->ops++;
	}
	*str = end;
	return (SUCCESS);
}

int	process_input_ops(t_stack *s, char *str)
{
	int	len;
	int	i;
	
	len = ft_count_args(str);
	s->ops_root = (int *)malloc(sizeof(int) * len);
	if (!s->ops_root)
		return (message_ret(ERROR, 2, "ops malloc error"));
	s->ops = s->ops_root;
	*s->ops = EMPTY;
	i = -1;
	while(i++ < len)
		if (addopp(s, &str) == FAILURE)
			return (message_ret(0, 2, "add ops error")
				+ ft_freeret_1(FAILURE, s->ops_root));
	if (DEBUG_TEST)
	{
		ft_printf("\nrecorded ops:\n");
		display_ops(s);
	}
	return (SUCCESS);
}