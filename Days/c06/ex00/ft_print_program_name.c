/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:03 by alarose           #+#    #+#             */
/*   Updated: 2024/03/25 15:34:30 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	argc_use;

	argc_use = argc - argc;
	i = 0;
	while (argv[argc_use][i] != '\0')
	{
		write(1, &argv[argc_use][i], 1);
		i++;
	}
	return (0);
}
