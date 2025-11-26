/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:50:08 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/26 15:00:09 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void parser(int argc, char **argv, Stack *stack_a){
    // the command line arguments must be parsed & 
    // datatype conversion is crucial for math operations
    int ind;

    ind = 1;
    // if (argc < 101)
    //     exit(0);
    while(ind < argc){  // this handles only ascii numbers('1', '2', '3' etc)
            // *parsed_stack_a = atoi(argv[i]);

            // digit words must be handled seperately
            if (*argv[ind]){
                // write(0, argv[i], ft_strlen(argv[i]));
                // write(0, "\n", 1);
                ft_printf("%s\n", argv[ind]);
                push(stack_a, ft_atoi(argv[ind]));
                ind++;
            }
            
        }
    
} 

