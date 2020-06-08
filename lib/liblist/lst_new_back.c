/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 16:08:25 by greed         #+#    #+#                 */
/*   Updated: 2020/06/08 16:08:43 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_list	*lst_new_back(t_list **node, void *content)
{
	t_list	*new;
	t_list	*node_cpy;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	node_cpy = *node;
	while (node_cpy->next)
		node_cpy = node_cpy->next;
	new = lst_new(content);
	new->prev = node_cpy;
	node_cpy->next = new;
	return (new);
}
