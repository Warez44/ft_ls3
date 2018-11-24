/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:07:54 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:40:22 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include "../includes/lflag.h"

void	putnbr_format(unsigned long num, int format)
{
	int				len;
	int				i;
	char			buf[format + 1];
	unsigned long	cp;

	cp = num;
	i = format - 1;
	ft_memset(buf, ' ', format);
	buf[format] = '\0';
	len = (num == 0) ? 1 : 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	num = cp;
	while (format - len <= i)
	{
		buf[i] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	ft_putstr(buf);
	ft_putstr(" ");
}

void	ft_specialcases(char *buf, mode_t mode)
{
	buf[9] = (mode & S_ISVTX) ? 't' : buf[9];
	buf[3] = (mode & S_ISUID) ? 's' : buf[3];
	if (mode & S_ISUID && !(mode & (S_IRWXU | S_IRWXG | S_IRWXO)))
		buf[3] = 'S';
	if (mode & S_ISVTX && !(mode & (S_IRWXU | S_IRWXG | S_IRWXO)))
		buf[9] = 'T';
}

void	strpermission(mode_t mode)
{
	size_t	i;
	char	characters[10];
	char	buf[13];

	i = 0;
	ft_strcpy(characters, "rwxrwxrwx");
	buf[0] = '-';
	buf[0] = (S_ISDIR(mode)) ? 'd' : buf[0];
	buf[0] = (S_ISBLK(mode)) ? 'b' : buf[0];
	buf[0] = (S_ISLNK(mode)) ? 'l' : buf[0];
	buf[0] = (S_ISFIFO(mode)) ? 'p' : buf[0];
	buf[0] = (S_ISCHR(mode) && !S_ISLNK(mode)) ? 'c' : buf[0];
	buf[0] = (S_ISSOCK(mode)) ? 's' : buf[0];
	while (i < 9)
	{
		buf[i + 1] = (mode & 1 << (8 - i)) ? characters[i] : '-';
		i++;
	}
	buf[10] = ' ';
	buf[11] = ' ';
	buf[12] = '\0';
	ft_specialcases(buf, mode);
	ft_putstr(buf);
}

void	putparams(t_file file)
{
	strpermission(file.stats.st_mode);
	putnbr_format(file.stats.st_nlink, file.lenlnk);
	putstr_format(uidname(file.stats.st_uid), file.lenuid);
	ft_putstr("  ");
	putstr_format(gidname(file.stats.st_gid), file.lengid);
	ft_putstr("  ");
	if (!S_ISCHR(file.stats.st_mode) && !S_ISBLK(file.stats.st_mode))
		putnbr_format(file.stats.st_size, file.lensiz);
	else
	{
		ft_putnbr(ft_major(file.stats.st_rdev));
		ft_putstr(", ");
		putnbr_format(ft_minor(file.stats.st_rdev), 4);
	}
	ft_puttime(&file.stats.st_mtime);
	ft_putstr(file.fname);
	if (S_ISLNK(file.stats.st_mode))
		putlink(file);
	ft_putstr("\n");
}

void	lflag(t_file *files, unsigned char flags)
{
	int i;

	i = 0;
	getstats(files, L_FLAG);
	if (!(flags & ONLY_FILE))
		puttotal(files);
	while (i < files->len)
		putparams(files[i++]);
}
