/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:58:46 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/27 19:03:07 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error_exit(char *str)
{
	char	*error;

	error = "Error\n";
	write(1, error, ft_strlen(error));
	free(str);
	exit(1);
}
