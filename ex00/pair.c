/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:30:36 by fmol              #+#    #+#             */
/*   Updated: 2024/09/14 16:37:09 by fmol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*create_pair(int x, int y)
{
	int	*pair;
	
	pair = malloc(2 * sizeof(int));
	if (!pair)
		return ((int *)0);
	pair[0] = x;
	par[1] = y;
	return (pair);
}
