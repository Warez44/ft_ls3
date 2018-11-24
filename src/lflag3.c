/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:12:11 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:22:01 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <lflag.h>

void	year_trim(char *str)
{
	char *year;
	char *temp;

	year = ft_strchr(str, '\n');
	*year-- = '\0';
	while (ft_isdigit(*year))
		year--;
	temp = year;
	while (!ft_isdigit(*temp))
		temp--;
	*(temp - 8) = '\0';
	str += 4;
	ft_putstr(str);
	ft_putstr(" ");
	ft_putstr(year);
	ft_putstr(" ");
}

void	normal_trim(char *str)
{
	str[3] = '\0';
	ft_strclr(str);
	str += 4;
	str[12] = ' ';
	str[13] = ' ';
	ft_strclr(str + 13);
	ft_putstr(str);
}

void	ft_puttime(const time_t *stat_time)
{
	time_t	present_time;
	time_t	diff_time;
	char	*str;

	malcheck(str = ctime(stat_time));
	time(&present_time);
	diff_time = present_time - *stat_time;
	if (diff_time > 15552000 || diff_time < -3600)
		year_trim(str);
	else
		normal_trim(str);
}

char	*gidname(gid_t gid)
{
	struct group *grp;

	grp = getgrgid(gid);
	return (grp->gr_name);
}

void	puttotal(t_file *files)
{
	int total;
	int i;

	total = 0;
	i = 0;
	while (i < files->len)
	{
		total += (int)files[i].stats.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}
