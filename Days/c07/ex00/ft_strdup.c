/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:55 by alarose           #+#    #+#             */
/*   Updated: 2024/03/27 17:25:14 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int	count;

	count = 0;
	while (*src++)
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}
/*
int	main(void)
{
	char str[] = "hello my man";

	printf("%s\n", ft_strdup(str));

	return (0);
}
*/
