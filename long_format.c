/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:09:14 by nguelfi           #+#    #+#             */
/*   Updated: 2017/06/12 18:09:16 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	init_long_struct(t_long *long_struct)
{
	long_struct->link = 0;
	long_struct->size = 0;
	long_struct->day = 0;
	long_struct->link_pad = 0;
	long_struct->size_pad = 0;
}

void	padding_size(char *names, t_long *long_struct)
{
	struct stat		filestat;
	int				dec;
	int				tmp;

	stat(names, &filestat);
	tmp = filestat.st_size;
	dec = 2;
	while (tmp /= 10)
		dec++;
	if (dec > long_struct->size_pad)
		long_struct->size_pad = dec;
}

void	padding_long(char *names, t_long *long_struct)
{
	struct stat		filestat;
	int				dec;
	int				tmp;

	stat(names, &filestat);
	tmp = filestat.st_nlink;
	dec = 2;
	while (tmp /= 10)
		dec++;
	if (dec > long_struct->link_pad)
		long_struct->link_pad = dec;
}

void	build_long(char *names, t_long *long_struct)
{
	build_rights(names, long_struct);
	build_links(names, long_struct);
	build_id(names, long_struct);
//	build_size(names, long_struct);
//	build_time(names, long_struct);
}

void	print_long(char *names, t_long *long_struct)
{
//	t_long	*long_struct;

//	long_struct = malloc(sizeof(t_long));
//	init_long_struct(long_struct);
	build_long(names, long_struct);
	printf("%s ", long_struct->right);
//	printf("LINK PAD = %d SIZE PAD = %d ", long_struct->link_pad, long_struct->size_pad);
	printf("%*d ", long_struct->link_pad, long_struct->link);
	printf("%s ", long_struct->uid);
	printf("%5s ", long_struct->group);
}
