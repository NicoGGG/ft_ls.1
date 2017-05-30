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
void	ft_ls(char **av, t_flag *option);

void	init_option(t_flag *option)
{
	option->l = 0;
	option->rec = 0;
	option->a = 0;
	option->r = 0;
	option->t = 0;
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

	if (ac == 1)
		return (simple_ls());
	option = malloc(sizeof(t_flag));
	init_option(option);
	parse_option(av + 1, option);
	ft_ls(av + 1, option);
	return (0);
}
