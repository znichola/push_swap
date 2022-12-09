/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:07:31 by znichola          #+#    #+#             */
/*   Updated: 2022/12/09 19:40:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	message_ret(int sig, char *msg)
{
	if (sig == ERROR)
		while (*msg)
			write(1, msg++, 1);
	return (sig);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest != NULL || src != NULL)
		while (n-- > 0)
			*d++ = *s++;
	return (dest);
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

int	freeret_3(int ret, void *x, void *y, void *z)
{
	free(x);
	free(y);
	free(z);
	return (ret);
}

// assuming the list is biggest > smallest 
int	*findin_sorted(int x, int *arr, int *arr_end)
{
	int	*t;

	t = arr + ((arr_end - arr) / 2);
	// printf("x:%d t:%d diff:%ld arr:%p end:%p\n", x, *t, arr_end - arr, arr, arr_end);
	if (*arr_end == x)
		return (arr_end);
	if (*arr == x)
		return (arr);
	if (*t == x)
		return (t);
	if (arr_end - arr <= 1)
		return (NULL);
	if (*t > x)
		return (findin_sorted(x, t + 1, arr_end));
	return (findin_sorted(x, arr, t - 1));
}

int	*findin_unsorted(int x, int *arr, int size)
{
	while (size-- > 0)
		if (arr[size] == x)
			return (arr + size);
	return (NULL);
}

// int main(void) 
// {
// 	int list[11];
// 	for (int i = 0; i < 11; i++)
// 		list[i] = i;
// 	list[0] = -1;
// 	list[1] = 1;
// 	printf("here\n");
// 	// printf("0:%d\n", list[0]);
// 	// printf("0:%d\n", list[1]);
// 	for (int i = -2; i < 12; i++)
// 	{
// 		// pri ntf("%d\n", list[i]);
// 		int	*t = findin_sorted(i, list, list + 10);
// 		if (!t)
// 			printf("i:%d null ret\n", i);
// 		else
// 			printf("%p: i:%d %d\n", t, i, *t);
// 	}
// 	return (0);
// }

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	f;
	int	t;

	f = 1;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			t = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = t;
			f = 0;
		}
		i ++;
	}	
	if (f == 1)
	{
		return ;
	}
	bubble_sort(tab, size);
}