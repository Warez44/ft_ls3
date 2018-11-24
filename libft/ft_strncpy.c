/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:53:56 by clingier          #+#    #+#             */
/*   Updated: 2018/10/07 19:53:59 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	while (len != 0)
	{
		if ((*d++ = *s++) == 0)
		{
			while (--len != 0)
				*d++ = 0;
			break ;
		}
		len--;
	}
	return (dst);
}
