/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:38:00 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 11:39:05 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*removelast(char *src)
{
	char *temp;

	temp = ft_strrchr(src, '/');
	if (temp != NULL)
		ft_strclr(temp);
	else
	{
		free(src);
		src = NULL;
	}
	return (src);
}

void	freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*addlast(char *str, char *src)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	if (str == NULL)
		str = ft_strnew(0);
	else
	{
		temp = str;
		str = ft_strjoin(str, "/");
		free(temp);
	}
	ret = ft_strjoin(str, src);
	ft_strdel(&str);
	return (ret);
}

char	*path_simplifier(char *str)
{
	char	**tab;
	char	*res;
	int		i;

	malcheck(tab = ft_strsplit(str, '/'));
	res = NULL;
	i = 0;
	while (tab[i] && ft_strequ(tab[i], ".."))
		res = addlast(res, tab[i++]);
	while (tab[i])
	{
		if (!ft_strequ(tab[i], ".") && !ft_strequ(tab[i], ".."))
			res = addlast(res, tab[i]);
		if (ft_strequ(tab[i], ".."))
			res = removelast(res);
		i++;
	}
	freetab(tab);
	if (res == NULL)
		res = ft_strdup(".");
	return (res);
}
