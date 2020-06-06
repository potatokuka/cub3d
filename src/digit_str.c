/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digit_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 10:06:03 by greed         #+#    #+#                 */
/*   Updated: 2020/05/18 14:33:19 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_dig_str(char *str)
{
	if (!str)
		put_error("Invalid Resolution");
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
