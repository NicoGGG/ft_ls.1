/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:38:12 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/30 18:32:39 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>

typedef struct	s_flag
{
	int	l;
	int rec;
	int a;
	int r;
	int t;
	int	args;
}				t_flag;

typedef struct  s_long
{
	char	right[11];
	int		link;
	int		link_pad;
	char	*uid;
	char	*group;
	int		size;
	int		size_pad;
	char	month[4];
	int		day;
	char	time[6];
}				t_long;

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36;1m"
# define ANSI_COLOR_RESET   "\x1b[0m"

void	parse_option(char **av, t_flag *option);
int		ft_ls(char **av, t_flag *option, t_long *long_struct);
void    print_dir(char *dname);
int		simple_ls(void);
char	**to_display(t_flag *option, char **names);
char	**in_folder(int count, char *curr_dir);
void	option_ls(t_flag *option, char *curr_dir, t_long *long_struct);
int		ls_noargs(t_flag *option, char *curr_dir);
void	parse_args(char **av, t_flag *option);
void	sort_names(t_flag *option, char **names);
void	init_long_struct(t_long *long_struct);
void	build_long(char *names, t_long *long_struct);
void	build_rights(char *names, t_long *long_struct);
void	build_links(char *names, t_long *long_struct);
void	build_id(char *names, t_long *long_struct);
void	padding_long(char *names, t_long *long_struct);
void	padding_size(char *names, t_long *long_struct);
void	print_long(char *names, t_long *long_struct);

#endif
