/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:18:30 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/30 18:34:52 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	parse_option(char **av, t_flag *option);
int		simple_ls(void);
//void	ft_ls(char **av, t_flag *option, t_long *long_struct);

void	init_option(t_flag *option)
{
	option->l = 0;
	option->rec = 0;
	option->a = 0;
	option->r = 0;
	option->t = 0;
	option->args = 0;

}

void	print_option(t_flag *option)
{
	printf("l = %d, rec = %d, a = %d\nr = %d, t = %d, args = %d\n", option->l, option->rec, option->a, option->r, option->t, option->args);

}
/* AU 30/05/17 :
 * - arranger le parsing des arguments pour savoir si il y a
 * un ou plusieurs dossier a ls (comportement different de -R)
 * - ameliorer la fonction d'affichage pour la rendre universelle
 * a toutes les options et toutes les combinations d'arg
 */

int		main(int ac, char **av)
{
	t_flag	*option;
	t_long	*long_struct;
	int 	args;

	if (ac == 1)
		return (simple_ls());
	option = malloc(sizeof(t_flag));
	long_struct = malloc(sizeof(t_long));
	init_option(option);
	init_long_struct(long_struct);
	parse_option(av + 1, option);
	parse_args(av + 1, option);
	print_option(option);
	av++;
	while (*av && **av == '-')
		av++;
	ft_ls(av, option, long_struct);
	return (0);
}
