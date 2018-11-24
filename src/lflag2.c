/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:11:08 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:19:32 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <lflag.h>

char	*uidname(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	return (pwd->pw_name);
}

void	getlenlnk(t_file *files)
{
	unsigned int	max;
	int				i;
	int				len;

	max = 0;
	i = 0;
	len = 0;
	while (i < files->len)
	{
		if ((unsigned int)files[i].stats.st_nlink > max)
			max = (unsigned int)files[i].stats.st_nlink;
		i++;
	}
	if (max == 0)
		len = 1;
	while (max)
	{
		len++;
		max /= 10;
	}
	i = 0;
	while (i < files->len)
		files[i++].lenlnk = len;
}

void	getmaxstr(t_file *files)
{
	int i;
	int max[2];

	i = 0;
	max[0] = 0;
	max[1] = 0;
	while (i < files->len)
	{
		if ((int)ft_strlen(uidname(files[i].stats.st_uid)) > max[0])
			max[0] = ft_strlen(uidname(files[i].stats.st_uid));
		if ((int)ft_strlen(gidname(files[i].stats.st_gid)) > max[1])
			max[1] = ft_strlen(gidname(files[i].stats.st_gid));
		i++;
	}
	i = 0;
	while (i < files->len)
	{
		files[i].lenuid = max[0];
		files[i].lengid = max[1];
		i++;
	}
}

void	getlensiz(t_file *files)
{
	unsigned long	max;
	int				i;
	int				len;

	i = 0;
	max = 0;
	len = 0;
	while (i < files->len)
	{
		if ((unsigned long)files[i].stats.st_size > max)
			max = (unsigned long)files[i].stats.st_size;
		i++;
	}
	if (max == 0)
		len = 1;
	while (max)
	{
		len++;
		max /= 10;
	}
	i = 0;
	while (i < files->len)
		files[i++].lensiz = len;
}

void	putstr_format(char *str, int format)
{
	int len;

	len = ft_strlen(str);
	while (format - len > 0)
	{
		ft_putstr(" ");
		len++;
	}
	ft_putstr(str);
}
