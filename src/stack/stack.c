/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:02:30 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 21:05:47 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

Stack initialize_stack(int size){
    Stack temp_stack;

    temp_stack.size = size;
    temp_stack.stack = (int *)malloc(sizeof(int)*temp_stack.size);
    if (!temp_stack.stack)
        temp_stack.stack=NULL;
        
    temp_stack.top = -1;
    return temp_stack;
}

void free_stack(Stack *stack){
    if (stack->stack)
        free(stack->stack);
}
