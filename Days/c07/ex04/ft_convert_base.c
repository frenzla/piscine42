/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:31:33 by alarose           #+#    #+#             */
/*   Updated: 2024/04/02 14:42:19 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	base_len(char *base);
int	convert(char *str, char *base);
int	ft_atoi_base(char *str, char *base);
int	is_in_base(char c, char *base);

int	base_is_wrong(char *str)
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

void	ft_putnbr_base(int nbr, char *base, char *result, int index)
{
	int		base_length;
	long	nbr_l;

	nbr_l = nbr;
	if (nbr_l < 0)
	{
		nbr_l = -nbr_l;
		result[0] = '-';
	}
	base_length = base_len(base);
	if (nbr_l >= base_length)
		ft_putnbr_base((nbr_l / base_length), base, result, index - 1);
	result[index] = base[nbr_l % base_length];
}

int	nbr_length(int nbr_dec, int base_length)
{
	int		count;
	long	nbr;

	nbr = nbr_dec;
	if (nbr < 0)
		nbr *= -1;
	count = 1;
	while (nbr >= base_length)
	{
		nbr /= base_length;
		count++;
	}
	return (count);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_dec;
	char	*result;
	int		base_length;
	int		nb_length;

	result = NULL;
	if (base_is_wrong(base_from) || base_is_wrong(base_to))
		return (NULL);
	nbr_dec = ft_atoi_base(nbr, base_from);
	base_length = base_len(base_to);
	nb_length = nbr_length(nbr_dec, base_length);
	if (nbr_dec < 0)
		nb_length++;
	result = malloc(sizeof(char) * (nb_length + 1));
	if (!result)
		return (NULL);
	ft_putnbr_base(nbr_dec, base_to, result, nb_length - 1);
	result[nb_length] = '\0';
	return (result);
}
/*
int	main(void)
{
	printf("42:%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}
*/
