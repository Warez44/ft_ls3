/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:02:51 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 11:40:28 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	malcheck(void *ptr)
{
	if (!ptr)
	{
		ft_putendl_fd("Not enough memory...", 2);
		exit(EXIT_FAILURE);
	}
}
