/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:54:57 by clingier          #+#    #+#             */
/*   Updated: 2018/11/02 13:09:09 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	if (*sub == '\0')
		return ((char *)str);
	while (*str)
	{
		if (*str == *sub && ft_memcmp(str, sub, ft_strlen(sub)) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
