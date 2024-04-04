/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:10:13 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 10:26:26 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
		if (*str > 47 && *str < 58)
			str++;
	else
		return (0);
	return (1);
}
/*
int	main(void)
{
	char str[] = "1587";
	int	result;
	result = ft_str_is_numeric(str);
	printf("Result: %d\n", result);
	return (0);
}
*/
