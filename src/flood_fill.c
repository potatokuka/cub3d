/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 11:34:31 by greed         #+#    #+#                 */
/*   Updated: 2020/07/06 13:39:50 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	flood_check(t_ray *ray, int x, int y)
{
	if (ray->map_array[y][x] == '0')
		ray->map_array[y][x] = 'O';
	if (ray->map_array[y][x] == '2')
		ray->map_array[y][x] = 'U';
}

/*
**	Mark where you've passed and Check if inbounds
*/

int		flood_fill_map(t_ray *ray, int x, int y)
{
	int		len;

	if (x < 0 || y < 0 || y >= ray->map_height)
		return (INVALID);
	if (ray->map_array[y][x] == 'O' || ray->map_array[y][x] == 'U' ||
		ray->map_array[y][x] == '1')
		return (0);
	len = ft_strlen_lib(ray->map_array[y]);
	if (x >= len)
		return (INVALID);
	flood_check(ray, x, y);
	if (flood_fill_map(ray, x, y - 1) ||
		flood_fill_map(ray, x, y + 1) ||
		flood_fill_map(ray, x - 1, y) ||
		flood_fill_map(ray, x + 1, y) ||
		flood_fill_map(ray, x + 1, y + 1) ||
		flood_fill_map(ray, x + 1, y - 1) ||
		flood_fill_map(ray, x - 1, y + 1) ||
		flood_fill_map(ray, x - 1, y - 1))
		return (INVALID);
	return (VALID);
}
