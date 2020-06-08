/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_foreach.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 16:08:16 by greed         #+#    #+#                 */
/*   Updated: 2020/06/08 16:08:38 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	lst_foreach(t_list *node, void (*func)(void *))
{
	while (node)
	{
		func(node->content);
		node = node->next;
	}
}
