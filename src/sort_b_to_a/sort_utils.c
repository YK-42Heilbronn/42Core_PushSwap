/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:10:42 by ykonka            #+#    #+#             */
/*   Updated: 2025/12/09 15:00:04 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sort_b_to_a.h"

void swap_stack_eles(Stack *swap_stack, int start_ind){
    int temp;
    
    temp = swap_stack->stack[start_ind];
    swap_stack->stack[start_ind] = swap_stack->stack[start_ind+1];
    swap_stack->stack[start_ind+1] = temp;
}

// Bubble Sort - largest element should be at the top of the stack - decending
void sort_max_stack_elements(Stack **max_stack){
    int ind;
    
    while(1){
        ind = 0;
        // ft_printf("it is in sort max stack eles");
        while (ind < max_stack[0]->top){
            if (max_stack[0]->stack[ind]>max_stack[0]->stack[ind+1]){
                swap_stack_eles(max_stack[0], ind);
                swap_stack_eles(max_stack[1], ind);
            }
            else{
                ind++;
                continue;
            }
            ind++;
        }
        if (is_stack_decending(max_stack[0], 0))  // max at top
        {
            // ft_printf("    sort breaked ----");
            break;
        }
            
    }
}

// Bubble Sort - smallest index should be at the top of the stack - ascending
// We need only this, not elements > which is an safety implementation
void sort_max_stack_indexes(Stack **max_stack){
    int ind;
    
    while(1){
        ind = 0;
        while (ind < max_stack[1]->top){
            if (max_stack[1]->stack[ind]<max_stack[1]->stack[ind+1]){
                swap_stack_eles(max_stack[0], ind);
                swap_stack_eles(max_stack[1], ind);
            }
            else{
                ind++;
                continue;
            }
            ind++;
        }
        if (is_stack_ascending(max_stack[1], 0))  // min at top
            break;
    }
}

void sort_min_stack_elements(Stack **max_stack){
    int ind;
    
    while(1){
        ind = 0;
        while (ind < max_stack[0]->top){
            if (max_stack[0]->stack[ind]<max_stack[0]->stack[ind+1]){
                swap_stack_eles(max_stack[0], ind);
                swap_stack_eles(max_stack[1], ind);
            }
            else{
                ind++;
                continue;
            }
            ind++;
        }
        if (is_stack_ascending(max_stack[0], 0))  // min at top
            break;
    }
}

// void preprocess_indexes(Stack **max_stack, int rr_or_rrr){
//     int ind;

//     ind = 0;
    
// }

void arrange_ele_in_max_stack(Stack **max_stack, int ele,  int top_ind){
    int ind;
    int top;

    ind = 0;
    top = max_stack[0]->size-1;
    // ft_printf("ele: %d, top_ind: %d, top: %d || ", ele, top_ind, top);
    // ft_printf("top ele: %d, top ind: %d \n", max_stack[0]->stack[top], max_stack[1]->stack[top]);
    while (ind <= top){
        // ft_printf("top ele: %d", max_stack[0]->stack[top]);
        if(max_stack[0]->stack[top])
            break;
        if (!max_stack[0]->stack[ind]){
            // initial filling, why push -> automatically increases top
            push(max_stack[0], ele);
            push(max_stack[1], top_ind);
            // ft_printf("if: %d(%d) ", max_stack[0]->stack[ind], ind);
            return;
        }else{
            ind++;
            continue;
        }
        ind++;
    }
    sort_max_stack_elements(max_stack);
    // print_stack(max_stack[0]);
    ind = max_stack[0]->top;
    while(ind >= 0){
        // this is exchanging eles with index
        if (ele > max_stack[0]->stack[ind]){
            if (ind > 0)
                insert_max_ele_in_stack(max_stack, ind);
            max_stack[0]->stack[ind]=ele;
            max_stack[1]->stack[ind]=top_ind;
            // ft_printf("else(if): %d(%d) ", max_stack[0]->stack[ind], ind);
            break;
        }
        ind--;
    }
    // ft_printf("\n");
}

void swap(int *ele1, int *ele2){
    int temp;

    temp = *ele1;
    *ele1 = *ele2;
    *ele2 = temp;
}

void insert_max_ele_in_stack(Stack **max_stack, int insert_ind){
    int ind;

    ind = 0;
    while (ind < insert_ind){
        swap(&max_stack[0]->stack[ind], &max_stack[0]->stack[ind+1]);
        swap(&max_stack[1]->stack[ind], &max_stack[1]->stack[ind+1]);
        ind++;
    }
}

void arrange_ele_in_min_stack(Stack **min_stack, int ele,  int top_ind){
    int ind;
    int top;

    ind = 0;
    top = min_stack[0]->size-1;
    // ft_printf("ele: %d, top_ind: %d || ", ele, top_ind);
    while (ind <= top){
        if (!min_stack[0]->stack[ind]){
            // initial filling, why push -> automatically increases top
            push(min_stack[0], ele);
            push(min_stack[1], top_ind);
            // ft_printf("if: %d(%d) ", min_stack[0]->stack[ind], ind);
            return;
        }
        ind++;
    }
    sort_min_stack_elements(min_stack);
    // print_stack(min_stack[0]);
    ind = top;
    while (ind >= 0){
        if (ele < min_stack[0]->stack[ind]){
            // this is exchanging eles with index
            if (ind > 0)
                insert_max_ele_in_stack(min_stack, ind);
            min_stack[0]->stack[ind]=ele;
            min_stack[1]->stack[ind]=top_ind;
            // ft_printf("else(if): %d(%d) ", min_stack[0]->stack[ind], ind);
            break;
        }
        ind--;
    }
    // ft_printf("\n");
}

void update_max_stack(Stack *max_index_stack, int shift_value){
    int ind;

    ind = 0;
    while (ind <= max_index_stack->top){
        max_index_stack->stack[ind++] += shift_value;
    }
}

int handle_min_eles(Stack *stack_a, Stack *stack_b, Stack **min_stack, Stack **max_stack){
    int ind;

    ind = 0;
    while(ind <= min_stack[0]->top){
        if (peek(stack_b) == min_stack[0]->stack[ind]){
            push_top_2_values_of_stacks(stack_b, stack_a);
            rotate_stack_values_shift_up(stack_a);
            update_max_stack(max_stack[1], -1);
            pop(min_stack[0]);
            pop(min_stack[1]);
            return 1;
        }
        ind++;
    }
    return 0;
}

