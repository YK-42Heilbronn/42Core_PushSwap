/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:37:11 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:38:05 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int **pt_indices, int *pt_len);

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
		a->stack[++a->top] = indices[i];
	free(indices);
	if (len <= 5)
		sort_small(a, b, len);
	else
		radix_sort(a, b, len);
	free_stack(a);
	free_stack(b);
}
