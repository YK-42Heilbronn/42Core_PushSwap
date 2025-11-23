/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:05:00 by ykonka            #+#    #+#             */
/*   Updated: 2025/11/22 21:29:25 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// void parser(){
//     // the command line arguments must be parsed & 
//     // datatype conversion is crucial for math operations
    
// } 


void swap_bw_two_stacks(unsigned int *a, unsigned int *b){
    // a is a pointer - stores address of an variable
    // b is a pointer - stores address of an variable

    int temp;
    // printf("a %d b %d\n", *a, *b);
    // printf("aptr %p bptr %p\n", a, b);
    temp = *a; 
    // printf("temp %d \n", temp);
    *a = *b;
    // printf("a %d aptr %p\n", *a, a);
    *b = temp;
    // printf("b %d bptr %p\n", *b, b);
}


int get_top_index(unsigned int *stack){
    int ind;

    ind = -1;
    while(*stack++){
        ind++;
    }
    return ind;
}

void push_to_stack(unsigned int *take_from, unsigned int *place_on){
    place_on[get_top_index(place_on)+1] = take_from[get_top_index(take_from)];
    // printf("%d\n", place_on[get_top_index(place_on)+1]);
    // free(&take_from[get_top_index(take_from)]);
    take_from[get_top_index(take_from)] = 0;
}


// void print_double_ptr(int *ptr){
//     char *str;
    
//     while(*ptr){
//         str = ft_itoa(*ptr);
//         // printf("%s\n", str);
//         ptr++;
//         write(0, str, ft_strlen(str));
//         write(0, "\n", 1);
//     }
// }



