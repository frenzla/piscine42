/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:18:40 by daavril           #+#    #+#             */
/*   Updated: 2024/03/24 07:45:07 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct	test
{
	char	tab[4];
};
char	put_line(char **row)
{
	struct	test row1 = {row[4]}; 
	write(1, tab, 1);
}

int	main(voi)
{
	char	tab[4];

	tab[] = "0123";
	put_line(tab);
}
