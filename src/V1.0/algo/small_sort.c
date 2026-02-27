/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:48 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:31:58 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->stack[a->top];
	y = a->stack[a->top - 1];
	z = a->stack[a->top - 2];
	if (x > y && x > z && y < z)
		ra(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x < z)
		sa(a);
	else if (x < y && x > z)
		rra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
}

/* for 4–5 can be extend with push smallest to B, sort 3,
		then bring back */
void	sort_small(t_stack *a, t_stack *b, int n)
{
	(void)b;
	if (n == 2)
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			sa(a);
	}
	else if (n == 3)
		sort_three(a);
}
