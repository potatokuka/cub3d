/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:09:14 by greed         #+#    #+#                 */
/*   Updated: 2020/06/08 14:53:48 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_calloc(size_t count, size_t size)
{
	void		*stored;

	stored = (void*)malloc(count * size);
	if (!(stored))
		return (NULL);
	ft_bzero(stored, count * size);
	return (stored);
}
