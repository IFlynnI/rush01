/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:49:22 by fmol              #+#    #+#             */
/*   Updated: 2024/09/14 12:08:51 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_error_message(char *str);

int	arr_len(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	calculate_clues_size(char *str);

int	*create_clues_array(char *str);

int	**fill_latin_square(int *clues, int size);

void	print_latin_square(int **array, int size);

void	free_memory(int *clues, int **array, int size);

int	main(int argc, char *argv[])
{
	int	**array;
	int	*clues;
	int	size;

	if (argc != 2)
		return (print_error_message("add string of numbers"));
	clues = create_clues_array(argv[1]);
	if (!clues)
		return (print_error_message("could not interpret clues"));
	size = arr_len(clues) / 4;
	array = fill_latin_square(clues, size);
	if (!array)
		return (print_error_message("could not find a valid latin square"));
	print_latin_square(array, size);
	free_memory(clues, array, size);
	return (0);
}		
