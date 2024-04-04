/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:04:00 by alarose           #+#    #+#             */
/*   Updated: 2024/03/28 11:16:10 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_len(char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
		count++;
	return (count);
}

int	convert(char *str, char *base)
{
	int	nbr;

	nbr = 0;
	while (is_in_base(*str, base) != -1)
	{
		nbr = nbr * base_len(base) + is_in_base(*str, base);
		str++;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	sign_counter;

	if (error(base))
		return (0);
	else
	{
		while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
			str++;
		sign_counter = 0;
		while (*str && (*str == '+' || *str == '-'))
		{
			if (*str == '-')
				sign_counter++;
			str++;
		}
		if (is_in_base(*str, base))
			nbr = convert(str, base);
		if (sign_counter % 2 == 1)
			nbr = -nbr;
	}
	return (nbr);
}
/*
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}
*/
