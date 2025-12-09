/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:05:00 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/01 04:30:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

// @Violates Stack Standard Concept - Not Suggested
// void swap_top_2_values_of_stack(Stack *swap_stack){
//     // a is a pointer - stores address of an variable
//     // b is a pointer - stores address of an variable
//     // if (swap_stack->top < 1){
//     //     return;
//     // }
//     int temp;
//     // printf("a %d b %d\n", *a, *b);
//     // printf("aptr %p bptr %p\n", a, b);
    
//     temp = swap_stack->stack[swap_stack->top]; 
//     // printf("\ntemp %d \n", temp);
//     swap_stack->stack[swap_stack->top] = swap_stack->stack[swap_stack->top-1];
//     // printf("a %d\n", swap_stack->stack[swap_stack->top]);
//     swap_stack->stack[swap_stack->top-1] = temp;
//     // printf("b %d\n", swap_stack->stack[swap_stack->top-1]);
// }


void swap_top_2_values_of_stack(Stack *swap_stack){
    int top;
    int next_top;
    
    top = pop(swap_stack);
    next_top = pop(swap_stack);

    push(swap_stack, top);
    push(swap_stack, next_top);
}


// int get_top_index(unsigned int *stack){
//     int ind;

//     ind = -1;
//     while(*stack++){
//         ind++;
//     }
//     return ind;
// }

void push_top_2_values_of_stacks(Stack *take_from, Stack *place_on){
    if (isempty(take_from))
        return;
    push(place_on, pop(take_from));
    // --------- or ----------
    // place_on->stack[place_on->top+1] = take_from->stack[take_from->top];
    // place_on->top++;
    // take_from->top--;
    // printf("%d\n", place_on[get_top_index(place_on)+1]);
    // free(&take_from[get_top_index(take_from)]);
    // take_from[get_top_index(take_from)] = 0;
}


// @Violates the Stack Standard Concept - Not Suggested
void rotate_stack_values_shift_up(Stack *stack_to_rotate){ // rotate right
    int top_val;
    int counter;

    if (stack_to_rotate->top < 1)
        return;

    counter = stack_to_rotate->top;
    top_val = stack_to_rotate->stack[stack_to_rotate->top];

    while(counter > 0){
        stack_to_rotate->stack[counter] = stack_to_rotate->stack[counter-1];
        counter--;
    }
    stack_to_rotate->stack[counter] = top_val;
}

// // Very costly operation, Creating an new Stack on every rotation is computationally expensive in Scaling
// void rotate_stack_values_shift_up(Stack *stack_to_rotate){
//     Stack *temp_stack;
//     int top_ele;

//     temp_stack = initialize_stack(stack_to_rotate->size-1);
//     top_ele = pop(stack_to_rotate);

//     while(isempty(stack_to_rotate)){
//         push(temp_stack, pop(stack_to_rotate));
//     }
//     push(stack_to_rotate, top_ele);
//     while(isempty(temp_stack)){
//         push(stack_to_rotate, pop(temp_stack));
//     }
//     free_stack(temp_stack);
// }

// @Violating Stack Standard Concept - Not Suggested
void rotate_stack_values_shift_down(Stack *stack_to_rotate){  // rotate left
    int bottom_val;
    int counter;

    if (stack_to_rotate->top < 1)
        return;

    counter = 0;
    bottom_val = stack_to_rotate->stack[0];

    while(counter < stack_to_rotate->top){
        stack_to_rotate->stack[counter] = stack_to_rotate->stack[counter+1];
        counter++;
    }
    stack_to_rotate->stack[counter] = bottom_val;
}

// // @Very costly operation, Creating an new Stack on every rotation is computationally expensive in Scaling 
// void rotate_stack_values_shift_down(Stack *stack_to_rotate){
//     Stack *temp_stack;
//     int bottom_ele;

//     temp_stack = initialize_stack(stack_to_rotate->size);
//     while(isempty(stack_to_rotate)){
//         push(temp_stack, pop(stack_to_rotate));
//     }
//     bottom_ele = pop(temp_stack);
//     while(isempty(temp_stack)){
//         push(stack_to_rotate, pop(temp_stack));
//     }
//     push(stack_to_rotate, bottom_ele);
//     free_stack(temp_stack);
// }


