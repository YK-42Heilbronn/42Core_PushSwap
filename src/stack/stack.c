/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:02:30 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/23 16:24:43 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

Stack* initialize_stack(int size){
    Stack *ptr_stack;

    ptr_stack = (Stack*)malloc(sizeof(Stack));
    if (!ptr_stack)
        return NULL;
    ptr_stack->size = size;
    
    ptr_stack->stack = (int *)malloc(sizeof(int)*ptr_stack->size);
    if (!ptr_stack->stack){
        free(ptr_stack);
        return NULL;
    }
        
    ptr_stack->top = -1;

    return ptr_stack;
}

void free_stack(Stack *stack){
    if (stack->stack)
        free(stack->stack);
}
