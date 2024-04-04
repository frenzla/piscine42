/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoma <mpoma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:27:03 by mpoma             #+#    #+#             */
/*   Updated: 2024/03/31 10:30:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_line(char *str)
{
	int	nb_counter;

	nb_counter = 0;
	if (*str == '\n')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb_counter++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (*str == ':')
		str++;
	else
		return (-1);
	while (*str == ' ')
		str++;
	if (!ft_str_is_printable(str))
		return (-1);
	if (nb_counter == 0)
		return (-1);
	return (0);
}

int	check_dict(char **ret, int str_count)
{
	int	str_n;

	str_count *= 2;
	str_n = 0;
	while (str_n < str_count)
	{
		if (check_line(ret[str_n]) == -1)
			return (-1);
		str_n += 2;
	}
	return (0);
}

char	**split_dict_strings(char **ret, int str_count)
{
	int	str_n;
	int	i;

	str_count *= 2;
	str_n = 0;
	while (str_n < str_count)
	{
		i = 0;
		if (ret[str_n][0] != '\n')
		{
			while (ret[str_n][i] >= '0' && ret[str_n][i] <= '9')
				i++;
			while (ret[str_n][i] == ' ' || ret[str_n][i] == ':')
			{
				ret[str_n][i] = '\0';
				i++;
			}
			ret[str_n + 1] = &ret[str_n][i];
		}
		str_n += 2;
	}
	return (ret);
}
