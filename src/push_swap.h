/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:23:16 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/26 14:09:06 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack_a: [negative +_ positive] integers

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include "stdlib.h"
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "stack/stack.h"
// # include "libft/ft_itoa.c"

// push_swap.c
void push_swap(Stack *stack_a, Stack *stack_b);

// ops.c
void swap_ops(unsigned int *stack_a, unsigned int *stack_b, int flag);
void push_ops(unsigned int *stack_a, unsigned int *stack_b);
void rotate_ops(unsigned int *stack_a, unsigned int *stack_b);
void reverse_rotate_ops(unsigned int *stack_a, unsigned int *stack_b);

// utils.c
void parser();
void swap_top_2_values_of_stack(Stack *swap_stack);
void push_top_2_values_of_stacks(Stack *take_from, Stack *place_on);
void rotate_stack_values_shift_up(Stack *stack_to_rotate);
void rotate_stack_values_shift_down(Stack *stack_to_rotate);
void print_double_ptr(int *ptr);
int get_top_index(unsigned int *stack);

#endif

