/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:05:25 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:51:58 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_arg_string(const char *s, int *stack, int *i, t_data *data);
static int	parse_one_token(const char *s, int start, int *out_value);
static int	atoi_wrapper(const char *start, int len);
static void	parser(char *argvs[], int **pt_stack, t_data *data);

/* public: parse argv into stack[], also check duplicates here */
int	*prepare_stack(int argc, char *argvs[], int *arr_size)
{
	int		len;
	int		*stack;
	t_data	data;

	clean_argvs(argc, argvs, &len);
	*arr_size = len;
	stack = (int *)malloc(sizeof(int) * len);
	if (!stack)
		print_error_exit(NULL);
	data.seen = (int *)malloc(sizeof(int) * len);
	if (!data.seen)
	{
		free(stack);
		print_error_exit(NULL);
	}
	parser(argvs, &stack, &(data));
	return (stack);
}

static void	parser(char *argvs[], int **pt_stack, t_data *data)
{
	int	i;
	int	*stack;

	i = 0;
	data->used = 0;
	stack = *pt_stack;
	argvs++;
	while (*argvs)
	{
		if (!parse_arg_string(*argvs, stack, &i, data))
		{
			free(stack);
			free(data->seen);
			print_error_exit(NULL);
		}
		argvs++;
	}
	free(data->seen);
}

/* Parse one argv string like "-1 23   +32" into stack[] */
/* Parse one argv string like "-1 23   +32" into stack[] + duplicate check */
static int	parse_arg_string(const char *s, int *stack, int *i, t_data *data)
{
	int	j;
	int	value;

	j = 0;
	while (s[j])
	{
		while (s[j] && ft_is_space(s[j]))
			j++;
		if (!s[j])
			break ;
		j = parse_one_token(s, j, &value);
		if (is_duplicate(data->seen, data->used, value))
			return (0);
		data->seen[data->used] = value;
		(data->used)++;
		stack[*i] = value;
		(*i)++;
	}
	return (1);
}

/* return new index position after the token */
static int	parse_one_token(const char *s, int start, int *out_value)
{
	int	end;

	end = start;
	while (s[end] && !ft_is_space(s[end]))
		end++;
	*out_value = atoi_wrapper(s + start, end - start);
	return (end);
}

/* or handle alloc error differently */
/* ascii → int */
static int	atoi_wrapper(const char *start, int len)
{
	char	*substr;
	int		num;

	if (!start || len <= 0)
		return (0);
	substr = ft_substr(start, 0, len);
	if (!substr)
		return (0);
	num = ft_atoi(substr);
	free(substr);
	return (num);
}

// void	clean_argvs(int argc, char *argvs[], int *len)
// {
// 	char	*cleaned_str;
// 	int		ind;
// 	int		nums;
// 	int		flag;
// 	int i;

// 	nums = 0;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		cleaned_str = ft_strtrim(argvs[i], " /t/n/f/v/r");
// 		if (cleaned_str == NULL || *cleaned_str == '\0')
// 			print_error_exit(cleaned_str);
// 		ind = 0;
// 		flag = 1;
// 		while (cleaned_str[ind])
// 		{
// 			if (!ft_is_space(cleaned_str[ind]) &&
// 			!ft_isdigit(cleaned_str[ind]) &&
// 			!ft_isoperator(cleaned_str[ind]))
// 				print_error_exit(cleaned_str);
// 			else
// 			{
// 				if (ft_isoperator(cleaned_str[ind]))
// 				{
// 					if (cleaned_str[ind+1] != '\0'
// && !ft_isdigit(cleaned_str[ind+1]))
// 						print_error_exit(cleaned_str);
// 				}
// 				if (ft_isdigit(cleaned_str[ind]))
// 				{
// 					if (flag)
// 					{
// 						flag = 0;
// 						nums++;
// 					}
// 					else
// 						flag = 1;
// 				}
// 			}
// 			ind++;
// 		}
// 		free(cleaned_str);
// 		i++;
// 	}
// 	*len = nums;
// }

// int *prepare_stack(int argc, char *argvs[], int *arr_size)
// {
// 	int	len;

// 	int *stack;
// 	char *tmp;
// 	int index[2];
// 	int i;

// 	clean_argvs(argc, argvs, &len);
// 	printf("%d - %d\n", len, argc);
// 	stack = (int *)malloc(sizeof(int)*len);
// 	// arr_size = 0;  // NULL
// 	if (stack == NULL)
// 		return (NULL);
// 	// printf("%d \n", argc);
// 	*arr_size = len;
// 	// printf("size: %d\n", *arr_size);
// 	i = 0;
// 	argvs++;
// 	// printf("%s\n", *argvs);
// 	while (*argvs)
// 	{
// 		// printf("%d \n", argc);
// 		tmp = *argvs;
// 		index[0] = 0;
// 		while (tmp[index[0]])
// 		{
// 			// printf("%s\n", tmp);
// 			while (tmp[index[0]] && ft_is_space(tmp[index[0]]))
// 				index[0]++;
// 			index[1] = index[0];
// 			while (tmp[index[1]] && (ft_isoperator(tmp[index[1]])
// || ft_isdigit(tmp[index[1]])))
// 				index[1]++;
// 			// printf("%d - %d\n", index[0], index[1]);
// 			if (!tmp[index[1]])
// 			{
// 				stack[i] = atoi_wrapper(&tmp[index[0]], index[0], index[1]--);
// 				index[0] = index[1]++;
// 			}
// 			else
// 			{
// 				stack[i] = atoi_wrapper(&tmp[index[0]], index[0], index[1]);
// 				index[0] = index[1];
// 			}
// 			printf("%d\n", stack[i]);
// 			i++;
// 		}
// 		argvs++;
// 	}
// 	return (stack);
// 	// return (NULL);
// }
