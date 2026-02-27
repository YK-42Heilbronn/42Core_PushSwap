/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:22 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 20:22:06 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index_sorted_array(int **sorted, int **idx, int *vals, int *n);
static void	bubble_sort(int **sorted, int *n);

int	*index_values(int *vals, int n)
{
	int	*sorted;
	int	*idx;
	int	i;

	sorted = (int *)malloc(sizeof(int) * n);
	idx = (int *)malloc(sizeof(int) * n);
	if (!sorted || !idx)
	{
		free(sorted);
		free(idx);
		return (NULL);
	}
	i = -1;
	while (++i < n)
		sorted[i] = vals[i];
	bubble_sort(&sorted, &n);
	index_sorted_array(&sorted, &idx, vals, &n);
	return (idx);
}

static void	bubble_sort(int **sorted, int *n)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < *n - 1)
	{
		j = i;
		while (++j < *n)
		{
			if ((*sorted)[i] > (*sorted)[j])
			{
				tmp = (*sorted)[i];
				(*sorted)[i] = (*sorted)[j];
				(*sorted)[j] = tmp;
			}
		}
	}
}

static void	index_sorted_array(int **sorted, int **idx, int *vals, int *n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < *n)
	{
		j = 0;
		while (j < *n && vals[i] != (*sorted)[j])
			j++;
		(*idx)[i] = j;
	}
	free(*sorted);
}

// int *index_values(int *vals, int n)
// {
//     int *sorted;
//     int *idx;
//     int i, j, tmp;

//     sorted = (int *)malloc(sizeof(int) * n);
//     idx = (int *)malloc(sizeof(int) * n);
//     if (!sorted || !idx)
//     {
//         free(sorted);
//         free(idx);
//         return (NULL);
//     }
//     for (i = 0; i < n; i++)
//         sorted[i] = vals[i];
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (sorted[i] > sorted[j])
//             {
//                 tmp = sorted[i];
//                 sorted[i] = sorted[j];
//                 sorted[j] = tmp;
//             }
//         }
//     }
//     for (i = 0; i < n; i++)
//     {
//         j = 0;
//         while (j < n && vals[i] != sorted[j])
//             j++;
//         idx[i] = j;
//     }
//     free(sorted);
//     return (idx);
// }
