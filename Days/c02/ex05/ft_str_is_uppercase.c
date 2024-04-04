/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:10:13 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 11:06:36 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
		if (*str > 64 && *str < 91)
			str++;
	else
		return (0);
	return (1);
}
/*
int	main(void)
{
	char str[] = "HELLo";
	int	result;
	result = ft_str_is_uppercase(str);
	printf("Result: %d\n", result);
	return (0);
}
*/
