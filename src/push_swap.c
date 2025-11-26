/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:22:27 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/26 14:57:48 by ykonka           ###   ########.fr       */
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
    }
    // else part is error handling
    // do not forget to handle memory leaks
}


void push_swap(Stack *stack_a, Stack *stack_b){
    int ind;

    ind = 0;
    ft_printf("stack_a %d\n", stack_a->top);
    while(ind <= stack_a->top){
        ft_printf("%d ", stack_a->stack[ind]);
        ind++;
    }
    ft_printf("\nstack_b %d\n", stack_b->size);
    
}

