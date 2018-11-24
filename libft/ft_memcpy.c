/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 08:33:43 by clingier          #+#    #+#             */
/*   Updated: 2018/10/16 12:15:08 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *s;
	char *d;

	if (src == dest)
		return (dest);
	s = (char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
