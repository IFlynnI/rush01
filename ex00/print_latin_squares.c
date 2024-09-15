/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_latin_squares.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:31:01 by rpelckma          #+#    #+#             */
/*   Updated: 2024/09/15 11:51:52 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	print_latin_square(int **array, int size)
{
	int	c;
	int	r;

	c = 0;
	while (c < size)
	{
		r = 0;
		while (r < size)
		{
			ft_putnbr(array[c][r]);
			if (r < size - 1)
				ft_putchar(' ');
			r++;
		}
		ft_putchar('\n');
		c++;
	}
}
