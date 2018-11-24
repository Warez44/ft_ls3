/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:44:36 by clingier          #+#    #+#             */
/*   Updated: 2018/10/08 07:10:14 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	int		len;
	int		neg;
	char	*str;

	neg = (nbr < 0) ? 1 : 0;
	len = ft_len(nbr);
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (neg)
		str[0] = '-';
	nbr = (nbr < 0) ? -nbr : nbr;
	while (--len >= neg)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
