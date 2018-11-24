/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:04:32 by clingier          #+#    #+#             */
/*   Updated: 2018/10/16 12:17:25 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len)
	{
		*((char *)dst) = *((char *)src);
		if ((char)(c) == *((char*)dst))
			return (dst + 1);
		dst++;
		src++;
		len--;
	}
	return (NULL);
}
