/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_res.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:49:01 by greed         #+#    #+#                 */
/*   Updated: 2020/05/18 14:43:59 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_res(t_ray *ray, char **info)
{
	int i;

	i = 0;
	ray->vars++;
	while (info[i])
		i++;
	if (i != 3)
		put_error("Invalid Resolution Given");
	if (info[1][0] == '-' || info[2][0] == '-')
		put_error("Negative Resolution");
	if (ft_dig_str(info[1]) == 1)
	{
		ray->win_x = ft_atoi(info[1]);
		if (ray->win_x > 2560 || ray->win_x < 1)
			ray->win_x = 2560;
	}
	if (ft_dig_str(info[2]) == 1)
	{
		ray->win_y = ft_atoi(info[2]);
		if (ray->win_y > 1440 || ray->win_y < 1)
			ray->win_y = 1440;
	}
	else
		put_error("Invalid Resolution Given");
}
