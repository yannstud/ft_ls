/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 03:20:39 by ysalaun           #+#    #+#             */
/*   Updated: 2017/12/15 00:38:56 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*node(char *t1, char *t2, char *t3)
{
	t_arg 		*tata;

	tata = ft_memalloc(sizeof(t_arg));
	tata->name = ft_strdup(t1);
	tata->type = ft_strdup(t2);
	tata->rights = ft_strdup(t3);
	return (tata);

}

int main (int argc, char **argv)
{
	struct stat		sb = {};
	DIR* 			rep = NULL;
	t_list			*list = NULL;
	char *str;
	char *path = "../";

	str = NULL;
	(void)argc;
	if ((rep = parsing(argv)) == NULL)
		return (0);
	get_names(&list, rep, path);
	aff_list(&list);
	recursive(&list, sb, path);
}





















