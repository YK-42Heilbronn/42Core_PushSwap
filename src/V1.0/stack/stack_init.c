/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:56:46 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:29:36 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*initialize_stack(int size)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->stack = (int *)malloc(sizeof(int) * size);
	if (!s->stack)
	{
		free(s);
		return (NULL);
	}
	s->size = size;
	s->top = -1;
	return (s);
}

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	free(s->stack);
	free(s);
}

int	isempty(t_stack *s)
{
	return (s->top < 0);
}
