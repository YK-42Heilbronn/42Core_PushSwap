/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:23:16 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/07 17:45:47 by ykonka           ###   ########.fr       */
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
# include "ops/ops.h"
# include "sort_b_to_a/sort_b_to_a.h"
// # include "libft/ft_itoa.c"

// parser.c
void parser();

// push_swap.c
void push_swap(Stack *stack_a, Stack *stack_b);
// void move_in_a_stack(Stack *stack);
// void move_bw_stacks(Stack *stack_a, Stack *stack_b);
void sort_stack_a(Stack *stack_a, Stack *stack_b);
void sort_stack_b(Stack *stack_b);
void sort_last_3_elements(Stack *stack_a, Stack *stack_b);
void initial_sorting(Stack *stack_a, Stack *stack_b);
void sorting_b_stack_only(Stack *stack_a, Stack *stack_b, Stack **max_stack, Stack **min_stack);

// utils.c
void print_stack(Stack *stack);
int is_stack_ascending(Stack *stack, int start);
int is_stack_decending(Stack *stack, int start);

// stack state information
typedef struct{
    int *chunk_1[2];  // min - max  = [0, 1]
    // int max;
    int *chunck_2[2];  // min - max = [0, 1]
    // int next_max;
    
    // int sort_type;  // 1-ascending, 0-decending
    // int sort_state; // 1-type-active, 0-type-inactive
} Chunks;   // StackState

#endif

