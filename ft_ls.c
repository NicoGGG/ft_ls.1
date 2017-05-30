/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:44:59 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/30 18:32:37 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	**to_display(t_flag *option, char **names)
{
	char	**new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (names[i])
		i++;
	new = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (names[i])
	{
		if (*names[i] != '.')
			new[j++] = strdup(names[i]);
		free(names[i]);
		i++;
	}
	new[j] = NULL;
	return (new);
}

char	**in_folder(int count, char *av)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				j;

	j = 0;
	names = malloc(sizeof(char *) * count + 1);
	dirp = opendir(av);
	while ((dp = readdir(dirp)))
		names[j++] = strdup(dp->d_name);
	names[j] = NULL;
	return (names);
}

void	ft_ls(char **av, t_flag *option)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				count;
	
	if (*av == NULL)
		return ;
	if (*(av + 1))
		printf("%s:\n", *av);
	count = 0;
	while (*av && **av == '-')
		av++;
	dirp = opendir(*av);
	while ((dp = readdir(dirp)))
		count++;
	names = in_folder(count, *av);
	names = to_display(option, names);
//	sort_names(option, names);
	while (*names)
	{
		print_dir(*names);
		names++;
	}
	ft_ls(av + 1, option);
}
