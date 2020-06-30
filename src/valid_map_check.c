/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:48:51 by greed         #+#    #+#                 */
/*   Updated: 2020/06/30 18:05:30 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_play_pos(t_ray *ray, int x, int y)
{
	ray->start_dir = (ft_start_dir(ray, &ray->map_array[y][x]));
	ray->nsew += 1;
	ray->play.pos.x = (x + 0.48);
	ray->play.pos.y = (y + 0.43);
	ray->map_array[y][x] = '0';
	if (flood_fill_map(ray, x, y) == 1)
		put_error("Invalid Map");
}

int			map_check_2(t_ray *ray, int x, int y)
{
	int		len;

	len = ft_strlen_lib(ray->map_array[y]);
	while (ray->map_array[y][x])
	{
		if (ray->map_array[y][x] == '2' || ray->map_array[y][x] == 'U')
			ray->data.g_num_sprite++;
		if (ft_strchr_lib("NSEW", ray->map_array[y][x]))
			set_play_pos(ray, x, y);
		x++;
	}
	return (x);
}

bool		vlad_impaler(t_ray *ray)
{
	int x;
	int y;
	int width;

	y = 0;
	width = 0;
	free_list(ray->map_lst, &free);
	while (y < ray->map_height)
	{
		x = 0;
		if (y == 0)
			while (ray->map_array[0][x])
			{
				x++;
				width++;
			}
		if (y != 0 && y != ray->map_height)
			x = map_check_2(ray, x, y);
		if (x == -2)
			return (false);
		ray->map_wid = width;
		y++;
	}
	return (true);
}
