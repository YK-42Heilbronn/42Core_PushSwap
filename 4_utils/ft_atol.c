/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykonka <ykonka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:39:33 by ykonka            #+#    #+#             */
/*   Updated: 2026/02/28 00:39:46 by ykonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == 45 || *str == 43)
	{
		minus = 44 - *str;
		str++;
	}
	while (*str)
		if (*str >= 48 && *str <= 57)
			result = (result * 10) + (*str++ - 48);
	return (result * minus);
}
