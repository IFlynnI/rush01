/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   latin_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:10:47 by fmol              #+#    #+#             */
/*   Updated: 2024/09/14 18:34:30 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*create_pair(int x, int y);

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	set_row(int ***array, int size, int r, int start)
{
	int	sign;
	int	i;
	int	limit;

	sign = -1;
	i = size - 1;
	limit = 0;
	if (start == 1)
	{
		i = 0;
		sign = 1;
		limit = size;
	}
	while (ft_abs(limit - i) > 0)
	{
		array[i][r] = i + 1;
		i = i + sign;
	}
}

void    set_column(int ***array, int size, int c, int start)
{
        int     sign;
        int     i;
        int     limit;

        sign = -1;
        i = size - 1;
        limit = 0;
        if (start == 1)
        {
                i = 0;
                sign = 1;
                limit = size;
        }
        while (ft_abs(limit - i) > 0)
        {
                assign(array, c, i, i + 1);
                i = i + sign;
        }
}

/*
 * set the numbers in the array we know for sure based on the clues
 */
void	assign_numbers(int *clues, int ***array, int size)
{
	int	i;

	i = 0;
	while (i < size * 4)
	{
		if (clues[i] == 1 && i / (size * 2) < 1)
			//set first or last entry of column to size
			assign(array, i % 4, (i / (size * 4)) * size, size);
		else if (clues[i] == 1 && i / (size * 2) >= 1)
			//set first or last entry of row to size
                        assign(array, (i / (size * 4)) * size, i % 4, size);
		else if (clues[i] == n && i / (size * 2) < 1)	
			//set entire column to 1:n;
			set_column(array, size, i % 4, (i / (size * 4)) * size);
		else if (clues[i] == n && i / (size * 2) >= 1)
			//set entire row to 1:n;
                        set_row(array, size, (i / (size * 4)) * size, i % 4);

	}
}

void	check_square(int *clues, int ***array, int size)

/*
 * assigns 'value' to array[c][r] and eliminates it from the options of
 * array[c][1:n] and array[1:n][r]
 */
int	assign(int ***array, int *index_pair, int value, int size)
{
	int	i;
	//eliminate every option besides value from array[c][r]
	i = 1;
	while(i <= size)
	{
		if (i == value)
		{
			i++;
			continue ;
		}
		if(!eliminate(array, index_pair, i, size));
			return (0);
		i++;
	}
	return (1);
}

int	has_one_option(int *options)
{
	if (options[1] == 0)
		return options[0];
	return (0);
}

int	has_option(int *options, int value, int size)
{
	int	i;

	i = 0;
	while (i < size && options[i] != 0)
	{
		if (options[i] == value)
			return (1);
	}
	return (0);
}

int	remove_from_options(int *options, int value, int size)
{
	int	i;
	int	found_val;

	i = 0;
	found_val = 0;
	while(i < size - 1 && options[i] != 0)
	{
		if (options[i] == value)
			found_val = 1;
		if (found_val)
			options[i] = options[i + 1];
		i++;
	}
	if (!found_val && options[i] == value)
	{
		options[i] = 0;
		return (1);
	}
	else if (!found_val)
		return (0);
	return (1);
}

int	eliminate_from_peers(int ***array, int *index_pair, int value, int size)
{
	int	*pair;
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (c < size)
	{
		if (c == index_pair[0])
		{
			c++;
			continue ;
		}
		pair = create_pair(c, index_pair[1]);
		if (!eliminate(array, pair, value, size))
		{
			free(pair);
			return (0);
		}
		free(pair);
	}
	while (r < size)
	{
		if (r == index_pair[1])
                {
                        r++;
                        continue ;
                }
                pair = create_pair(index_pair[0], r);
                if (!eliminate(array, pair, value, size))
                {
                        free(pair);
                        return (0);
                }
                free(pair);
	}
	return (1);
}

int	check_units_for_assign(int ***array, int size)
{
	int	r;
	int	c;

	c = 0;
	r = 0;
	while (c < size)
	{
		while (r < size)
		{
			if ()
		}
	}
}

/*
 * eliminates 'value' from the options of array[c][r]
 */
int	eliminate(int ***array, int *index_pair, int value, int size)
{
	int	nbr;
	if (!has_option(array[index_pair[0]][index_pair[1]], value, size))
		return (1);
	nbr = has_one_option(array[index_pair[0]][index_pair[1]]);
	if (nbr && has_option(array, array[index_pair[0]][index_pair[1]], value, size))
		return (0);
	else if (!nbr)
	{
		remove_from_options(array[index_pair[0]][index_pair[1]], value, size);
		nbr = has_one_option(array[index_pair[0]][index_pair[1]]);
		if (nbr)
			if (!eliminate_from_peers(array, index_pair, value, size))
				return (0);
	}
	reeturn (check_units_for_assign(array, size));
}

int	*create_options_array(int size)
{
	int	*options;
	int	i;

	options = malloc(size * sizeof(int));
	i = 1;
	while (i <= size)
	{
		options[i - 1] = i;
		i++;
	}
	return (options);
}

int	***create_latin_square(int size)
{
	int	***square;
	int	**column;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		column = malloc(size * sizeof(int *));
		j = 0;
		while (j < size)
		{
			column[j] = create_options_array(size);
			j++;
		}
		square[i] = column;
		i++;
	}
	return (square);
}

#include <stdlib.h>
/*
 * clues contains the visibility clues (skycraper puzzle style)
 * cu = column up, cd = column down, rl = row left, rr = row right
 * order: cu1, ..., cun, cd1, ..., cdn, rl1, ..., rln, rr1, ... rrn
 */
int	**fill_latin_square(int *clues, int size)
{
	int	***square;

	square = create_latin_square(size);
	set_initial_numbers(clues, square, size);

}
