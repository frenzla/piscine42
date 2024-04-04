/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:33:00 by alarose           #+#    #+#             */
/*   Updated: 2024/03/31 17:11:37 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

void	print_dozens(int **digits, int i, char **dict, char **argv)
{
	int		k;
	char	*nb_in_char;
	int		dict_len;

	dict_len = 2 * linecount(argv[2]);
	k = 0;
	nb_in_char = nb_to_char(digits[i][0] * 10);
	while (k < dict_len)
	{
		if (ft_strcmp(nb_in_char, dict[k]) == 0)
		{
			ft_putstr(" ");
			ft_putstr(dict[k + 1]);
			ft_putstr("-");
		}
		k += 2;
	}
}

void	print_power_h(int dict_len, char **dict)
{
	int	j;

	j = 0;
	while (j < dict_len)
	{
		if (ft_strcmp(powers_of_thousand(2), dict[j]) == 0)
		{
			ft_putstr(" ");
			ft_putstr(dict[j + 1]);
		}
		j++;
	}
}

void	print_hundreds(int **digits, int i, char **dict, char **argv)
{
	int		k;
	char	*nb_in_char;
	int		dict_len;

	dict_len = 2 * linecount(argv[2]);
	k = 0;
	nb_in_char = nb_to_char(digits[i][0]);
	while (k < dict_len)
	{
		if (ft_strcmp(nb_in_char, dict[k]) == 0)
		{
			ft_putstr(dict[k + 1]);
			print_power_h(dict_len, dict);
		}
		k += 2;
	}
}