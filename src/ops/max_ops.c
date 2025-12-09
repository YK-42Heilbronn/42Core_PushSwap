/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:32:49 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/01 05:33:39 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

// @Move in Stack
// swaps top 2 elements of the stack if stack[top] < stack[top-1]
int max_swap(Stack *stack){
    int top_ele;

    top_ele = pop(stack);
    if (top_ele > peek(stack)){
        push(stack, top_ele);
        // swap_top_2_values_of_stack(stack);
        return 1; 
    }
    push(stack, top_ele);
    return 0;
}

// @Move in Stack
// rotate up if stack[top] < stack[0]
int max_rotate(Stack *stack){
    int bottom_ele;

    rotate_stack_values_shift_down(stack);   // bring bottom ele to top
    bottom_ele = pop(stack);                 // store it in seperate temp var
    push(stack, bottom_ele);                //  push bottom_ele to top
    rotate_stack_values_shift_up(stack);     // put back to bottom
    if (peek(stack) > bottom_ele){
        // rotate_stack_values_shift_up(stack);  // puts top ele to bottom
        return 1;
    }
    return 0;
}

// @Move in Stack
// rotate down if stack[top] < stack[0]
int max_reverse_rotate(Stack *stack){
    int bottom_ele;

    rotate_stack_values_shift_down(stack);   // bring bottom ele to top
    bottom_ele = pop(stack);                 // store it in seperate temp var
    push(stack, bottom_ele);                //  push bottom_ele to top
    rotate_stack_values_shift_up(stack);     // put back to bottom
    if (peek(stack) > bottom_ele){
        // rotate_stack_values_shift_down(stack);  // brings bottom ele to top
        return 1;
    }
    return 0;
}

// @Move Between Stacks
// push stack_a top ele to stack_b top if stack_a[top] < stack_b[top]
int max_push(Stack *stack_a, Stack *stack_b){
    if (peek(stack_a) > peek(stack_b)){
        // push_top_2_values_of_stacks(stack_a, stack_b);
        return 1;
    }
    return 0;
}

