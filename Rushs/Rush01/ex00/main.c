/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:16:45 by alarose           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:33 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	game_finished(int tab[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			if (tab[i][j] == 0)
			{
				 return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	height_is_valid(int tab[6][6], int row, int col, int height, int side_len)
{
	int	i;

	i = 1;
	while ( i < side_len - 1)
	{
		if(tab[row][i] == height || tab[i][col] == height)
			return (0);
		i++;
	}
    return (1);
}

int	check_c_from_up(int tab[6][6], int col, int side_len)
{
	int	visible_from_up;
	int	i;
	int	higher;

	i = 1;
	visible_from_up = 0;
	higher = 0;
	while (i < side_len - 1)
	{
		if (tab[i][col] > higher)
		{
			higher = tab[i][col];
			visible_from_up++;
		}
		i++;
	}
	return (visible_from_up);
}

int check_c_from_down(int tab[6][6], int col, int side_len)
{
	int	visible_from_down;
	int	i;
	int higher;

	i = side_len - 2;
	visible_from_down = 0;
	higher = 0;
	while (i > 0)
	{
		if (tab[i][col] > higher)
		{
			higher = tab[i][col];
			visible_from_down++;
		}
		i--;
	}
	return (visible_from_down);
}

int	column_full(int tab[6][6], int col, int side_len)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < side_len - 1)
	{
		if (tab[i][col] != 0)
			count++;
		i++;
	}
	if (count == side_len - 2)
		return (1);
	else
		return (0);
}

int	check_column(int tab[6][6], int col, int side_len)
{
	if (check_c_from_up(tab, col, side_len) != tab[0][col] || check_c_from_down(tab, col, side_len) != tab[side_len - 1][col])
		return (0);
	return (1);
}

int	check_r_from_left(int tab[6][6], int row, int side_len)
{
	int	visible_from_left;
	int	i;
	int	higher;

	i = 1;
	visible_from_left = 0;
	higher = 0;
	while (i < side_len - 1)
	{
		if (tab[row][i] > higher)
		{
			higher = tab[row][i];
			visible_from_left++;
		}
		i++;
	}
	return (visible_from_left);
}

int check_r_from_right(int tab[6][6], int row, int side_len)
{
	int	visible_from_right;
	int	i;
	int higher;

	i = side_len - 2;
	visible_from_right = 0;
	higher = 0;
	while (i > 0)
	{
		if (tab[row][i] > higher)
		{
			higher = tab[row][i];
			visible_from_right++;
		}
		i--;
	}
	return (visible_from_right);
}

int	check_row(int tab[6][6], int row, int side_len)
{
	if (check_r_from_right(tab, row, side_len) != tab[row][0] || check_r_from_left(tab, row, side_len) != tab[row][side_len - 1])
		return (0);
	return (1);
}

int	check_num_is_valid(int tab[6][6], int row, int col, int num, int side_len)
{
	if (!(height_is_valid(tab, row, col, num, side_len)))
		return (0);
	if (col == side_len - 2)
	{
		if (!(check_row(tab, row, side_len)))
			return (0);
	}
	if (column_full(tab, col, side_len))
	{
		if (!(check_column(tab, col, side_len)))
			return (0);
	}
	return (1);
}

int	input_valid(char *input)
{
	int	i;
	int	nb_arg;
	
	nb_arg = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (i % 2 == 0 && input[i] >= '0' && input[i] <= '9')
		{
			nb_arg++;
		}
		else if (i % 2 == 0 || input[i] != 32 || (input[i+1] == '\0' && input[i] == ' '))
		{
			printf("Error: input only digits & spaces (and terminate by a digit)\n");
			return (0);
		}
		i++;
	}
	if (nb_arg % 4 != 0 || nb_arg < 8)
	{
		printf("Impossible: not a square");
		return (0);
	}
	printf("Tableau %dx%d\n", nb_arg/4, nb_arg/4);
	return (nb_arg);
}

void	print_tab(int tab[6][6], int nb_arg)
{
	int	side_len = nb_arg / 4 + 2;
	int	i;
	int	k;
	char	c;

	i = 0;
	while (i < side_len)
	{
		k = 0;
		while (k < side_len)
		{
			c = tab[i][k] + '0';
			write(1, &c, 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	insert_ext_row(int row_num,int side_len, char *str, int k, int tab[6][6])
{
	int	j;

	j = 1;
	while (j < side_len -1)
	{
		tab[row_num][j] = str[k] - '0';
		j++;
		k += 2;
	}
	return (k);
}

int	insert_ext_col(int col_num, int side_len, char *str, int k, int tab[6][6])
{
	int	j;

	j = 1;
	while (j < side_len -1)
	{
		tab[j][col_num] = str[k] - '0';
		j++;
		k += 2;
	}
	return (k);
}

void create_tab(int tab[6][6], int nb_arg, char *str)
{
	int side_len = nb_arg / 4 + 2;
	int	k;
	int	j;

	k = 0;
	while (k < side_len)
	{
		j = 0;
		while (j < side_len)
		{
			tab[k][j] = 0;
			j++;
		}
		k++;
	}
	k = 0;
	k = insert_ext_row(0, side_len, str, k, tab);
	k = insert_ext_row(side_len - 1, side_len, str, k, tab);
	k = insert_ext_col(0, side_len, str, k, tab);
	k = insert_ext_col(side_len - 1, side_len, str, k, tab);
}

void	solver(int tab[6][6], int row, int col, int side_len, int nb_arg)
{
	int	nb;
	int	next_col;
	int	next_row;

	nb = 1;
	if (game_finished(tab))
	{
		print_tab(tab, nb_arg);
		return;
	}
	while (nb <= 4)
	{
		printf("ok");
		if (check_num_is_valid(tab, row, col, nb, side_len))
		{
			tab[row][col] = nb;
			next_col = col + 1;
			next_row = row;
			if (next_col == 5)
			{
				next_col = 1;
				next_row++;
			}
			solver(tab, next_row, next_col, side_len, nb_arg);
			tab[row][col] = 0;
		}
		nb++;
	}
	printf("No valid move not found");
}

int	main(int argc, char **argv)
{
	int	result;
	int	nb_arg;
	int	tab[6][6];

	if (argc != 2)
	{
		printf("Too many arguments... try again ^^");
		return (0);
	}
	else
	{
		nb_arg = input_valid(argv[1]);
		create_tab(tab, nb_arg, argv[1]);
		print_tab(tab, nb_arg);
		printf("\n");

		tab[1][2] = 2; tab[2][2] = 1; tab[4][2] = 4;
		tab[3][0] = 2; tab[3][1] = 2; tab[3][2] = 1; tab[3][3] = 4; tab[3][4] = 3; tab[3][5] = 2;
		print_tab(tab, nb_arg);
		printf("\n");
		printf("%d\n", check_c_from_down(tab, 2, 6));
		printf("\n");
		printf("%d\n", height_is_valid(tab, 3, 2, 1, 6));
		printf("\n");
		printf("%d\n", column_full(tab, 2, 6));
		printf("\n");
		printf("%d\n", check_column(tab, 2, 6));
		printf("\n");
		printf("%d\n", check_row(tab, 3, 6));

		solver(tab, 0, 0, 6, nb_arg);
	}
	return (0);
}
