/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:58:08 by alarose           #+#    #+#             */
/*   Updated: 2024/03/18 21:13:48 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/
int	is_alphanumeric(char c)
{
	if (c > 47 && c < 58)
		return (1);
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	if (str[0] > 96 && str[0] < 123)
		str[0] -= 32;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(is_alphanumeric(str[i])))
		{
			if (str[i + 1] > 96 && str[i + 1] < 123)
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char str[] = "salut, coMMent tU vAs ? 42Mots quarantE-DEux; cinquante+et+un";
	char *result;

	result = ft_strcapitalize(str);
	printf("\n");
	printf("%s\n", str);

	return (0);
}
*/
