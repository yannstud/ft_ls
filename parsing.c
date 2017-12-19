/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 00:48:33 by ysalaun           #+#    #+#             */
/*   Updated: 2017/12/19 04:06:15 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR*	parsing(char **argv, char **path)
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
			*path = argv[i];
			return (rep);
		}
	}
	return (NULL);
}

char		*get_args(char **argv, char *args)
{
	int		i;
	int		j;
	int		k;
	t_lsarg	lsarg;
	
	i = 0;
	k = 0;
	// lsarg = (lsarg *)ft_memalloc(sizeof(lsarg));
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
		if (args[i] == 'a')
			lsarg.a = 1;
		else if (args[i] == 'R')
			lsarg.R = 1;
		else if (args[i] == 'l')
			lsarg.l = 1;
		else if (args[i] == 't')
			lsarg.t = 1;
		else if (args[i] == '-')
			lsarg.T = 1;
		else if (args[i] == 'r')
			lsarg.r = 1;
		else
		{
			ft_putstr("wrong argument\n");
			return NULL;
		}
		i++;
	}
	return (args);
}

void		get_names(t_list **alst, DIR* rep, char *path)
{
	struct	dirent	*filetoread;
	struct	stat	sb = {};
	
	while ((filetoread = readdir(rep)) != NULL)
	{
		if ((char)filetoread->d_name[0] != '.')
		{
			lstat(path = getpath(path, filetoread->d_name), &sb); // leaks
			ft_lstadd_front(alst, ft_lstnew((void *)node(filetoread->d_name, 
				type_of_file(sb), rights(&sb), path), sizeof(t_arg)));
			// printf("%u\n",sb.st_gid);
		}
	}
}

char		*aff_folder(t_list *list)
{
	char	*str;
	char	cyan[8] = "\x1b[36m";
	char	white[7] = "\x1b[0m";
	int		j;
	int		i;
	
	if ((ft_strcmp(((t_arg *)list->content)->type, "répertoire") == 0))
	{
		str = ft_memalloc(15 + ft_strlen(((t_arg *)list->content)->name));
		i = -1;
		while (cyan[++i])
			str[i] = cyan[i];
		j = 0;
		while (((t_arg *)list->content)->name[j])
			str[i++] = ((t_arg *)list->content)->name[j++];
		j = 0;
		while (white[j])
			str[i++] = white[j++];
		return (str);
	}
	else 
		return (NULL);
}

void		aff_list(t_list **alst)
{
	t_list	*list = NULL;

	list = *alst;
	while (list)
	{
			if ((ft_strcmp(((t_arg *)list->content)->type, "répertoire") == 0))
			{
				ft_putstr(CYAN);
				ft_putstr(((t_arg *)list->content)->name);
				ft_putstr(WHITE);
			}
			else if ((ft_strcmp(&((t_arg *)list->content)->rights[8], "x") == 0))
			{
				ft_putstr(RED);
				ft_putstr(((t_arg *)list->content)->name);
				ft_putstr(WHITE);
			}
			else 
				ft_putstr(((t_arg *)list->content)->name);
		if (list->next)
			ft_putchar('\t');
		list = list->next;
	}
	ft_putchar('\n');
}


char		*getpath(char *path, char *list)
{
	char	*slash;
	char	*tmp;

	slash = "/";
	tmp = ft_strjoin(path, slash);
	path = ft_strjoin(tmp, list);
	free(tmp);
	return (path);
}

void	recursive(t_list **alst, struct stat sb, char *path)
{
	t_list	*list;
	t_list	*list2;
	DIR*	rep;
	char	*str;
	
	list2 = NULL;
	list = *alst;
	while (list)
	{
		if (ft_strcmp((((t_arg *)list->content)->type), "répertoire") == 0)
		{
			str = getpath(path, (((t_arg *)list->content)->name));
			if ((rep = opendir(str)) != NULL)
			{
				// affichage
				ft_putchar('\n');
				ft_putstr(str);
				ft_putchar('\n');
				get_names(&list2, rep, str);
				closedir(rep);
				aff_list(&list2);
				recursive(&list2, sb, str);
				list2 = NULL;
			}
		}
		list = list->next;
	}
}

// char	*padding(t_list **alst)
// {
// 	struct winsize ws;
// 	t_list *list;
// 	int i;
// 	int count;
// 	int col;

// 	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
// 	list = *alst;
// 	while (list)
// 	{
// 		i = 0;
// 		while (((t_arg *)list->content)->name[i])
// 			i++;
// 		i++;
// 		count += i;
// 		list = list->next;
// 	}
// 	list = *alst;

// 		col = count / ws.ws_col;
// 		printf("%s ", ((t_arg *)list->content)->name)
// 		while (col)
// 		{
// 			list = list->next;
// 			col--;
// 		}
// 	}
// }