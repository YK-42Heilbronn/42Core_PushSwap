/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:28:25 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:32:59 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_tokens_in_arg(char *arg);
static void	validate_char_or_exit(char c, char next);

void	clean_argvs(int argc, char *argvs[], int *len)
{
	int		i;
	int		total;
	char	*cleaned;

	total = 0;
	i = 1;
	while (i < argc)
	{
		cleaned = ft_strtrim(argvs[i], " \t\n\f\v\r");
		if (!cleaned || *cleaned == '\0')
			print_error_exit(cleaned);
		total += count_tokens_in_arg(cleaned);
		free(cleaned);
		i++;
	}
	*len = total;
}

/* operator, handled by validate_char_or_exit */
static int	count_tokens_in_arg(char *arg)
{
	int	i;
	int	nums;
	int	in_token;

	i = 0;
	nums = 0;
	in_token = 0;
	while (arg[i])
	{
		validate_char_or_exit(arg[i], arg[i + 1]);
		if (ft_is_space(arg[i]))
			in_token = 0;
		else if (ft_isdigit(arg[i]))
		{
			if (!in_token)
				nums++;
			in_token = 1;
		}
		else
			in_token = 0;
		i++;
	}
	return (nums);
}

static void	validate_char_or_exit(char c, char next)
{
	if (!ft_is_space(c) && !ft_isdigit(c) && !ft_isoperator(c))
		print_error_exit(NULL);
	if (ft_isoperator(c))
	{
		if (next != '\0' && !ft_isdigit(next))
			print_error_exit(NULL);
	}
}

/* O(n) duplicate check against values seen so far */
int	is_duplicate(int *seen, int used, int value)
{
	int	k;

	k = 0;
	while (k < used)
	{
		if (seen[k] == value)
			return (1);
		k++;
	}
	return (0);
}
