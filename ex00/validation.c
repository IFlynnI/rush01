/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <fmol@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:21:57 by fmol              #+#    #+#             */
/*   Updated: 2024/09/14 20:21:59 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int calculate_cu_view(int **array, int size, int c)
{
    int i;
    int last;
    int count;

    i = 0;
    last = 0;
    count = 0;
    while (i < size)
    {
        if (array[c][i] > last)
        {
            last = array[c][i];
            count++;
        }
        i++;
    }
    return (count);
}

int calculate_cd_view(int **array, int size, int c)
{
    int i;
    int last;
    int count;

    i = size - 1;
    last = 0;
    count = 0;
    while (i >= 0)
    {
        if (array[c][i] > last)
        {
            last = array[c][i];
            count++;
        }
        i--;
    }
    return (count);
}

int calculate_rl_view(int **array, int size, int r)
{
    int i;
    int last;
    int count;

    i = 0;
    last = 0;
    count = 0;
    while (i < size)
    {
        if (array[i][r] > last)
        {
            last = array[i][r];
            count++;
        }
        i++;
    }
    return (count);
}

int calculate_rr_view(int **array, int size, int r)
{
    int i;
    int last;
    int count;

    i = size - 1;
    last = 0;
    count = 0;
    while (i >= 0)
    {
        if (array[i][r] > last)
        {
            last = array[i][r];
            count++;
        }
        i--;
    }
    return (count);
}

int check_views(int **array, int size, int *clues)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (calculate_cu_view(array, size, i) != clues[i]
            || calculate_cd_view(array, size, i) != clues[i + size])
            return (0);
        i++;
    }
    i = 0;
    while (i < size)
    {
        if (calculate_rl_view(array, size, i) != clues[i + size * 2] 
            || calculate_rr_view(array, size, i) != clues[i + size * 3])
            return (0);
        i++;
    }
    return (1);
}