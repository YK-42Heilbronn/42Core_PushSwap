/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:05:25 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/28 01:13:26 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_arg_string(const char *s, long *stack, int *i, t_data *data);
static int	parse_one_token(const char *s, int start, long *out_value);
static long	atoi_wrapper(const char *start, int len);
static void	parser(char *argvs[], long **pt_stack, t_data *data);

/* public: parse argv into stack[], also check duplicates here */
long	*prepare_stack(int argc, char *argvs[], int *arr_size)
{
	int		len;
	long	*stack;
	t_data	data;

	clean_argvs(argc, argvs, &len);
	*arr_size = len;
	stack = (long *)malloc(sizeof(long) * len);
	if (!stack)
		print_error_exit(NULL);
	data.seen = (long *)malloc(sizeof(long) * len);
	if (!data.seen)
	{
		free(stack);
		print_error_exit(NULL);
	}
	parser(argvs, &stack, &(data));
	return (stack);
}

static void	parser(char *argvs[], long **pt_stack, t_data *data)
{
	int		i;
	long	*stack;

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
static int	parse_arg_string(const char *s, long *stack, int *i, t_data *data)
{
	int		j;
	long	value;

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
static int	parse_one_token(const char *s, int start, long *out_value)
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
static long	atoi_wrapper(const char *start, int len)
{
	char	*substr;
	long	num;

	if (!start || len <= 0)
		return (0);
	substr = ft_substr(start, 0, len);
	if (!substr)
		return (0);
	num = ft_atol(substr);
	free(substr);
	return (num);
}
