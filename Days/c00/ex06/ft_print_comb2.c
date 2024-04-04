/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:41:45 by alarose           #+#    #+#             */
/*   Updated: 2024/03/14 11:51:16 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_comb(int nb)
{
	int	a;
	int	b;

	a = nb % 10;
	b = nb / 10;
	if (nb < 10)
	{
		ft_putchar('0');
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putchar(b + '0');
		ft_putchar(a + '0');
	}
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	while (nb1 < 99)
	{
		nb2 = nb1 + 1;
		while (nb2 < 100)
		{
			ft_comb(nb1);
			ft_putchar(' ');
			ft_comb(nb2);
			if (nb1 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			nb2++;
		}
		nb1++;
	}
}
