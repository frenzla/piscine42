/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:17:12 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 11:18:11 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
		if (*str > 31 && *str < 127)
			str++;
	else
		return (0);
	return (1);
}
/*
int	main(void)
{
	char str[] = "Hello 42!";
	int	result;
	result = ft_str_is_printable(str);
	printf("Result: %d\n", result);
	return (0);
}
*/
