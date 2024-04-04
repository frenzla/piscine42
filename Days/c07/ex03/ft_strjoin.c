/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:10:04 by alarose           #+#    #+#             */
/*   Updated: 2024/04/02 17:39:33 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_empty_str(void)
{
	char	*str;

	str = malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		strs_len;
	int		i;

	if (size == 0)
		return (ft_empty_str());
	i = 0;
	strs_len = 0;
	while (i < size)
		strs_len += ft_strlen(strs[i++]);
	str = malloc((strs_len + ((size - 1) * ft_strlen(sep)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i < size)
			ft_strcat(str, sep);
	}
	return (str);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*ptr;

	printf("./ex03/output___said___this___is___a___success :\n");
	ptr = ft_strjoin(argc, argv, "_");
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
*/
