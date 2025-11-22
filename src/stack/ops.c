/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:57:13 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 19:01:51 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stack.h"

/* 
pseudocode:

resources:
    1. https://www.geeksforgeeks.org/c/implement-stack-in-c/
*/ 
  
void push(Stack *stack, int value){
    if (isfull(stack)){
        return;
    }
    stack->stack[++stack->top] = value;
}

int pop(Stack *stack){
    if (isempty(stack)){
        return -1;
    }
    return stack->stack[stack->top--];
}

int peek(Stack *stack){
    if (isempty(stack)){
        return -1;
    }
    return stack->stack[stack->top];
}

int isempty(Stack *stack){
    if (stack->top == -1){
        return 1; //True
    }
    return 0; //False
}

int isfull(Stack *stack){
    if (stack->top == stack->size-1){
        return 1; //True
    }
    return 0; //False
}
