/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 03:33:35 by ysalaun           #+#    #+#             */
/*   Updated: 2017/12/19 03:08:03 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "./libft/libft.h" 
# include <pwd.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <dirent.h>
# include <stdio.h>
#include <sys/ioctl.h>
#include <grp.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[0m"

// faire une liste chainee de chaque arguments
// verifier dans cette liste a chaque fois si il y as un autre dossier
// si oui balancer les noms dans le buffer
// ouvrir et recreer une new list de ce new dossier avec ce qu'il y a dedans
// balancer dans le buffer
// envoyer le buffer et le bzero a chaque fois qu'on a plus la place d'en mettre dedans
// recommencer 
//							IZI

typedef struct		s_arg
{
	char			*name;
	char			*type;
	char			*rights;
	char			*path;	
}					t_arg;

typedef struct		s_lsarg
{
	int				a;
	int				R;
	int				t;
	int				l;
	int				T;
	int				r;
}					t_lsarg;

char				folder_or_not(char *type);
char				*type_of_file(struct stat sb);
char				*rights(struct stat *sb);
void				name_of_file(DIR *file_to_read, struct dirent *file_name);
DIR*				parsing(char **argv, char **path);
t_arg				*node(char *t1, char *t2, char *t3, char *t4);
void				get_names(t_list **alst, DIR* rep, char *path);
char				*get_args(char **argv, char *args);
void				aff_list(t_list **alst);
void				recursive(t_list **alst, struct stat sb, char *path);
char				*getpath(char *path, char *list);
void				aff_coll(t_list **alst);

#endif