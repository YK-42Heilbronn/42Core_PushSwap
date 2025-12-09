/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:41:18 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/09 15:57:07 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "move_a_to_b.h"

void initial_sorting(Stack *stack_a, Stack *stack_b){
    int ind;
    int iter;
    // int stack_b_top;

    // ft_printf("stack_a %d\n", stack_a->top);
    print_stack(stack_a);
    // if (is_stack_ascending(stack_a)){
    //     ft_printf("stack_a is already sorted in ascending order\n");
    // }
    // if (is_stack_decending(stack_a)){
    //     ft_printf("stack_a is already sorted in decending order\n");
    // }
    iter = 0;
    while(iter < 1){  // (stack_a->top == stack_a->size-1 && is_stack_ascending(stack_a))
        ind = stack_a->top;
        // stack_b_top = if(isempty(stack_b)) 0; else stack_b->top;
        ft_printf("<<<<%d>>>>\n", ind);
        while (stack_a->top>0){
            sort_stack_a(stack_a, stack_b);
            ft_printf("(((((%d, %d)))))\n", ind, stack_a->top);
            if (ind%2==0){
                if(is_stack_ascending(stack_a, 0)){
                    print_stack(stack_a);
                }
                if(is_stack_decending(stack_b, 0)){
                    print_stack(stack_b);
                }
                ft_printf("A:: ");
                print_stack(stack_a);
                ft_printf("\nB:: ");
                print_stack(stack_b);
                ft_printf("\n");
            }
            if (stack_a->top==1){
                ft_printf("============= top is 1 ==========");
                // sort_last_3_elements(stack_a, stack_b);
                // swap_top_2_values_of_stack(stack_a);
                break;
            }
            ind--;
            ft_printf("------------------------");
        }
        ft_printf("---------iteration over %d----------\n", iter);
        iter++;
        ft_printf("A:: ");
        print_stack(stack_a);
        ft_printf("B:: ");
        print_stack(stack_b);
        ft_printf("\n");
    }
    // ind = 0;
    while(1){
        if (stack_b->stack[0] < stack_b->stack[stack_b->top]){
            push_top_2_values_of_stacks(stack_b, stack_a);
            // rotate_stack_values_shift_up(stack_a);
            break;
        }
        else{
            rotate_stack_values_shift_down(stack_b);
            push_top_2_values_of_stacks(stack_b, stack_a);
            // rotate_stack_values_shift_up(stack_a);
        }
    }
    // push_top_2_values_of_stacks(stack_b, stack_a);
    // push_top_2_values_of_stacks(stack_b, stack_a);
    // push_top_2_values_of_stacks(stack_b, stack_a);
    // rotate_stack_values_shift_up(stack_a);
    ft_printf("A:: ");
    print_stack(stack_a);
    ft_printf("B:: ");
    print_stack(stack_b);
    ft_printf("\n");
    
    // if (is_stack_ascending(stack_a)){
    //     ft_printf("stack_a is already sorted in ascending order\n");
    // }
    // if (is_stack_decending(stack_a)){
    //     ft_printf("stack_a is already sorted in decending order\n");
    // }
    // ft_printf("\nstack_b %d\n", stack_b->size);
    // sorting_b_stack_only(stack_a, stack_b);
}

void sort_stack_a(Stack *stack_a, Stack *stack_b){
    if (stack_a->top > 0){   // atlease 2 elements needed for sorting
        if (max_swap(stack_a))
            swap_top_2_values_of_stack(stack_a);
        if (min_rotate(stack_a))  //else if
            rotate_stack_values_shift_up(stack_a);
        // else{
        if (!max_swap(stack_a) & (!min_rotate(stack_a))){
            push_top_2_values_of_stacks(stack_a, stack_b);
            sort_stack_b(stack_b);   
        }
        // }
    }
}

// @NewVersion
// void sort_stack_a(Stack *stack_a, Stack *stack_b){
//     if (stack_a->top > 0){
//         if (stack_a->stack[stack_a->top] > stack_a->stack[stack_a->top-1])  // {bring} ||min ele|| to "top" of [top, top-1]
//             swap_top_2_values_of_stack(stack_a);
//         else if (stack_a->stack[stack_a->top] < stack_a->stack[0])  // {move} ||min ele|| to "bottom" of [0, top]
//             rotate_stack_values_shift_up(stack_a);
//         else{
//             push_top_2_values_of_stacks(stack_a, stack_b);
//             sort_stack_b(stack_b);
//         }
//     }
// }

void sort_stack_b(Stack *stack_b){
    if (stack_b->top > 0){  // stack_b->top > 0 stack_b_top
        if (min_swap(stack_b)) // {bring} ||min ele|| to "top" of [top, top-1]
            swap_top_2_values_of_stack(stack_b);
        if (max_rotate(stack_b))  // {move} ||min ele|| to "bottom" of [0, top]  // else if
            rotate_stack_values_shift_up(stack_b);
        // else
        //     return;
    }
}

// @OldVersion
// void sort_stack_b(Stack *stack_b){
//     if (stack_b->top > 0){
//         if (stack_b->stack[stack_b->top] < stack_b->stack[stack_b->top-1]) // {bring} ||max ele|| to "top" of [top, top-1]
//             swap_top_2_values_of_stack(stack_b);
//         else if (stack_b->stack[stack_b->top] > stack_b->stack[0])  // {move} ||max ele|| to "bottom" of [0, top]
//             rotate_stack_values_shift_up(stack_b);
//         // else
//         //     return;
//     }
// }

void push_swap(Stack *stack_a, Stack *stack_b){
    Stack **max_stack;
    Stack **min_stack;
    // int i;

    max_stack = info_stack(8);
    min_stack = info_stack(2);
    // i = max_stack[0]->size;
    // while (i>0){
    //     if (max_stack[0]->stack[i])
    //         ft_printf("if: %d\n", max_stack[0]->stack[i]);
    //     else
    //         ft_printf("NULL %d\n", max_stack[0]->stack[i]);
    //     i--;
    // }
    // ft_printf("%p\n", max_stack);
    // ft_printf("%p\n", min_stack);
    initial_sorting(stack_a, stack_b);
    // initial_sorting(stack_b, stack_a);
    while (!(isempty(stack_b))){
        sorting_b_stack_only(stack_a, stack_b, max_stack, min_stack);  // stack_a,
        // ft_printf("{{{{{{{{{{{{{{{{{{{b empty?: %d}}}}}}}}}}}}}}}}}}}\n", isempty(stack_b));  
        // clean_double_stack_ptr(max_stack, 2);
        // max_stack=NULL;
        // clean_double_stack_ptr(min_stack, 2);
        // min_stack=NULL;
        // max_stack = info_stack(8);
        // min_stack = info_stack(2);
    
        // ft_printf("%d\n", max_stack[0]->size);
        // // print_stack(max_stack[0]);
        // i=max_stack[0]->size;
        // while (i>0){
        //     if (max_stack[0]->stack[i])
        //         ft_printf("if: %d\n", max_stack[0]->stack[i]);
        //     else
        //         ft_printf("NULL %d\n", max_stack[0]->stack[i]);
        //     i--;
        // }
        
        // sorting_b_stack_only(stack_a, stack_b, max_stack, min_stack);  // stack_a,
        // ft_printf("{{{{{{{{{{{{{{{{{{{b empty?: %d}}}}}}}}}}}}}}}}}}}\n", isempty(stack_b)); 
        clean_double_stack_ptr(max_stack, 2);
        max_stack=NULL;
        clean_double_stack_ptr(min_stack, 2);
        min_stack=NULL;
        max_stack = info_stack(8);
        min_stack = info_stack(2);   
        // sorting_b_stack_only(stack_a, stack_b, max_stack, min_stack);  // stack_a,
        ft_printf("{{{{{{{{{{{{{{{{{{{b empty?: %d}}}}}}}}}}}}}}}}}}}\n", isempty(stack_b)); 
    }
    // move min eles from bottom to top

    // check ascending order of stack_a

    /* if yes -> end program
    else -> Error message "Stack is unsorted || BUG" */
    ft_printf("A:: ");
    print_stack(stack_a);
    ft_printf("B:: ");
    print_stack(stack_b);
    ft_printf("\n");
}
