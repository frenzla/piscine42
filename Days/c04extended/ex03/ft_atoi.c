/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:57:50 by alarose           #+#    #+#             */
/*   Updated: 2024/03/25 11:15:24 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	calc_num(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 1;
	while (is_num(*(--str)))
	{
		nbr += (*str - '0') * i;
		i *= 10;
	}
	return (nbr);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign_counter;

	while (*str && is_space(*str))
		str++;
	sign_counter = 0;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign_counter++;
		str++;
	}
	while (*str && is_num(*str))
	{
		str++;
	}
	nbr = calc_num(str);
	if (sign_counter % 2 == 1)
		nbr = -nbr;
	return (nbr);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("qhb4idhnlyrjv8h2k6r8oinz"));
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}
*/
