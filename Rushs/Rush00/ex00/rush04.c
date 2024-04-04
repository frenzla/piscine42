/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:48:46 by alarose           #+#    #+#             */
/*   Updated: 2024/03/17 15:36:03 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char i);

void	check_case(c_x, c_y, x, y)
{
	if ((c_x == 1 && c_y == 1) || ((c_x == x && c_y == y) && y > 1 && x > 1))
	{
		ft_putchar('A');
	}
	else if ((c_x == 1 && c_y == y) || (c_x == x && c_y == 1))
		ft_putchar('C');
	else if (c_x == 1 || c_y == 1 || c_x == x || c_y == y)
		ft_putchar('B');
	else
		ft_putchar (' ');
}

void	rush(int x, int y)
{
	int	c_x;
	int	c_y;

	c_x = 1;
	c_y = 1;
	if (x > 0 && y > 0)
	{
		while (c_y <= y)
		{
			while (c_x <= x)
			{
				check_case(c_x, c_y, x, y);
				c_x++;
			}
			c_y++;
			c_x = 1;
			ft_putchar('\n');
		}
	}
}
/*
void	ft_putchar(char i);

x = largeur || Y = hauteur

void	first_row(int x, int y, int counter_x, int counter_y)
{
	if (counter_y == 1 && counter_x == 1)
	{
		ft_putchar('/');
		counter_x++;
	}
	while (counter_x < x)
	{
		ft_putchar('*');
		counter_x++;
	}
	if (counter_x == x && x > 1)
	{
		ft_putchar('\\');
	}
}

int	middle_rows(int x, int y, int counter_x, int counter_y)
{
	while (counter_y < y && y > 1)
	{
		while (counter_x < x + 1)
		{
			if (counter_x == 1 || counter_x == x)
			{
				ft_putchar('*');
				counter_x++;
			}
			else
			{
				ft_putchar(' ');
				counter_x++;
			}
		}
		counter_y++;
		counter_x = 1;
		ft_putchar('\n');
	}
	return (counter_y);
}

void	last_row(int x, int y, int counter_x, int counter_y)
{
	if (counter_y == y && counter_x == 1)
	{
		ft_putchar('\\');
		counter_x++;
	}
	while (counter_x < x && y > 1)
	{
		ft_putchar('*');
		counter_x++;
	}
	if (counter_x == x && x > 1 && y > 1)
		ft_putchar('/');
}

void	rush(int x, int y)
{
	int	counter_y;
	int	counter_x;

	if (x > 0 && y > 0)
	{
		counter_y = 1;
		counter_x = 1;
		first_row(x, y, counter_x, counter_y);
		ft_putchar('\n');
		counter_y++;
		counter_y = middle_rows(x, y, counter_x, counter_y);
		last_row(x, y, counter_x, counter_y);
	}
}
*/
