/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:48:10 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 07:05:47 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_atoi(const char *string)
{
	long	sign;
	long	number;
	long	temp;
	char	*str;

	str = (char *)string;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
	{
		temp = number;
		number *= 10;
		number += sign * (long)(*str - 48);
		if (temp && (number ^ temp) < 0)
			return ((sign < 0) ? (int)LONG_MIN : (int)LONG_MAX);
		str++;
	}
	return ((int)(number));
}
