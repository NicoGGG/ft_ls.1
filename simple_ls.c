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

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

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
