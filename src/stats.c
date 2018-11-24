/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:38:16 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:36:36 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <lflag.h>

void	getstats(t_file *files, unsigned char flags)
{
	int i;

	i = 0;
	while (i < files->len)
	{
		if (lstat(files[i].fpath, &files[i].stats) == -1)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putendl_fd(strerror(errno), 2);
		}
		i++;
	}
	if (flags & L_FLAG)
	{
		getlenlnk(files);
		getlensiz(files);
		getmaxstr(files);
	}
}
