/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:22:20 by daavril           #+#    #+#             */
/*   Updated: 2024/03/24 06:22:17 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_display(char tab[], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		j = 0;
		while (j < row)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	row;
	int	col;

	row = 4;
	col = 4;
	a = ft_display(argv[1], row, col);
	b = ft_display(argv[2], row, col);
	c = ft_display(argv[3], row, col);
	d = ft_display(argv[4], row, col);
	/*char	tab[2][4];

	tab[0][0] = '0';
	tab[0][1] = '0';
	tab[0][2] = '0';
	tab[0][3] = '0';
	tab[1][0] = '1';
        tab[1][1] = '1';
        tab[1][2] = '1';
        tab[1][3] = '1';
	ft_display(tab, 4, 2);*/
	
}
