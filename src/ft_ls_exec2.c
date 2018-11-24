/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_exec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:41:39 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:44:48 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	freefiles(t_file *files)
{
	int len;
	int i;

	len = files->len;
	i = 0;
	while (i < len)
	{
		free(files[i].fpath);
		free(files[i].fname);
		i++;
	}
	free(files);
}

int		howmanyfile(char **argv, unsigned char flags)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (argv[i])
		if (isdir(argv[i++], flags) == 0)
			count++;
	return (count);
}

void	sort_argv(char **argv)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}
