/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:09 by clingier          #+#    #+#             */
/*   Updated: 2018/10/16 11:56:06 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t len1;
	size_t len2;
	size_t len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	len = (len1 > len2) ? len1 : len2;
	return (ft_memcmp(s1, s2, len));
}
