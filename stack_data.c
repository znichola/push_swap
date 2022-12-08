/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:23:03 by znichola          #+#    #+#             */
/*   Updated: 2022/12/08 14:16:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	print_stack(t_stack *s)
{
	int	i;

	i = -1;
	while (i++ < s->size)
	{
		if (s->root_a + i <= s->a)
			printf("%-2d", s->root_a[i]);
		else
			printf("  ");
		printf(" ");
		if (s->root_b + i <= s->b)
			printf("%-2d", s->root_b[i]);
		printf("\n");
	}
	return (SUCCESS);
}