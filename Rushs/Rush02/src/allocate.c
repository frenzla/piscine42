/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:42:26 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/31 16:35:14 by mpoma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**arrii(int len)
{
	int	**ret;

	ret = malloc(sizeof(int *) * len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

int	*arri(int len)
{
	int	*ret;

	ret = malloc(sizeof(int) * len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	**arrcc(int len)
{
	char	**ret;

	ret = malloc(sizeof(char *) * len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*arrc(int len)
{
	char	*ret;

	ret = malloc(sizeof(char) * len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
