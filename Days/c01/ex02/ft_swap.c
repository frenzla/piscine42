/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:36:03 by alarose           #+#    #+#             */
/*   Updated: 2024/03/14 17:45:02 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
*/

void	ft_swap(int *a, int *b)
{
	int	swap_buff;

	swap_buff = *a;
	*a = *b;
	*b = swap_buff;
}
/*
int	main(void)
{
	int	*p_a;
	int	*p_b;
	int	a;
	int	b;

	a = 33;
	b = 42;
	p_a = &a;
	p_b = &b;
	printf("Before swap: a = %d and b = %d\n", a, b);
	ft_swap(p_a, p_b);
	printf("After swap: a = %d and b = %d\n", a, b);
	return (0);
}
*/
