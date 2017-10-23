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
		if (option->a == 0)
		{
			if (*names[i] != '.')
				new[j++] = strdup(names[i]);
		}
		else
			new[j++] = strdup(names[i]);
		free(names[i]);
		i++;
	}
	new[j] = NULL;
	return (new);
}

char	**in_folder(int count, char *curr_dir)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				j;

	j = 0;
	names = malloc(sizeof(char *) * count + 1);
	dirp = opendir(curr_dir);
	while ((dp = readdir(dirp)))
		names[j++] = strdup(dp->d_name);
	names[j] = NULL;
	return (names);
}

int		ft_ls(char **av, t_flag *option, t_long *long_struct)
{
	char			**names;
	void			*dirp;
	struct dirent	*dp;
	int				count;
	char			*curr_dir;

	if (*av == NULL && option->args > 0)
		return (1);
	else if (option->args == 0)
		return (ls_noargs(option, "."));
	count = 0;
	if (option->args > 1)
	{
		printf("%s:\n", *av);
		curr_dir = *av;
	}
	else if (option->args == 1)
		curr_dir = *av;
	else
		curr_dir = strdup(".");
/*	dirp = opendir(curr_dir);
	while ((dp = readdir(dirp)))
		count++;
	names = in_folder(count, curr_dir);
	names = to_display(option, names);
//	sort_names(option, names);
	while (*names)
	{
		print_dir(*names);
		names++;
	}
*/
	option_ls(option, curr_dir, long_struct);
	if (*(av + 1))
		printf("\n");
	return (ft_ls(av + 1, option, long_struct));
}
