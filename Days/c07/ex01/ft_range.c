/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:41:48 by alarose           #+#    #+#             */
/*   Updated: 2024/03/27 17:27:20 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;
	int	range;

	range = max - min;
	i = 0;
	ptr = NULL;
	if (range <= 0)
		return (ptr);
	ptr = malloc(range * sizeof(int));
	if (!ptr)
		return (0);
	while (i < range)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	i;
	int	*ptr;

	max = 54;
	min = 30;

	i = 0;
	ptr = ft_range(min, max);
	while (i<(max-min))
	{
		printf("%d", ptr[i]);
		if (i != (max - min - 1))
			printf(" - ");
		i++;
	}
	free(ptr);
	return (0);
}
*/
