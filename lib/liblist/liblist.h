/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   liblist.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 16:10:20 by greed         #+#    #+#                 */
/*   Updated: 2020/06/08 16:14:03 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H
# include <stddef.h>

typedef struct s_list	t_list;

struct	s_list
{
	void	*content;
	t_list	*next;
	t_list	*prev;
};

t_list	*lst_new(void *content);
t_list	*lst_new_back(t_list **node, void *content);
void	lst_new_front(t_list **node, void *content);
void	lst_remove(t_list *node, void (*free_func)(void *));
void	lst_reverse(t_list **node);
size_t	lst_size(t_list *node);
void	lst_foreach(t_list *node, void (*func)(void *));

#endif
