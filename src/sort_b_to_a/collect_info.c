/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:55:13 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/09 15:01:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sort_b_to_a.h"

Stack** info_stack(int size){
    Stack **stack_stacks;
    int ind;
    int stack2d_size;
    
    ind = 0;
    stack2d_size = 2;
    stack_stacks = (Stack**)malloc(sizeof(Stack*)*stack2d_size);
    if (stack_stacks == NULL)
        return NULL;
    // ft_printf("info_stack-stack_stacks: %p\n", stack_stacks);
    while (ind < stack2d_size){
        // Stack *max_ele_stack;        ind = 0
        // Stack *max_ind_stack;        ind = 1
        // Array index already says that they are arranged according to [max or min] level
        stack_stacks[ind] = initialize_stack(size);
        // ft_printf("info_stack-stack_stacks[%d]: %p\n", ind, stack_stacks[ind]);
        if (stack_stacks[ind] == NULL){
            while (ind >=0){
                free(stack_stacks[ind]->stack);
                free(stack_stacks[ind--]);
            }
            free(stack_stacks);
            return NULL;
        }
        ind++;
    }
    return stack_stacks;
}

void gather_info_stack_b(Stack *stack_b, Stack **max_stack, Stack **min_stack){
    // [max, min]_stack[0] - elements
    // [max, min]_stack[1] - indexes, calculated from Top
    // [max, min]_stack[2] - quality level [0-size][high-least]
    int ind;

    ind = stack_b->top;
    while (ind >= 0){
        arrange_ele_in_max_stack(max_stack, stack_b->stack[ind], stack_b->top-ind);
        arrange_ele_in_min_stack(min_stack, stack_b->stack[ind], stack_b->top-ind);
        ind--;
    }
    sort_max_stack_indexes(max_stack);
    // sort min_stack: it has only 2 elements -> no function
    if (min_stack[0]->stack[0]<min_stack[0]->stack[1]){
        swap_stack_eles(min_stack[0], 0);
        swap_stack_eles(min_stack[1], 0);
    }
    // ----- Manual Testing -----
    print_stack(max_stack[0]);
    print_stack(max_stack[1]);
    print_stack(min_stack[0]);
    print_stack(min_stack[1]);
}

// void stack_b_max_to_stack_a(Stack *stack_a, Stack *stack_b, Stack **max_stack, Stack **min_stack){
void stack_b_max_to_stack_a(Stack *stack_a, Stack *stack_b, Stack **max_stack, Stack **min_stack){
    // there is an assumtion for the stack_a - carefull before using this method
    // int ind;
    // int top;
    int rr_or_rrr;
    int steps_from_bottom;
    int steps_from_top;

    // ind = 0;
    // top = stack_b->top;
    // preprocess_indexes(max_stack, rr_or_rrr);
    while (max_stack[1]->top>=0){
        // ft_printf("{{{{{{{{{{{{{{{{{{{{\n");
        rr_or_rrr = (int)(stack_b->top/2);
        // ft_printf("rr_or_rrr: %d || top b: %d || max_stack_top: %d\n------------------\n", rr_or_rrr, stack_b->top, max_stack[1]->top);
        // up=(-1, removing from top), down=(+1, adding to top)
        // @TODO: is it good rotate up or down when the state is equal
        if (max_stack[1]->stack[max_stack[1]->top]<=rr_or_rrr){
            steps_from_top=max_stack[1]->stack[max_stack[1]->top];
            // pop(max_stack[0]);
            // pop(max_stack[1]);
        }
        if (max_stack[1]->stack[0]>rr_or_rrr){
            // rotate_stack_values_shift_down(max_stack[0]);
            steps_from_bottom=stack_b->top-max_stack[1]->stack[0];
            // pop(max_stack[0]);
            // pop(max_stack[1]);
        }
        // print_stack(max_stack[0]);
        // print_stack(max_stack[1]);
        // ft_printf("steps-top: %d || steps-bottom: %d\n", steps_from_top, steps_from_bottom);
        if (steps_from_top<steps_from_bottom){
            // ft_printf("if\n");
            while (steps_from_top>=0)
            {
                if (steps_from_top > 0){
                    handle_min_eles(stack_a, stack_b, min_stack, max_stack);
                    rotate_stack_values_shift_up(stack_b);
                }
                steps_from_top--;
                // the position of eles from top is reduced, there are getting closer to top
                // if (steps_from_top > 0)
                update_max_stack(max_stack[1], -1);
            }   
        }else{
            // ft_printf("else\n");
            rotate_stack_values_shift_down(max_stack[0]);
            rotate_stack_values_shift_down(max_stack[1]);
            while (steps_from_bottom>=0)
            {
                handle_min_eles(stack_a, stack_b, min_stack, max_stack);
                rotate_stack_values_shift_down(stack_b);
                steps_from_bottom--;
                // the position of eles from top is increased, they are getting farther to top
                if (steps_from_bottom > 0)
                    update_max_stack(max_stack[1], 1);
            }
        }
        // Actually stupid Checking
        // ft_printf("stack_btop: %d || max_stack[0]: %d\n", peek(stack_b), peek(max_stack[0]));
        if (peek(stack_b) == peek(max_stack[0]))
            push_top_2_values_of_stacks(stack_b, stack_a);   
        // print_stack(stack_a);
        // print_stack(stack_b);
        pop(max_stack[0]);
        pop(max_stack[1]);
        // print_stack(max_stack[0]);
        // print_stack(max_stack[1]);
        // ind++;
        // ft_printf("========================\n");
    }
}

void sort_max_from_stack_b_in_stack_a(Stack *stack_a, Stack *stack_b, int previous_top_ind){
    int ind;
    int local_prev_top_ind;
    int size_of_sort_elements;
    
    local_prev_top_ind = previous_top_ind;
    size_of_sort_elements = stack_a->top-previous_top_ind;
    // ft_printf("prevTopInd: %d || stack_a top: %d || stack_b top: %d\n--------------------\n", 
    //     previous_top_ind, stack_a->top, stack_b->top);
    while (1){
        // ft_printf("+:+:+:+:+:+:+:+:+:+:+:+:+:+:+:+\n");
        // the newly added values are already sorted in ascending order, no need to sort the stack_a new elements
        if (is_stack_ascending(stack_a, previous_top_ind)){
            // ft_printf("================break=====================\n");
            break;
        }
        // ind = stack_a->top;
        // loop - 1: push to stack A to stack B - first half cycle
        if (local_prev_top_ind>0)
            push_top_2_values_of_stacks(stack_a, stack_b);
        while (stack_a->top >= local_prev_top_ind){
            // ft_printf("while1\n");
            if (peek(stack_a)<peek(stack_b)){
                push_top_2_values_of_stacks(stack_a, stack_b);
                swap_top_2_values_of_stack(stack_b);
            }
            else{
                push_top_2_values_of_stacks(stack_a, stack_b);
            }
            // ind--;
        }
        // ft_printf("\\\\\\\\\before while2\\\\\\\\\\n");
        // print_stack(stack_a);
        // print_stack(stack_b);
        // // ft_printf("------------------------\n");
        // ft_printf("while2::prevTopInd: %d || stack_a top: %d || stack_b top: %d\n--------------------\n", 
        //     previous_top_ind, stack_a->top, stack_b->top);
        // local_prev_top_ind++;
        // loop - 2: push to stack B to stack A - second half cycle
        // if (stack_b->top > 0)
        if (stack_b->top>=size_of_sort_elements)
            ind = stack_b->top-size_of_sort_elements;
        else
            ind = 0;
        // ft_printf("while2::ind:: %d\n", ind);
        if (local_prev_top_ind>0)  //  || stack_b->top == -1
            push_top_2_values_of_stacks(stack_b, stack_a);
        while (stack_b->top >= ind){
            // ft_printf("while2:: stack_btop: %d || ind: %d \n", stack_b->top, ind);
            if (peek(stack_b)>peek(stack_a)){
                push_top_2_values_of_stacks(stack_b, stack_a);
                swap_top_2_values_of_stack(stack_a);
            }
            else
                push_top_2_values_of_stacks(stack_b, stack_a);
            // ind--;
            // if (stack_b->top == -1 & ind <= -1)
            //     break;
        }
        // ft_printf("\\\\\\\\\after while2\\\\\\\\\\n");
        // print_stack(stack_a);
        // print_stack(stack_b);
        local_prev_top_ind++;
        // push_top_2_values_of_stacks(stack_b, stack_a);
        // // finished - full cycle
        // ind = stack_a->top;
    }
    print_stack(stack_a);
    print_stack(stack_b);
    ft_printf("============after complete intermediate sort===========\n");
}

