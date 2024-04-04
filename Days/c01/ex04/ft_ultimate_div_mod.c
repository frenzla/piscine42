/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:48:33 by alarose           #+#    #+#             */
/*   Updated: 2024/03/16 18:49:36 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	switch_buff;

	switch_buff = *a / *b;
	*b = *a % *b;
	*a = switch_buff;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	*p_a;
	int	*p_b;

	p_a = &a;
	p_b = &b;
	a = 42;
	b = 5;
	printf("a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(p_a, p_b);
	printf("a = %d, b = %d\n", a, b);
	return (0);
}
*/
