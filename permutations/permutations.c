/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:43:07 by fibarros          #+#    #+#             */
/*   Updated: 2024/10/05 17:11:19 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	swap(char *x, char *y)
{
	char temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	permuteRec(char *str, int idx, int n)
{
	if (idx == n - 1)
	{
		ft_putstr(str);
		ft_putchar('\n');
		return ;
	}
	int i = idx;
	while (i < n)
	{
		swap(&str[idx], &str[i]);
		permuteRec(str, idx + 1, n);
		swap(&str[idx], &str[i]);
		i++;
	}
}

void	permute(char *str)
{
	int n = ft_strlen(str);
	permuteRec(str, 0, n);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *str = av[1];
	permute(str);
	return (0);
}
