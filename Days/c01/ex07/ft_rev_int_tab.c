/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:57:59 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 09:21:49 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/

void	ft_swap(int *a, int *b)
{
	int	swap_buff;

	swap_buff = *a;
	*a = *b;
	*b = swap_buff;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1 - i))
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}
/*
int	main(void)
{
	int numbers[] = {1, 3, 4, -5, 6, 7};
	int i = 0;

	while (i < 6)
	{
		printf("%d", numbers[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(numbers, 6);
	i = 0;
	while (i < 6)
	{
		printf("%d", numbers[i]);
		i++;
	}
	return (0);
}
*/
