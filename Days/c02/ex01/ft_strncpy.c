/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:06:36 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 12:12:44 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	int n = 25;
	char src[] = "Hello my friend";
	char dest[100];
	
	char *result;
	result = ft_strncpy(dest, src, n);
	int i = 0;
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
	return (0);
}
*/
