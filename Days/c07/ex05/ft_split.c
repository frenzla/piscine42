/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:45:20 by alarose           #+#    #+#             */
/*   Updated: 2024/04/02 12:31:38 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_elements(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (is_in_charset(str[i], charset))
		i++;
	while (str[i])
	{
		if (!(is_in_charset(str[i], charset))
			&& ((is_in_charset(str[i + 1], charset))
				|| str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	elem_len(char *str, int i, char *charset)
{
	int	len;

	len = 0;
	while (!(is_in_charset(str[i], charset)) && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

int	insert_w(char *str, int i, char *table, char *charset)
{
	int	j;

	j = 0;
	while (j < elem_len(str, i, charset))
	{
		table[j] = str[i + j];
		j++;
	}
	table[j] = '\0';
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**table;
	int		j;
	int		i;

	j = 0;
	i = 0;
	table = malloc(sizeof(char *) * (count_elements(str, charset) + 1));
	if (table == NULL)
		return (NULL);
	while (j < count_elements(str, charset))
	{
		if (is_in_charset(str[i], charset))
			i++;
		else
		{
			table[j] = malloc(sizeof(char) * (elem_len(str, i, charset) + 1));
			if (table == NULL)
				return (NULL);
			insert_w(str, i, table[j], charset);
			i += elem_len(str, i, charset);
			j++;
		}
	}
	table[j] = NULL;
	return (table);
}
/*
int	main(void)
{
	int	i;
	char **table;

	i = 0;
	char str[] = "Hello! My name is Alex!";
	char charset[] = "! ";
	table = ft_split (str, charset);
	while (i < count_elements(str, charset) + 1)
	{
		printf("%s\n", table[i]);
		free(table[i]);
		i++;
	}
	free(table);
	return (0);
}
*/
