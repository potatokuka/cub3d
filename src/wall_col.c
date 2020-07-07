/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_col.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 12:41:19 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 17:15:08 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		ft_iseq(double c1, double c2)
{
	if (c1 - c2 >= -0.01 && c1 - c2 <= 0.01)
		return (1);
	return (0);
}

t_vect	ft_yeet_back(char **map, t_vect old)
{
	t_vect	update;

	update = old;
	if (ft_iseq(floor(old.y), old.y) &&
		(int)old.y - 1 > 0 &&
		!ft_chrmatch(map[(int)old.y - 1][(int)old.x], "1"))
		update.y += 0.05;
	if (ft_iseq(ceil(old.y), old.y) &&
		map[(int)old.y + 1][(int)old.x] == '1')
		update.y -= 0.05;
	if (ft_iseq(floor(old.x), old.x) && (int)old.x - 1 > 0 &&
		!ft_chrmatch(map[(int)old.y][(int)old.x - 1], "1"))
		update.x += 0.05;
	if (ft_iseq(ceil(old.x), old.x) && map[(int)old.y][(int)old.x + 1] == '1')
		update.x -= 0.05;
	return (update);
}

void	ft_update_pos(t_ray *ray, t_vect incr, double speed)
{
	char	**map;
	t_vect	pos;
	t_vect	new_pos;

	pos = ray->play.pos;
	map = ray->map_array;
	pos.x += (speed * incr.x);
	pos.y += (speed * incr.y);
	new_pos.x = ray->play.pos.x;
	new_pos.y = ray->play.pos.y;
	if (pos.x > 0 && !ft_chrmatch(map[(int)ray->play.pos.y][(int)pos.x], "1"))
		new_pos.x = pos.x;
	if (pos.y > 0 && !ft_chrmatch(map[(int)pos.y][(int)ray->play.pos.x], "1"))
		new_pos.y = pos.y;
	new_pos = ft_yeet_back(ray->map_array, new_pos);
	ray->play.pos = new_pos;
}

int		new_movement(t_ray *ray)
{
	if (ray->moving == 1)
	{
		if (ray->strafe_l)
			ft_rot_dir(ray, -ROT_SPEED);
		if (ray->strafe_r)
			ft_rot_dir(ray, ROT_SPEED);
		if (ray->move_right)
			ft_update_pos(ray, ray->play.plane, MV_SPEED);
		if (ray->move_left)
			ft_update_pos(ray, ray->play.plane, -MV_SPEED);
		if (ray->move_f)
			ft_update_pos(ray, ray->play.dir, MV_SPEED);
		if (ray->move_b)
			ft_update_pos(ray, ray->play.dir, -MV_SPEED);
	}
	return (0);
}
