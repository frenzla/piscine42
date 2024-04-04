/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:31:51 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/30 15:53:07 by cfabas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	clean_arrii(int **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
}

void	clean_arri(int *arr)
{
	free(arr);
}

void	clean_arrcc(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
}

void	clean_arrc(char *arr)
{
	free(arr);
}
