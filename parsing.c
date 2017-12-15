/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 00:48:33 by ysalaun           #+#    #+#             */
/*   Updated: 2017/12/15 18:21:50 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR*	parsing(char **argv)
{
	DIR*	rep;
	char	*args;
	int		i;

	args = ft_strnew(50);
	i = -1;
	if ((args = get_args(argv, args)) == NULL)
		return (NULL);
	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] != '-')
		{
			if ((rep = opendir(argv[i])) == NULL)
				return (NULL);
			return (rep);
		}
	}
	return (NULL);
}

char	*get_args(char **argv, char *args)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(argv[++i])
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][++j])
				args[k++] = argv[i][j];
		}
	}
	i = -1;
	while (args[++i])
	{
		if (args[i] == 'a' || args[i] == 'R' || args[i] == 'l' 
			|| args[i] == 't' || args[i] == '-' || args[i] == 'r')
			i++;
		else
		{
			ft_putstr("wrong argument\n");
			return NULL;
		}
	}
	return (args);
}

void	get_names(t_list **alst, DIR* rep, char *path)
{
	struct dirent	*filetoread;
	struct stat		sb = {};
	
	while ((filetoread = readdir(rep)) != NULL)
	{
		if (ft_strcmp(filetoread->d_name, ".") != 0 && 
			ft_strcmp(filetoread->d_name, "..") != 0 && 
			ft_strcmp(filetoread->d_name, ".DS_Store") != 0 && 
			ft_strcmp(filetoread->d_name, ".git") != 0)
		{
			lstat(getpath(path, filetoread->d_name), &sb);
			// printf("PATH ==> %s\n", path);
			// printf("d_name ==> %s\n",filetoread->d_name);
			// printf("RIGHTS ===> %s\n", rights(&sb));
				// printf("RIGHTS ===> %s\n", type_of_file(sb));
			ft_lstadd_front(alst, ft_lstnew((void *)node(filetoread->d_name, 
			type_of_file(sb), rights(&sb)), sizeof(t_arg)));
		}
	}
}

void	aff_list(t_list **alst)
{
	t_list		*list = NULL;

	list = *alst;
	while (list)
	{
		ft_putstr(((t_arg *)list->content)->name);
		if (list->next)
			ft_putchar('\t');
		list = list->next;
	}
	ft_putchar('\n');
}

char	*getpath(char *path, char *list)
{
	char *slash;

	slash = "/";
	path = ft_strjoin(path, slash);
	path = ft_strjoin(path, list);

	return (path);
}

void	recursive(t_list **alst, struct stat sb, char *path)
{
	t_list	*list;
	t_list	*list2;
	DIR*	rep;
	char *str;
	
	list2 = NULL;
	list = *alst;
	while (list)
	{
		// printf("%s ==> type\n", (((t_arg *)list->content)->rights));
		if (ft_strcmp((((t_arg *)list->content)->type), "répertoire") == 0)
		{
			str = getpath(path, (((t_arg *)list->content)->name));
			rep = opendir(str);
			ft_putchar('\n');
			ft_putstr(str);
			ft_putchar('\n');
			get_names(&list2, rep, str);
			aff_list(&list2);
			recursive(&list2, sb, str);
			list2 = NULL;
		}
		list = list->next;
	}
}