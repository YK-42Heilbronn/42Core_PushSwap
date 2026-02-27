/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:36 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:30:41 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 100 :: 0110 0100
static int	max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static int	is_sorted(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// max_i = n - 1;
void	radix_sort(t_stack *a, t_stack *b, int n)
{
	int	bits;
	int	bit;
	int	i;
	int	val;

	bits = max_bits(n - 1);
	bit = -1;
	while (++bit < bits)
	{
		if (is_sorted(a, n) && isempty(b))
			break ;
		i = 0;
		while (i < n)
		{
			val = a->stack[a->top];
			if (((val >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (!isempty(b))
			pa(a, b);
	}
}
