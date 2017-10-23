/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:46:20 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/30 17:26:02 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	print_dir(char *dname)
{
	struct stat	filestat;

	stat(dname, &filestat);
	if (S_ISDIR(filestat.st_mode))
		printf(ANSI_COLOR_CYAN	"%s"	ANSI_COLOR_RESET	"\n", dname);
	else if (filestat.st_mode & S_IXUSR
			|| filestat.st_mode & S_IXGRP
			|| filestat.st_mode & S_IXOTH)
		printf(ANSI_COLOR_RED	"%s"	ANSI_COLOR_RESET	"\n", dname);
	else
		printf("%s\n", dname);
}

int		simple_ls(void)
{
	void			*dirp;
	struct dirent	*dp;

	dirp = opendir(".");
	while ((dp = readdir(dirp)))
	{
		if (dp->d_name[0] != '.')
			print_dir(dp->d_name);
	}
	return (0);
}

char	*next_dir(char **names)
{
	static char		*next_dir = NULL;
	void			*dirp;
	struct dirent	*dp;
	struct stat		filestat;

	if (next_dir == NULL)
		next_dir = *names;
	while (strcmp(*names, next_dir))
		names++;
	while ((*names))
	{
		stat(*names, &filestat);
		if (S_ISDIR(filestat.st_mode) && strcmp(*names, ".") && strcmp(*names, ".."))
		{
			next_dir = *names;
			return (next_dir);
		}
		names++;
	}
	next_dir = NULL;
	return (next_dir);
}

int		ls_noargs(t_flag *option, char *curr_dir)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				count;

	struct stat 	filestat;

	if (curr_dir == NULL)
		return (1);
	dirp = opendir(curr_dir);
	while ((dp = readdir(dirp)))
		count++;
	names = in_folder(count, curr_dir);
	names = to_display(option, names);
	sort_names(option, names);
	while (*names)
	{
		print_dir(*names);
		names++;
	}
	if (option->rec == 1)
		return (ls_noargs(option, next_dir(names)));
	return (1);
}

void	option_ls(t_flag *option, char *curr_dir, t_long *long_struct)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				count;

	dirp = opendir(curr_dir);
	while ((dp = readdir(dirp)))
	{
		padding_long(dp->d_name, long_struct);
		padding_size(dp->d_name, long_struct);
		count++;
	}
	names = in_folder(count, curr_dir);
	names = to_display(option, names);
	sort_names(option, names);
	while (*names)
	{
		if (option->l == 1)
			print_long(*names, long_struct);
		print_dir(*names);
		names++;
	}
}
