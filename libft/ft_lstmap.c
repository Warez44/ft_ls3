/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:46:06 by clingier          #+#    #+#             */
/*   Updated: 2018/11/05 08:45:20 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(t_list *lst)
{
	t_list *tmp;

	tmp = lst->next;
	if (tmp == NULL)
		free(lst);
	while (tmp)
	{
		free(lst);
		lst = tmp;
		tmp = tmp->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *fresh_cur;

	if (!lst || !f)
		return (NULL);
	fresh_cur = f(lst);
	fresh = fresh_cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(fresh_cur->next = f(lst)))
		{
			ft_free(fresh);
			return (NULL);
		}
		fresh_cur = fresh_cur->next;
	}
	return (fresh);
}
