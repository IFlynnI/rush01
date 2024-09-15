/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   latin_square2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <fmol@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:12:26 by fmol              #+#    #+#             */
/*   Updated: 2024/09/15 12:23:38 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print_latin_square(int **array, int size);

void    swap_rows(int **array, int r1, int r2, int size);

void    swap_columns(int **array, int c1, int c2);

int check_views(int **array, int size, int *clues);

int	**create_latin_square(int **square, int size)
{
	int	*column;
	int	i;
	int	j;
    int offset;

	i = 0;
    offset = 0;
	while (i < size)
	{
		column = malloc(size * sizeof(int));
        if (!column) //TODO: free memory from already allocated columns
            return ((int **)0);
		j = 0;
		while (j < size)
		{
			column[j] = (j + offset) % (size) + 1;
			j++;
		}
		square[i] = column;
		i++;
        offset++;
	}
	return (square);
}

int transform_square(int **array, int size, int *clues, int history)
{
	int	i;
	int	j;
	
	i = 0;
	//print_latin_square(array, size);
	if (check_views(array, size, clues))
		return (1);
	if (history == (size - 1)*(size - 1))
		return (0);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (history % 2 == 0)
			{
				swap_rows(array, i, j, size);
				if (transform_square(array, size, clues, history + 1))
					return (1);
				swap_rows(array, i, j, size);
				swap_columns(array, i, j);
				if (transform_square(array, size, clues, history + 1))
					return (1);
				swap_columns(array, i, j);
			}
			else
			{
				swap_columns(array, i, j);
				if (transform_square(array, size, clues, history + 1))
					return (1);
				swap_columns(array, i, j);
				swap_rows(array, i, j, size);
				if (transform_square(array, size, clues, history + 1))
					return (1);
				swap_rows(array, i, j, size);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int **fill_latin_square(int *clues, int size)
{
    int	**square;

    square = malloc(size * sizeof(int *));
    if (!square)
	    return ((int **)0);
    if (!create_latin_square(square, size))
	    return ((int **)0);
    print_latin_square(square, size);
    if (!transform_square(square, size, clues, 0))
	    return ((int **)0);
    return (square);
}

void	free_memory(int *clues, int **array, int size)
{
    int i;

    free(clues);
    i = 0;
    while (i < size)
    {
        free(array[i]);
        i++;
    }
    free(array);
}
