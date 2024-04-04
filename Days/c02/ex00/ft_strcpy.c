/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:38:41 by alarose           #+#    #+#             */
/*   Updated: 2024/03/18 14:33:00 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	char	*head;

	head = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (head);
}
/*
int	main(void)
{
	char src[] = "Hello my friend!";
	char dest[100];
	char	*result;
	result = ft_strcpy(dest, src);
	printf("Result in dest: %s\n", result);

	return (0);
}
*/
