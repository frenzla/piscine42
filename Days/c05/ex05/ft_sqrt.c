/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:06:25 by alarose           #+#    #+#             */
/*   Updated: 2024/03/26 09:59:14 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (nb / i > i)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_sqrt(144));
	return (0);
}
*/
