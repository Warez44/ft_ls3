/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:49:30 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:27:45 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		getnumberoffiles(char *directory, unsigned char *flags)
{
	int				count;
	struct dirent	*dp;
	DIR				*dir;

	count = 0;
	errno = 0;
	dir = opendir(directory);
	if (errno != 0)
	{
		ft_putstr_fd("ls: ", 2);
		perror(directory);
		*flags = *flags | 128;
		return (0);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || (*flags & 2))
			count++;
	}
	closedir(dir);
	return (count);
}

char	*get_file_path(char *directory, char *filename)
{
	char *res;
	char *temp;

	malcheck(res = ft_strjoin(directory, "/"));
	temp = res;
	malcheck(res = ft_strjoin(res, filename));
	free(temp);
	return (res);
}

void	get_fname_fpath(t_file *file, char *str, char *directory, int n_o_f)
{
	malcheck(file->fname = ft_strdup(str));
	malcheck(file->fpath = get_file_path(directory, file->fname));
	file->len = n_o_f;
}

t_file	*readfiles(char *directory, unsigned char flags)
{
	t_file			*files;
	int				num_o_files;
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	num_o_files = getnumberoffiles(directory, &flags);
	if (num_o_files == 0 || flags & 128)
		return (NULL);
	files = (t_file *)malloc(sizeof(*files) * num_o_files);
	dir = opendir(directory);
	i = 0;
	while ((dp = readdir(dir)) != NULL)
		if (dp->d_name[0] != '.' || (flags & A_FLAG))
			get_fname_fpath(&files[i++], dp->d_name, directory, num_o_files);
	files = sortingfiles(files, flags);
	closedir(dir);
	return (files);
}
