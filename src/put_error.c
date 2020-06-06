/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 14:45:06 by greed         #+#    #+#                 */
/*   Updated: 2020/05/25 17:43:26 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error(char *error)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}
