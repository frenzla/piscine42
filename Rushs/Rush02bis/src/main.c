/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:50:01 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/31 17:10:32 by cfabas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

void	work(int argc, char **argv)
{
	int		**digits;
	char	**dict;

	if (argc == 2)
	{
		digits = rev_parray(argv[1]);
		dict = populate("../numbers.dict");
		split_dict_strings(dict, linecount("../numbers.dict"));
		search_n_write(digits, dict, argv);
	}
	else if (argc == 3)
	{
		digits = rev_parray(argv[1]);
		dict = populate(argv[2]);
		split_dict_strings(dict, linecount(argv[2]));
		search_n_write(digits, dict, argv);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(argparse(argv[1])))
		{
			ft_putstr("Error\n");
			return (-1);
		}
		work(2, argv);
	}
	else if (argc == 3)
	{
		if (!(argparse(argv[1])))
		{
			ft_putstr("Error\n");
			return (-1);
		}
		work(3, argv);
	}
	return (0);
}
