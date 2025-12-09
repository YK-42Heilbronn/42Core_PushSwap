/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:50:08 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/02 12:47:37 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/* 
1. check for duplication of the arguments - if yes -> Error

*/
void parser(int argc, char **argv, Stack *stack_a){
    // the command line arguments must be parsed & 
    // datatype conversion is crucial for math operations
    int ind;

    ind = argc-1;
    // if (argc < 101)
    //     exit(0);
    while(ind > 0){  // this handles only ascii numbers('1', '2', '3' etc)
            // *parsed_stack_a = atoi(argv[i]);

            // digit words must be handled seperately
            if (*argv[ind]){
                // write(0, argv[i], ft_strlen(argv[i]));
                // write(0, "\n", 1);
                // ft_printf("%s\n", argv[argc-ind]);
                push(stack_a, ft_atoi(argv[ind]));
                ind--;
            }
            
        }
    
} 

