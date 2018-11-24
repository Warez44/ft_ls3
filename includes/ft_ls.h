/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:00:38 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:45:51 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define L_FLAG 1
# define A_FLAG 2
# define R_FLAG 4
# define R_MIN_FLAG 8
# define T_FLAG 16
# define ONLY_FILE 32

typedef struct	s_file
{
	struct stat		stats;
	char			*fname;
	char			*fpath;
	int				len;
	int				lenlnk;
	int				lensiz;
	int				lengid;
	int				lenuid;
}				t_file;

void			ft_ls(char *directory, unsigned char flags);
void			malcheck(void *ptr);
unsigned char	ft_flag(int argc, char **argv);
t_file			*readfiles(char *d, unsigned char f);
t_file			*sortingfiles(t_file *files, unsigned char flags);
void			lflag(t_file *files, unsigned char flags);
void			getstats(t_file *files, unsigned char flags);
char			*path_simplifier(char *str);
int				is_flag(char *str);
void			ls_exec(int argc, char **argv, unsigned char flags);
void			freefiles(t_file *files);
int				howmanyfile(char **argv, unsigned char flags);
void			freefiles(t_file *files);
void			sort_argv(char **argv);
int				isdir(char *fname, unsigned char flags);

#endif
