/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:05:00 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/25 18:48:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void swap_top_2_values_of_stack(Stack *swap_stack){
    // a is a pointer - stores address of an variable
    // b is a pointer - stores address of an variable
    // if (swap_stack->top < 1){
    //     return;
    // }
    int temp;
    // printf("a %d b %d\n", *a, *b);
    // printf("aptr %p bptr %p\n", a, b);
    
    temp = swap_stack->stack[swap_stack->top]; 
    // printf("\ntemp %d \n", temp);
    swap_stack->stack[swap_stack->top] = swap_stack->stack[swap_stack->top-1];
    // printf("a %d\n", swap_stack->stack[swap_stack->top]);
    swap_stack->stack[swap_stack->top-1] = temp;
    // printf("b %d\n", swap_stack->stack[swap_stack->top-1]);
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
    if (isempty(take_from) || isfull(place_on))
        return;
    place_on->stack[place_on->top+1] = take_from->stack[take_from->top];
    place_on->top++;
    take_from->top--;
    // printf("%d\n", place_on[get_top_index(place_on)+1]);
    // free(&take_from[get_top_index(take_from)]);
    // take_from[get_top_index(take_from)] = 0;
}


void rotate_stack_values_shift_up(Stack *stack_to_rotate){
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

void rotate_stack_values_shift_down(Stack *stack_to_rotate){
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


