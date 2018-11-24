/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:02:09 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:43:26 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		isdir(char *fname, unsigned char flags)
{
	struct stat	lstats;
	struct stat	stats;
	int			retlstat;
	int			retstat;

	retlstat = lstat(fname, &lstats);
	retstat = stat(fname, &stats);
	if (!fname || !*fname)
		return (0);
	if (retlstat == 0 && retstat == -1)
		return (0);
	if (S_ISLNK(lstats.st_mode) && flags & L_FLAG)
		return (0);
	if (retlstat == -1)
		return (-1);
	return (S_ISDIR(lstats.st_mode) || S_ISDIR(stats.st_mode));
}

t_file	*get_multiple_files(char **argv, unsigned char flags)
{
	int		i;
	int		j;
	int		numfiles;
	t_file	*files;

	i = 0;
	j = 0;
	numfiles = howmanyfile(argv, flags);
	if (numfiles)
		files = (t_file*)malloc(sizeof(*files) * numfiles);
	while (argv[j])
	{
		if (!isdir(argv[j], flags))
		{
			malcheck(files[i].fname = ft_strdup(argv[j]));
			malcheck(files[i].fpath = ft_strdup(argv[j]));
			files[i].len = numfiles;
			if (flags & L_FLAG)
				if (lstat(files[i].fpath, &files[i].stats) == -1)
					continue ;
			i++;
		}
		j++;
	}
	return (files = sortingfiles(files, flags));
}

void	ls_multiple_dirs(char **argv, unsigned char flags, int err)
{
	int i;

	i = -1;
	sort_argv(argv);
	while (argv[++i])
		if (isdir(argv[i], flags) != 0 && isdir(argv[i], flags) != -1)
		{
			if ((howmanyfile(argv, flags) ||
				(!howmanyfile(argv, flags) && i != 0))
					&& (!err || howmanyfile(argv, flags)))
				ft_putstr("\n");
			err = 0;
			ft_putstr(argv[i]);
			ft_putendl(":");
			ft_ls(argv[i], flags);
		}
}

void	ls_multiple_path(char **argv, unsigned char flags)
{
	int		i;
	int		err;
	t_file	*files;

	i = -1;
	err = 0;
	while (argv[++i])
		if (isdir(argv[i], flags) == -1 && (err = 1))
		{
			ft_putstr_fd("ls: ", 2);
			perror(argv[i]);
		}
	if (howmanyfile(argv, flags) != 0 && !(i = 0))
	{
		files = get_multiple_files(argv, flags);
		if (flags & L_FLAG && (flags = flags | ONLY_FILE))
			lflag(files, flags);
		while (i < files->len && !(flags & L_FLAG))
			ft_putendl(files[i++].fname);
		freefiles(files);
	}
	ls_multiple_dirs(argv, flags, err);
}

void	ls_exec(int argc, char **argv, unsigned char flags)
{
	int		i;
	char	*directory;

	i = 0;
	sort_argv(argv);
	if ((argc == 0 || argc == 1) && (isdir(*argv, flags) || !*argv))
	{
		malcheck(directory = (argc == 0) ? ft_strdup(".") : ft_strdup(*argv));
		ft_ls(directory, flags);
		free(directory);
		return ;
	}
	while (argv[i])
		if (argv[i++][0] == '\0')
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			exit(0);
		}
	ls_multiple_path(argv, flags);
}
