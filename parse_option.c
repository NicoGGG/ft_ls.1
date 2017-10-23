/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:20:48 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/30 16:45:52 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	parse_option(char **av, t_flag *option)
{
	int j;

	while (*av && (*av)[0] == '-')
	{
		j = 0;
		while ((*av)[++j])
		{
			if ((*av)[j] == 'l')
				option->l = 1;
			else if ((*av)[j] == 'R')
				option->rec = 1;
			else if ((*av)[j] == 'a')
				option->a = 1;
			else if ((*av)[j] == 'r')
				option->r = 1;
			else if ((*av)[j] == 't')
				option->t = 1;
			else
			{
				printf("%c unknown option\n", (*av)[j]);
				exit(1);
			}
		}
		av++;
	}
}

void	parse_args(char **av, t_flag *option)
{
	while (*av && (*av)[0] == '-')
		av++;
	while (*av++)
		option->args += 1;
}
