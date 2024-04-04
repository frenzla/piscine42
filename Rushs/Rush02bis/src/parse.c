/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:51:20 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/31 17:20:03 by mpoma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	parse(char *str, int *index)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r'))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*index = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sgn_and_set;
	int	i;

	res = 0;
	i = 0;
	sgn_and_set = parse(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sgn_and_set);
}

int	argparse(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return (ft_atoi(arg));
}

int	**parray(char *str)
{
	int	**ret;
	int	len;
	int	i;

	len = ft_strlen(str);
	ret = malloc(sizeof(int *) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = (int *)malloc(sizeof(int) * 2);
		if (ret[i] == NULL)
			return (NULL);
		ret[i][0] = str[i] - '0';
		ret[i][1] = len - 1 - i;
		i++;
	}
	return (ret);
}

int	**rev_parray(char *str)
{
	int	**ret;
	int	len;
	int	i;
	int	rev_i;

	len = ft_strlen(str);
	ret = malloc(sizeof(int *) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rev_i = len - i - 1;
		ret[rev_i] = (int *)malloc(sizeof(int) * 2);
		if (ret[rev_i] == NULL)
			return (NULL);
		ret[rev_i][0] = str[i] - '0';
		ret[rev_i][1] = len - 1 - i;
		i++;
	}
	return (ret);
}
