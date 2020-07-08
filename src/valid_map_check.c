/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:48:51 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 13:55:01 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

double		ft_deg2rad(char dir)
{
	double angle;

	angle = 0;
	if (dir == 'N')
		angle = 90;
	if (dir == 'S')
		angle = 270;
	if (dir == 'W')
		angle = 180;
	if (dir == 'E')
		angle = 0;
	return (angle * (M_PI / 180));
}

void		ft_direction_init(t_ray *ray)
{
	double	direction;

	direction = ft_deg2rad(ray->start_dir);
	ray->play.dir.x = cos(direction);
	ray->play.plane.x = sin(direction);
	ray->play.dir.y = -sin(direction);
	ray->play.plane.y = cos(direction);
}

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
	ft_validate_map(ray);
	return (true);
}
