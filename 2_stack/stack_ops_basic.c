/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:00 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/28 00:35:02 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	char	*ops;

	ops = "pa\n";
	if (isempty(b))
		return ;
	a->stack[++a->top] = b->stack[b->top--];
	write(1, ops, ft_strlen(ops));
}

void	pb(t_stack *a, t_stack *b)
{
	char	*ops;

	ops = "pb\n";
	if (isempty(a))
		return ;
	b->stack[++b->top] = a->stack[a->top--];
	write(1, ops, ft_strlen(ops));
}

void	ra(t_stack *a)
{
	int		top_val;
	int		i;
	char	*ops;

	ops = "ra\n";
	if (a->top < 1)
		return ;
	top_val = a->stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = top_val;
	write(1, ops, ft_strlen(ops));
}

void	rra(t_stack *a)
{
	int		bottom_val;
	int		i;
	char	*ops;

	ops = "rra\n";
	if (a->top < 1)
		return ;
	bottom_val = a->stack[0];
	i = 0;
	while (i < a->top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->top] = bottom_val;
	write(1, ops, ft_strlen(ops));
}

void	sa(t_stack *a)
{
	int		tmp;
	char	*ops;

	ops = "sa\n";
	if (a->top < 1)
		return ;
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = tmp;
	write(1, ops, ft_strlen(ops));
}
