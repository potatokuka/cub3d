/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 14:48:47 by greed         #+#    #+#                 */
/*   Updated: 2020/05/18 14:48:49 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		comb_sort_ex(int *order, double *dist, t_sort *sort)
{
	sort->j = sort->i + sort->gap;
	if (dist[sort->i] < dist[sort->j])
	{
		sort->tempdist = dist[sort->i];
		dist[sort->i] = dist[sort->j];
		dist[sort->j] = sort->tempdist;
		sort->tempord = order[sort->i];
		order[sort->i] = order[sort->j];
		order[sort->j] = sort->tempord;
		sort->swapped = 1;
	}
}

void		comb_sort(int *order, double *dist, int amount)
{
	t_sort	sort;

	sort.gap = amount;
	sort.i = 0;
	sort.swapped = 0;
	while (sort.gap > 1 || sort.swapped)
	{
		sort.gap = (sort.gap * 10) / 13;
		if (sort.gap == 9 || sort.gap == 10)
			sort.gap = 11;
		if (sort.gap < 1)
			sort.gap = 1;
		sort.swapped = 0;
		while (sort.i < amount - sort.gap)
		{
			comb_sort_ex(order, dist, &sort);
			sort.i++;
		}
	}
}
