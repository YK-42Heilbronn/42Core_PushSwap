/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:22:27 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/28 13:42:32 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int main(int argc, char *argv[]){
    Stack *stack_a;
    Stack *stack_b;
    
    if (argc > 1){
        stack_a = initialize_stack(argc-1);
        stack_b = initialize_stack(argc-1);

        parser(argc, argv, stack_a);
        push_swap(stack_a, stack_b);
        // ft_printf("%d", is_stack_ascending(stack_a));
    }
    // else part is error handling
    // do not forget to handle memory leaks
}

void print_stack(Stack *stack){
    int i;

    i=0;
    while(i<=stack->top){
        ft_printf("%d ", stack->stack[i]);
        i++;
    }
    ft_printf("\n");
}

void push_swap(Stack *stack_a, Stack *stack_b){
    int ind;
    int iter;

    // ft_printf("stack_a %d\n", stack_a->top);
    print_stack(stack_a);
    iter = 0;
    while(iter < 5){
        ind = stack_a->top;
        ft_printf("<<<<%d>>>>\n", ind);
        while (ind > 0){
            sort_stack_a(stack_a, stack_b);
            ft_printf("(((((%d, %d)))))\n", ind, stack_a->top);
            if (ind%2==0){
                if(is_stack_ascending(stack_a)){
                    print_stack(stack_a);
                }
                if(is_stack_decending(stack_b)){
                    print_stack(stack_b);
                }
                print_stack(stack_a);
                print_stack(stack_b);
            }
            if (stack_a->top==1){
                ft_printf("============= top is 1 ==========");
                sort_last_3_elements(stack_a, stack_b);
            }
            ind--;
            ft_printf("------------------------");
        }
        iter++;
        ft_printf("---------iteration over----------\n");
        print_stack(stack_a);
        print_stack(stack_b);
    }
    // ft_printf("\nstack_b %d\n", stack_b->size);
    
}

void sort_last_3_elements(Stack *stack_a, Stack *stack_b){
    // if (stack_a->stack[stack_a->top] > stack_a->stack[stack_a->top-1] &
    // stack_a->stack[stack_a->top] < stack_a->stack[0]){
    push_top_2_values_of_stacks(stack_a, stack_b);
    sort_stack_b(stack_b);
    // }
}


// void push_swap(Stack *stack_a, Stack *stack_b){
//     // int next_top;

//     // next_top = stack_a->top-1;
//     // ft_printf("stack_a %d\n", stack_a->top);
//     while(1){
//         // ft_printf("ind-%d - %d\n", ind, stack_a->stack[ind]);
//         if ((stack_a->stack[stack_a->top] > stack_a->stack[stack_a->top-1])){  // || (isempty(stack_b))
//             swap_ops(stack_a, stack_b, 0);
//         }
//         else if ((stack_b->stack[stack_b->top] > stack_b->stack[stack_b->top-1])){
//             swap_ops(stack_a, stack_b, 1);
//         }
//         else
//             swap_ops(stack_a, stack_b, 2);
//         // ------------------------------
//         if ((stack_a->stack[stack_a->top] > stack_a->stack[0])){
//             rotate_ops(stack_a, stack_b, 0);
//         }
//         else
//             reverse_rotate_ops(stack_a, stack_b, 0);

//         if ((stack_b->stack[stack_b->top] > stack_b->stack[0])){
//             rotate_ops(stack_a, stack_b, 1);
//         }
//         else
//             reverse_rotate_ops(stack_a, stack_b, 1);

//         if ((stack_a->stack[stack_a->top] > stack_a->stack[0]) && (stack_b->stack[stack_b->top] > stack_b->stack[0]))
//             rotate_ops(stack_a, stack_b, 2);
//         else
//             reverse_rotate_ops(stack_a, stack_b, 2);
//         // -------------------------------
//         if (stack_a->stack[stack_a->top]<stack_b->stack[stack_b->top])
//             push_ops(stack_b, stack_a, 0);
//         else
//             push_ops(stack_a, stack_b, 1);   
//         // ind++;
//     }
//     // ft_printf("\nstack_b %d\n", stack_b->size);
    
// }

// void move_in_a_stack(Stack *stack){
//     // swap, rotate & reverse_rotate are performed on a single stack itself
//     if (stack->stack[stack->top] > stack->stack[stack->top-1])
//     {
//         swap(stack);
//         move_in_a_stack(stack);
//     }
//     else if (stack->stack[stack->top] > stack->stack[0])
//         rotate(stack); // or reverse_rotate(stack) && push(stack_a, stack_b)
//     else
//         // push(stack_a, stack_b);
//         move_bw_stacks(stack, stack_b);
// }

// void move_bw_stacks(Stack *stack_a, Stack *stack_b){
//     /* 
//     push alone needs minimum two stacks to perform
//     whenever a new element is added to the stack(either a or b), do following updates:
//         1. check swap conditions of a & b --> do swap - ss
//         2. check rotate conditions of a & b --> do rotate - rr
//         3. check reverse rotate conditions of a & b --> do reverse rotate - rrr
//  */
// }

void sort_stack_a(Stack *stack_a, Stack *stack_b){
    if (stack_a->top > 0){
        if (stack_a->stack[stack_a->top] < stack_a->stack[stack_a->top-1])
            swap_top_2_values_of_stack(stack_a);
        else if (stack_a->stack[stack_a->top] > stack_a->stack[0])
            rotate_stack_values_shift_up(stack_a);
        else{
            push_top_2_values_of_stacks(stack_a, stack_b);
            sort_stack_b(stack_b);
        }
    }
}

void sort_stack_b(Stack *stack_b){
    if (stack_b->top > 0){
        if (stack_b->stack[stack_b->top] > stack_b->stack[stack_b->top-1])
            swap_top_2_values_of_stack(stack_b);
        else if (stack_b->stack[stack_b->top] < stack_b->stack[0])
            rotate_stack_values_shift_up(stack_b);
        // else
        //     return;
    }
}


int is_stack_ascending(Stack *stack){
/* 
    stack indexes = 0 1 2 3 4 5 ..... n(top)  || you stand & look from here
    ascending means = always stack[0]=max & stack[n]=min 
     */
    int ind;

    ind = 0;
    while(ind < stack->top){
        if (stack->stack[ind] < stack->stack[ind+1]){
            return 0;
        }
        ind++;
    }
    return 1;
}

int is_stack_decending(Stack *stack){
/* 
    stack_indexes = 0 1 2 3 4 5 ..... n(top)   || you stand & look from here
    descending means = always stack[0]=min & stack[n]=max
     */
    int ind;

    ind = 0;
    while(ind < stack->top){
        if (stack->stack[ind] > stack->stack[ind+1]){
            return 0;
        }
        ind++;
    }
    return 1;
}

// int insertion_index_of_element(Stack *stack){
//     int ind;

//     ind = 1;
//     while(ind <= stack->top){
//         if ((stack->stack[stack->top] < stack->stack[ind]) & 
//         (stack->stack[stack->top] > stack->stack[ind-1])){
//             return ind;
//         }
//         ind++;
//     }
//     return ind;  // if ind=stack->top, then no operation needs to be performed
// }

