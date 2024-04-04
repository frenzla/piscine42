/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:02:44 by daavril           #+#    #+#             */
/*   Updated: 2024/03/24 03:17:30 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void    print_row()
{
	
}*/

char	*create_tab(int nb_arg, char *str)
{
	int side_len = nb_arg / 4 + 2;
	int     tab[6][6];
	int     i;
	int     j;
	int     k;

	i = 0;
	j = 1;
	k = 0;
	while (j < side_len - 1)
	{
		tab[i][j] = str[k] - '0';
		j++;
		k += 2;
	}
	i = side_len;
	j = 1;
	while (j < side_len -1)
	{
		tab[i][j] = str[k] - '0';
	}
}

int	main(void)
{
	int	nb_arg;
	char	*str;

	nb_arg = 16;
	str = "4 2 3 6 8 7 9 4 5 1 2 6 4 5 9 8";
	create_tab(nb_arg, str);
	write(1, create_tab(nb_arg, str), 50);
}
