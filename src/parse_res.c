/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_res.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:49:01 by greed         #+#    #+#                 */
/*   Updated: 2020/06/30 11:32:41 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_res(t_ray *ray)
{
	int	max_resx;
	int	max_resy;

	mlx_get_screen_size(ray->mlx_ptr, &max_resx, &max_resy);
	max_resy -= 44;
	if (ray->win_x < 1 || ray->win_y < 1)
		put_error("Invalid Resolution Given");
	if (ray->win_x > max_resx)
		ray->win_x = max_resx;
	if (ray->win_y > max_resy)
		ray->win_y = max_resy;
}

void	ft_get_res(t_ray *ray, char **info)
{
	int i;

	i = 0;
	ray->vars++;
	while (info[i])
		i++;
	if (i != 3 || info[1][0] == '-' || info[2][0] == '-')
		put_error("Invalid Resolution Given");
	if (ft_dig_str(info[1]) == 1)
		ray->win_x = ft_atoi(info[1]);
	if (ft_dig_str(info[2]) == 1)
	{
		ray->win_y = ft_atoi(info[2]);
		ft_check_res(ray);
	}
	else
		put_error("Invalid Resolution Given");
}
