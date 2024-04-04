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

char	*nb_to_char(int nb)
{
	char	*nbr;

	if (nb >= 10)
	{
		nbr = arrc(3);
		nbr[0] = nb / 10 + '0';
		nbr[1] = nb % 10 + '0';
		nbr[2] = '\0';
	}
	else
	{
		nbr = arrc(2);
		nbr[0] = nb + '0';
		nbr[1] = '\0';
	}
	return (nbr);
}

char	*powers_of_thousand(int nb)
{
	char	*ret;
	int		i;

	i = 1;
	ret = NULL;
	if (nb != 0)
	{
		ret = arrc(nb + 2);
		ret[0] = '1';
		while (i <= nb)
		{
			ret[i] = '0';
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

void	print_power_u(int i, int dict_len, char **dict)
{
	int	j;

	j = 0;
	while (j < dict_len)
	{
		if (i != 0 && ft_strcmp(powers_of_thousand(i), dict[j]) == 0)
		{
			ft_putstr(" ");
			ft_putstr(dict[j + 1]);
			ft_putstr(" ");
		}
		j++;
	}
}

void	print_unit(int **digits, int i, char **dict, char **argv)
{
	int		k;
	int		nb_to_search;
	char	*nb_in_char;
	int		dict_len;
	int		nb_elements;

	nb_elements = ft_strlen(argv[1]);
	dict_len = 2 * linecount(argv[2]);
	k = 0;
	if (((i + 1) < nb_elements) && digits[i + 1][0] == 1)
		nb_to_search = digits[i + 1][0] * 10 + digits[i][0];
	else
		nb_to_search = digits[i][0];
	nb_in_char = nb_to_char(nb_to_search);
	while (k < dict_len)
	{
		if (ft_strcmp(nb_in_char, dict[k]) == 0)
		{
			ft_putstr(dict[k + 1]);
			print_power_u(i, dict_len, dict);
		}
		k += 2;
	}
}

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

void	print_power_h(int i, int dict_len, char **dict)
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
			print_power_h(i, dict_len, dict);
		}
		k += 2;
	}
}

void	search_n_write(int **digits, char **dict, char **argv)
{
	int	i;
	int	nb_digits;
	int	and;

	i = 0;
	and = ft_strlen(argv[1]) - 1;
	nb_digits = ft_strlen(argv[1]) - 1;
	while (nb_digits >= 0)
	{
		if (nb_digits % 3 == 0)
			print_unit(digits, nb_digits, dict, argv);
		if (nb_digits % 3 == 1 && digits[nb_digits][0] != 1)
		{
			if (nb_digits == 1 && and != 1)
				ft_putstr(" and");
			print_dozens(digits, nb_digits, dict, argv);
		}
		if (nb_digits % 3 == 2)
			print_hundreds(digits, nb_digits, dict, argv);
		nb_digits--;
	}
}
