/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:16:06 by alarose           #+#    #+#             */
/*   Updated: 2024/03/28 17:45:50 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	sign_counter = 0;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign_counter++;
		str++;
	}
	if (is_in_base(*str, base) != -1)
		nbr = convert(str, base);
	else
		return (0);
	if (sign_counter % 2 == 1)
		nbr = -nbr;
	return (nbr);
}
