/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:48:33 by alarose           #+#    #+#             */
/*   Updated: 2024/03/14 18:08:58 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	p_div;
	int	p_mod;
	
	div = &p_div;
	mod = &p_mod;

	a = 42;
	b = 7;
	ft_div_mod(a, b, div, mod);
	printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, *div,*mod);
	return (0);
}
*/
