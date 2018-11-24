/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:50:26 by clingier          #+#    #+#             */
/*   Updated: 2018/11/02 13:07:04 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	if (!*sub)
		return ((char *)str);
	while (*str && n)
	{
		if (ft_strncmp(str, sub, ft_strlen(sub)) == 0 && ft_strlen(sub) <= n)
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}
