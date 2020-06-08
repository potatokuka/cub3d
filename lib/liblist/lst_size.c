/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_size.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 16:10:01 by greed         #+#    #+#                 */
/*   Updated: 2020/06/08 16:10:02 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

size_t	lst_size(t_list *node)
{
	size_t	res;

	res = 0;
	while (node)
	{
		node = node->next;
		res++;
	}
	return (res);
}
