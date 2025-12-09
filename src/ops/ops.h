/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:51:47 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/03 16:58:26 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

// // ops.c
// void swap_ops(Stack *stack_a, Stack *stack_b, int flag);
// void push_ops(Stack *stack_a, Stack *stack_b, int flag);
// void rotate_ops(Stack *stack_a, Stack *stack_b, int flag);
// void reverse_rotate_ops(Stack *stack_a, Stack *stack_b, int flag);

// ops/ops.c
void swap_top_2_values_of_stack(Stack *swap_stack);
void push_top_2_values_of_stacks(Stack *take_from, Stack *place_on);
void rotate_stack_values_shift_up(Stack *stack_to_rotate);
void rotate_stack_values_shift_down(Stack *stack_to_rotate);
// void print_double_ptr(int *ptr);
// int get_top_index(unsigned int *stack);

// ops/max_ops.c
int max_swap(Stack *stack);
int max_rotate(Stack *stack);
int max_reverse_rotate(Stack *stack);
int max_push(Stack *stack_a, Stack *stack_b);

// ops/min_ops.c
int min_swap(Stack *stack);
int min_rotate(Stack *stack);
int min_reverse_rotate(Stack *stack);
int min_push(Stack *stack_a, Stack *stack_b);