/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:56:28 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 20:29:59 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK
# define STACK

#include "stdlib.h"

typedef struct{
    int *stack;
    int top;
    int size;
} Stack;

// stack.c
Stack initialize_stack(int size);
void free_stack(Stack *stack);

// ops.c
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int isempty(Stack *stack);
int isfull(Stack *stack);

#endif