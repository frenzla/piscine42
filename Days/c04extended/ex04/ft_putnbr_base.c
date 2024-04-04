/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:25:39 by alarose           #+#    #+#             */
/*   Updated: 2024/03/21 15:32:24 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	error(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (1);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == '+' || str[i] == '-')
				return (1);
			j = 1;
			while (str[i + j] != '\0')
			{
				if (str[i] == str[i + j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	base_len(char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
		count++;
	return (count);
}

void	change_base(int nbr, char *base, int base_length)
{
	long	nbr_long;

	nbr_long = nbr;
	if (nbr_long < 0)
	{
		nbr_long *= -1;
		ft_putchar('-');
	}
	if (nbr_long >= base_length)
		change_base((nbr_long / base_length), base, base_length);
	ft_putchar(base[nbr_long % base_length]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	if (error(base))
		return ;
	else
	{
		base_length = base_len(base);
		change_base(nbr, base, base_length);
	}
}
/*
void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}
*/
