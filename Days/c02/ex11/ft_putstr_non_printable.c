/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:50:40 by alarose           #+#    #+#             */
/*   Updated: 2024/03/19 11:27:18 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
#include <unistd.h>

void	trans_hex(char c)
{
	int	last_hex_digit;
	int	first_hex_digit;

	first_hex_digit = (unsigned char)c / 16;
	last_hex_digit = (unsigned char)c % 16;
	if (first_hex_digit < 10)
		first_hex_digit = first_hex_digit + '0';
	else
		first_hex_digit = first_hex_digit + ('a' - 10);
	if (last_hex_digit < 10)
		last_hex_digit = last_hex_digit + '0';
	else
		last_hex_digit = last_hex_digit + ('a' - 10);
	write(1, "\\", 1);
	write(1, &first_hex_digit, 1);
	write(1, &last_hex_digit, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str > 31 && *str < 127))
		{
			trans_hex(*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
/*
void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "Coucou\ntu vas bien ?";
	ft_putstr("Coucou\\0atu vas bien ?:");
	ft_putstr_non_printable(c);
	char d[] = "\x81\xbe";
	ft_putstr("\n\\81\\be:");
	ft_putstr_non_printable(d);
}
*/
