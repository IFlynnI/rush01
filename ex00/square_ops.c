/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <fmol@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:16:39 by fmol              #+#    #+#             */
/*   Updated: 2024/09/14 20:16:41 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    swap_rows(int **array, int r1, int r2, int size)
{
    int i;
    int tmp;

    i = 0;
    if (r1 == r2)
        return ;
    while (i < size)
    {
        tmp = array[i][r1];
        array[i][r1] = array[i][r2];
        array[i][r2] = tmp;
        //array[i][r1] ^= array[i][r2];
        //array[i][r1] ^= array[i][r2];
        //array[i][r1] ^= array[i][r2];
        i++;
    }
}

void    swap_columns(int **array, int c1, int c2)
{
    int *tmp;
    if (c1 == c2)
        return ;
    tmp = (array[c2]);
    (array[c2]) = (array[c1]);
    (array[c1]) = tmp;
}