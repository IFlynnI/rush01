/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_clues_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:09:42 by rpelckma          #+#    #+#             */
/*   Updated: 2024/09/15 11:33:55 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	calculate_clues_size(char *str)
{
	int	i;
	int	count;
	int	on_int;

	i = 0;
	count = 0;
	on_int = 0;
	while (str[i])
	{
		if (!on_int && str[i] >= '0' && str[i] <= '9')
			on_int = 1;
		else if (on_int && str[i] == ' ')
		{
			on_int = 0;
			count++;
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		i++;
	}
	if (on_int) 
		count++;
	return (count);
}

int	set_clues_array(int *arr, char *str)
{
	int     i;
	int	j;
	int	on_int;

	i = 0;
	j = 0;
	on_int = 0;
	while (str[i])
	{
		if (!on_int && str[i] >= '0' && str[i] <= '9')
		{
			arr[j] = (str[i] - '0');
			on_int = 1;
			j++;
		}
		else if (on_int && str[i] == ' ')
			on_int = 0;
		else if (((str[i] < '0' || str[i] > '9') && str[i] != ' ') || on_int)
			return (0);
		i++;
	}
	return (1);
}

int	*create_clues_array(char *str)
{
	int	i;
	int	*arr;
	int	count;

	i = 0;
	count = calculate_clues_size(str);
	if (!count || count % 4 != 0)
		return ((int *)0);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return ((int *)0);
	if (set_clues_array(arr, str))
		return (arr);
	return ((int *)0);
}
