/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:29:36 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/09 14:31:29 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

// collect_info.c
Stack** info_stack(int size);
void gather_info_stack_b(Stack *stack_b, Stack **max_stack, Stack **min_stack);
// void stack_b_max_to_stack_a(Stack *stack_a, Stack *stack_b, Stack **max_stack, Stack **min_stack);
void stack_b_max_to_stack_a(Stack *stack_a, Stack *stack_b, Stack **max_stack, Stack **min_stack);
void sort_max_from_stack_b_in_stack_a(Stack *stack_a, Stack *stack_b, int previous_top_ind);

// sort_utils.c
void swap_stack_eles(Stack *swap_stack, int start_ind);
void sort_max_stack_elements(Stack **max_stack);
void sort_max_stack_indexes(Stack **max_stack);
void arrange_ele_in_max_stack(Stack **max_stack, int ele,  int top_ind);
void arrange_ele_in_min_stack(Stack **min_stack, int ele,  int top_ind);
void update_max_stack(Stack *max_index_stack, int shift_value);
void insert_max_ele_in_stack(Stack **max_stack, int insert_ind);
void swap(int *ele1, int *ele2);
int handle_min_eles(Stack *stack_a, Stack *stack_b, Stack **min_stack, Stack **max_stack);

