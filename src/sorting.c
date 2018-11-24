/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:08:53 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:35:17 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	swapfiles(t_file *t_fi, t_file *t_fj)
{
	char *temp;

	temp = (*t_fi).fpath;
	(*t_fi).fpath = (*t_fj).fpath;
	(*t_fj).fpath = temp;
	temp = (*t_fi).fname;
	(*t_fi).fname = (*t_fj).fname;
	(*t_fj).fname = temp;
}

void	sort(t_file *t_f, int (*f)(const char *, const char *), int rev)
{
	int	i;
	int	j;

	i = 0;
	while (i < t_f->len)
	{
		j = i + 1;
		while (j < t_f->len)
		{
			if ((f(t_f[i].fpath, t_f[j].fpath) > 0 && !rev) ||
			(f(t_f[i].fpath, t_f[j].fpath) < 0 && rev))
				swapfiles(&t_f[i], &t_f[j]);
			if ((f(t_f[i].fpath, t_f[j].fpath) == 0) && (
			(ft_strcmp(t_f[i].fpath, t_f[j].fpath) < 0 && rev) ||
			(ft_strcmp(t_f[i].fpath, t_f[j].fpath) > 0 && !rev)))
				swapfiles(&t_f[i], &t_f[j]);
			j++;
		}
		i++;
	}
}

int		ft_timecmp(const char *file1, const char *file2)
{
	struct stat stat1;
	struct stat stat2;

	lstat(file1, &stat1);
	lstat(file2, &stat2);
	return ((int)stat2.st_mtime - stat1.st_mtime);
}

t_file	*sortingfiles(t_file *files, unsigned char flags)
{
	int (*sort_function)(const char *, const char *);

	sort_function = (flags & T_FLAG) ? &ft_timecmp : &ft_strcmp;
	if (flags & R_MIN_FLAG)
		sort(files, sort_function, 1);
	else
		sort(files, sort_function, 0);
	return (files);
}
