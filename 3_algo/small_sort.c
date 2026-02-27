/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:48 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 23:58:03 by ykonka           ###   ########.fr       */
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

int	get_min(int *stack, int n)
{
	int	i;
	int	min;

	i = 0;
	min = stack[i];
	while (i < n)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

// rotate 'a' until 'min' is at the *top* (index a->top)
static void	bring_min_to_top(t_stack *a, int min, int n)
{
	int	i;

	i = 0;
	while (i < n && a->stack[a->top] != min)
	{
		ra(a);
		i++;
	}
}

// Here we assume a->top == n - 1 at the beginning.
// find min among 0..n-1 (valid elements)
// rotate until that min is at index a->top
// push min to stack b; this should decrease a->top and increase b->top
// now A has one fewer element, so top should be n-1 again
// sort remaining 3 in a
// push them back
void	sort_four_or_five(t_stack *a, t_stack *b, int n)
{
	int	min;

	while (n > 3)
	{
		min = get_min(a->stack, n);
		bring_min_to_top(a, min, n);
		pb(a, b);
		n--;
	}
	sort_three(a);
	while (!isempty(b))
		pa(a, b);
}

/* for 4–5 can be extend with push smallest to B, sort 3,
		then bring back */
void	sort_small(t_stack *a, t_stack *b, int n)
{
	if (n == 2)
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			sa(a);
	}
	else if (n == 3)
		sort_three(a);
	else
		sort_four_or_five(a, b, n);
}
