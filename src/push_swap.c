/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:22:27 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 21:10:25 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char *argv[]){
    if argc > 0{
        unsigned int *parsed_stack_a = (void *)malloc(argc*sizeof(int));
        // isdigit(), only numbers are allowed, otherwise ERROR
        while(!*argv){  // this handles only ascii numbers('1', '2', '3' etc)
            *parsed_stack_a = atoi(*argv);
            // digit words must be handled seperately
        }
        push_swap(stack_a)
    }
    // else part is error handling
    // do not forget to handle memory leaks
}

void push_swap(unsigned int *stack_a){
    stack_a = initialize_stack(100);
    stack_b = initialize_stack(100);
    
    

}

