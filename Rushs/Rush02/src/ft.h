/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabas <cfabas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:46:38 by cfabas            #+#    #+#             */
/*   Updated: 2024/03/31 16:55:20 by cfabas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

int		**arrii(int len);
int		*arri(int len);
char	**arrcc(int len);
char	*arrc(int len);

void	clean_arrii(int **arr, int len);
void	clean_arri(int *arr);
void	clean_arrcc(char **arr, int len);
void	clean_arrc(char *arr);

int		linecount(char *argv);
int		*lineslens(char *argv);
char	**setup(char *argv);
char	**populate(char *argv);

int		argparse(char *arg);
int		**parray(char *str);
int		**rev_parray(char *str);

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

char	**split_dict_strings(char **ret, int str_count);

void	search_n_write(int **digits, char **dict, char **argv);

#endif