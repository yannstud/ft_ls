/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_rights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:02:55 by ysalaun           #+#    #+#             */
/*   Updated: 2017/12/16 22:53:51 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*rights(struct stat *sb)
{
	const char		chars[] = "rwxrwxrwx@";
	int				i;
	char			*buf;

	buf = ft_strnew(9);
	i = -1;
	while (++i < 9)
		buf[i] = (sb->st_mode & (1 << (8-i))) ? chars[i] : '-';
	buf[9] = '\0';
	return (buf);
}

char			*type_of_file(struct stat sb)
{
	char		*type;
	
	if ((sb.st_mode & S_IFMT) == S_IFBLK)
		type = ft_strdup("peripherique de bloc");
	else if ((sb.st_mode & S_IFMT) == S_IFCHR)
		type = ft_strdup("périphérique de caractère");
	else if ((sb.st_mode & S_IFMT) == S_IFDIR)
		type = ft_strdup("répertoire");
	else if ((sb.st_mode & S_IFMT) == S_IFIFO)
		type = ft_strdup("FIFO/tube");
	else if ((sb.st_mode & S_IFMT) == S_IFLNK)
		type = ft_strdup("lien symbolique");
	else if ((sb.st_mode & S_IFMT) == S_IFREG)
		type = ft_strdup("fichier ordinaire");
	else if ((sb.st_mode & S_IFMT) == S_IFSOCK)
		type = ft_strdup("socket");
	else
		type = ft_strdup("inconnu");
	return (type);
}
