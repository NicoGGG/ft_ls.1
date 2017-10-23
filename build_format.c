/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:14:54 by nguelfi           #+#    #+#             */
/*   Updated: 2017/06/12 18:14:55 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
/*
build_rights(names, long_struct);
	build_links(names, long_struct);
	build_id(names, long_struct);
	build_size(names, long_struct);
	build_time(names, long_struct);
*/

void	build_rights(char *names, t_long *long_struct)
{
	struct stat		filestat;

	long_struct->right[0] = 48;
	stat(names, &filestat);
	(S_ISDIR(filestat.st_mode) ? (long_struct->right[0] = 'd') : (long_struct->right[0] = '-'));
	((filestat.st_mode & S_IRUSR) ? (long_struct->right[1] = 'r') : (long_struct->right[1] = '-'));
	((filestat.st_mode & S_IWUSR) ? (long_struct->right[2] = 'w') : (long_struct->right[2] = '-'));
	((filestat.st_mode & S_IXUSR) ? (long_struct->right[3] = 'x') : (long_struct->right[3] = '-'));
	((filestat.st_mode & S_IRGRP) ? (long_struct->right[4] = 'r') : (long_struct->right[4] = '-'));
	((filestat.st_mode & S_IWGRP) ? (long_struct->right[5] = 'w') : (long_struct->right[5] = '-'));
	((filestat.st_mode & S_IXGRP) ? (long_struct->right[6] = 'x') : (long_struct->right[6] = '-'));
	((filestat.st_mode & S_IROTH) ? (long_struct->right[7] = 'r') : (long_struct->right[7] = '-'));
	((filestat.st_mode & S_IWOTH) ? (long_struct->right[8] = 'w') : (long_struct->right[8] = '-'));
	((filestat.st_mode & S_IXOTH) ? (long_struct->right[9] = 'x') : (long_struct->right[9] = '-'));
	long_struct->right[10] = 0;
}

void	build_links(char *names, t_long *long_struct)
{
	struct stat		filestat;
	int				dec;
	int				tmp;

	long_struct->link = filestat.st_nlink;
/*	dec = 1;
	tmp = long_struct->link;
	while (tmp /= 10)
		dec++;
	if (dec > long_struct->link_pad)
		long_struct->link_pad = dec;
*/
}

void	build_id(char *names, t_long *long_struct)
{
	struct stat		filestat;
	struct passwd	*tmp;
	struct group	*tmp2;
	int				uid;

	uid = filestat.st_uid;
	tmp = getpwuid(uid);
	long_struct->uid = strdup(tmp->pw_name);
	uid = filestat.st_gid;
	tmp2 = getgrgid(uid);
	long_struct->group = strdup(tmp2->gr_name);
}