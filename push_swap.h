/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:37:34 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/28 01:09:55 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "limits.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		used;
	long	*seen;
}			t_data;

typedef struct s_stack
{
	int		*stack;
	int		top;
	int		size;
}			t_stack;

/* parse_argvs */
void		clean_argvs(int argc, char *argvs[], int *len);
int			is_duplicate(long *seen, int used, int value);
long		*prepare_stack(int argc, char *argvs[], int *arr_size);

/* stack */
t_stack		*initialize_stack(int size);
void		free_stack(t_stack *s);
int			isempty(t_stack *s);

/* basic ops (print instruction + modify t_stacks) */
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);
void		sa(t_stack *a);

/* algo */
int			*index_values(long *vals, int n);
void		radix_sort(t_stack *a, t_stack *b, int n);
void		sort_small(t_stack *a, t_stack *b, int n);

/* utils */
int			ft_is_space(char c);
int			ft_isoperator(char c);
long		ft_atol(const char *str);
void		print_error_exit(void *msg);

/* wrapper used by parser */
// int		atoi_wrapper(const char *start, int len);

#endif
