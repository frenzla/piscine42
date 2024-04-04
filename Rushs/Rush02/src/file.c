/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:52:46 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/31 16:55:40 by cfabas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	linecount(char *argv)
{
	int		fd;
	char	c;
	int		count;

	fd = open(argv, O_RDONLY);
	count = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	*lineslens(char *argv)
{
	int		i;
	int		fd;
	char	c;
	int		count;
	int		*ret;

	i = 0;
	fd = open(argv, O_RDONLY);
	count = 0;
	ret = arri(linecount(argv));
	while (read(fd, &c, 1))
	{
		if (c != '\n')
		{
			count++;
		}
		else
		{
			ret[i++] = count;
			count = 0;
		}
	}
	close(fd);
	return (ret);
}

char	**setup(char *argv)
{
	char	**ret;
	int		i;
	int		*ll;

	i = 0;
	ret = arrcc(linecount(argv) * 2);
	ll = lineslens(argv);
	while (i < linecount(argv))
	{
		ret[i * 2] = arrc(ll[i] + 1);
		i++;
	}
	return (ret);
}

char	**populate(char *argv)
{
	char	**ret;
	char	c;
	int		fd;
	int		i;
	int		j;

	ret = setup(argv);
	fd = open(argv, O_RDONLY);
	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n')
			ret[i][j++] = c;
		else
		{
			ret[i][j] = '\0';
			j = 0;
			i += 2;
		}
	}
	close(fd);
	return (ret);
}
