/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:05:13 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:38:35 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int argc, char **argv)
{
	unsigned char	flags;
	int				ret;

	flags = ft_flag(argc, argv);
	argv++;
	argc--;
	while (*argv && (ret = is_flag(*argv)) != -2)
	{
		argc--;
		argv++;
		if (ret == -1)
			break ;
	}
	ls_exec(argc, argv, flags);
}
