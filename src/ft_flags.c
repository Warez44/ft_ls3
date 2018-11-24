/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:58:38 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 11:45:26 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				ft_flagerror(char t)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(t, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
	exit(EXIT_FAILURE);
}

unsigned char		ft_case(char c, unsigned char flags)
{
	flags = (c == 'l') ? (flags | L_FLAG) : flags;
	flags = (c == 'a') ? (flags | A_FLAG) : flags;
	flags = (c == 'R') ? (flags | R_FLAG) : flags;
	flags = (c == 'r') ? (flags | R_MIN_FLAG) : flags;
	flags = (c == 't') ? (flags | T_FLAG) : flags;
	return (flags);
}

int					is_flag(char *str)
{
	if (ft_strequ(str, "-"))
		return (-2);
	if (ft_strnequ(str, "-", 1))
	{
		if (ft_strequ(str, "--"))
			return (-1);
		return (1);
	}
	return (-2);
}

int					not_valid_char(char c)
{
	char	buf[8];
	int		i;
	int		flag;

	buf[7] = '\0';
	i = 0;
	flag = 0;
	ft_strcpy(buf, "tRral1-");
	while (buf[i])
	{
		if (buf[i++] == c)
			return (0);
	}
	return (1);
}

unsigned char		ft_flag(int argc, char **argv)
{
	unsigned char	flags;
	int				i;
	int				j;

	i = 1;
	j = 1;
	flags = 0;
	while (i < argc && is_flag(argv[i]) != -2)
	{
		j = 1;
		if (ft_strnequ(argv[i], "--", 2) && !ft_strequ(argv[i], "--"))
			ft_flagerror(argv[i][0]);
		while (argv[i][j])
		{
			flags = ft_case(argv[i][j], flags);
			if (not_valid_char(argv[i][j]) || ft_strnequ(argv[i] + j, "--", 2))
				ft_flagerror(argv[i][j]);
			j++;
		}
		if (is_flag(argv[i++]) == -1)
			break ;
	}
	return (flags);
}
