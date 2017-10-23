/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:48:05 by nguelfi           #+#    #+#             */
/*   Updated: 2017/06/12 16:48:07 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	sort_time(char **names)
{
	struct stat	filestati;
	struct stat	filestatj;
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	while (names[i + 1])
	{
		j = i;
		while (names[++j])
		{
			stat(names[i], &filestati);
			stat(names[j], &filestatj);
			if (filestati.st_mtime < filestatj.st_mtime)
			{
				tmp = strdup(names[i]);
				free(names[i]);
				names[i] = strdup(names[j]);
				free(names[j]);
				names[j] = strdup(tmp);
			}
		}
		i++;
	}
}

void	sort_reverse(char **names)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (names[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = strdup(names[i]);
		free(names[i]);
		names[i] = strdup(names[j]);
		free(names[j]);
		names[j] = strdup(tmp);
		j--;
		i++;
	}
}

void	sort_names(t_flag *option, char **names)
{
	if (option->t == 1)
		sort_time(names);
	if (option->r == 1)
		sort_reverse(names);
}
