/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:23:16 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 21:08:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack_a: [negative +_ positive] integers

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include "stdlib.h"
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "stack/stack.h"
// # include "libft/ft_itoa.c"

// ops.c
void push_swap(unsigned int *stack_a);
void swap_ops(unsigned int *stack_a, unsigned int *stack_b, int flag);
void push_ops(unsigned int *stack_a, unsigned int *stack_b);
void rotate_ops(unsigned int *stack_a, unsigned int *stack_b);
void reverse_rotate_ops(unsigned int *stack_a, unsigned int *stack_b);

// utils.c
void parser();
void swap(unsigned int *a, unsigned int *b);
void push(unsigned int *take_from, unsigned int *place_on);
void print_double_ptr(int *ptr);
int get_top_index(unsigned int *stack);

#endif
