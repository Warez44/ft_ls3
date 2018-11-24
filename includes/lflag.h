/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:13:47 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 12:46:47 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFLAG_H
# define LFLAG_H

char	*uidname(uid_t uid);
void	getlenlnk(t_file *files);
void	getmaxstr(t_file *files);
void	getlensiz(t_file *files);
void	putstr_format(char *str, int format);
void	strpermission(mode_t mode);
char	*gidname(gid_t gid);
void	puttotal(t_file *files);
void	ft_puttime(const time_t *stat_time);
int		ft_minor(dev_t st_dev);
int		ft_major(dev_t st_dev);
void	putlink(t_file file);

#endif
