/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:29:00 by alarose           #+#    #+#             */
/*   Updated: 2024/03/15 13:22:40 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab [i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}
/*
int	main(void)
{
	int	numbers[] = {6, 3, 1, 7, 5, 2, 4};
	int	i = 0;

	while (i < 7)
	{
		numbers[i] += '0';
		write(1, &numbers[i], 1);
		i++;
	}
	ft_sort_int_tab(numbers, 7);
	write(1, "\n", 1);
	i = 0;
	while (i < 7)
	{
		write(1, &numbers[i], 1);
		i++;
	}
	return (0);
}
*/
