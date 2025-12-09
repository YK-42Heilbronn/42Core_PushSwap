/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:27:14 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/03 18:58:30 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_stack(Stack *stack){
    int i;

    i=0;
    while(i<=stack->top){
        ft_printf("%d ", stack->stack[i]);
        i++;
    }
    ft_printf("\n");
}

int is_stack_ascending(Stack *stack, int start){
/* 
    stack indexes = 0 1 2 3 4 5 ..... n(top)  || you stand & look from here
    ascending means = always stack[0]=max & stack[n]=min 
     */
    int ind;

    ind = start;
    while(ind < stack->top){
        if (stack->stack[ind] < stack->stack[ind+1]){
            return 0;
        }
        ind++;
    }
    return 1;
}

int is_stack_decending(Stack *stack, int start){
/* 
    stack_indexes = 0 1 2 3 4 5 ..... n(top)   || you stand & look from here
    descending means = always stack[0]=min & stack[n]=max
     */
    int ind;

    ind = start;
    while(ind < stack->top){
        if (stack->stack[ind] > stack->stack[ind+1]){
            return 0;
        }
        ind++;
    }
    return 1;
}
