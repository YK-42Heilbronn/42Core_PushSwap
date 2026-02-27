/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:37:11 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 23:44:34 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int **pt_indices, int *pt_len);
static void	start_sorting(t_stack **a, t_stack **b, int *len);
static int is_stack_decending(int *values, int len);

/* fill A with indices, top at end of input */
int	main(int argc, char **argv)
{
	int	len;
	int	*values;
	int	*indices;

	if (argc < 2)
		return (0);
	values = prepare_stack(argc, argv, &len);
	if (!values)
		print_error_exit(NULL);
	indices = index_values(values, len);
	if (is_stack_decending(values, len))
		return (0);
	int *v;
	v = values;
	free(values);
	if (!indices)
		print_error_exit(NULL);
	push_swap(&indices, &len);
	return (0);
}

static void	push_swap(int **pt_indices, int *pt_len)
{
	t_stack	*a;
	t_stack	*b;
	int		*indices;
	int		len;
	int		i;

	indices = *pt_indices;
	len = *pt_len;
	a = initialize_stack(len);
	b = initialize_stack(len);
	if (!a || !b)
		print_error_exit(NULL);
	a->top = -1;
	i = len;
	while (--i >= 0)
	{
		a->stack[++a->top] = indices[i];
	}
	free(indices);
	start_sorting(&a, &b, &len);
}

static void	start_sorting(t_stack **a, t_stack **b, int *len)
{
	if (*len <= 5)
		sort_small(*a, *b, *len);
	else
		radix_sort(*a, *b, *len);
	free_stack(*a);
	free_stack(*b);
}

static int is_stack_decending(int *values, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (values[i] > values[i+1])
			return (0);
		i++;
	}
	return (1);
}
