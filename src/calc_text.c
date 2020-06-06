/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_text.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:05:58 by greed         #+#    #+#                 */
/*   Updated: 2020/05/25 14:08:39 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		calc_west_text(t_ray *ray)
{
	if (ray->side == 0)
		ray->text_west.wall_x = ray->play_pos_y +
			ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->text_west.wall_x = ray->play_pos_x +
			ray->perp_wall_dist * ray->ray_dir_x;
	ray->text_west.wall_x -= floor((ray->text_west.wall_x));
	ray->text_west.text_x = (int)(ray->text_west.wall_x *
							(double)(ray->text_west.width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_west.text_x = ray->text_west.width -
			ray->text_west.text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_west.text_x = ray->text_west.width -
			ray->text_west.text_x - 1;
}

void		calc_east_text(t_ray *ray)
{
	if (ray->side == 0)
		ray->text_east.wall_x = ray->play_pos_y +
			ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->text_east.wall_x = ray->play_pos_x +
			ray->perp_wall_dist * ray->ray_dir_x;
	ray->text_east.wall_x -= floor((ray->text_east.wall_x));
	ray->text_east.text_x = (int)(ray->text_east.wall_x *
							(double)(ray->text_east.width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_east.text_x = ray->text_east.width -
			ray->text_east.text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_east.text_x = ray->text_east.width -
			ray->text_east.text_x - 1;
}

void		calc_south_text(t_ray *ray)
{
	if (ray->side == 0)
		ray->text_south.wall_x = ray->play_pos_y +
			ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->text_south.wall_x = ray->play_pos_x +
			ray->perp_wall_dist * ray->ray_dir_x;
	ray->text_south.wall_x -= floor((ray->text_south.wall_x));
	ray->text_south.text_x = (int)(ray->text_south.wall_x *
							(double)(ray->text_south.width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_south.text_x = ray->text_south.width -
			ray->text_south.text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_south.text_x = ray->text_south.width -
			ray->text_south.text_x - 1;
}

void		calc_north_text(t_ray *ray)
{
	if (ray->side == 0)
		ray->text_north.wall_x = ray->play_pos_y +
			ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->text_north.wall_x = ray->play_pos_x +
			ray->perp_wall_dist * ray->ray_dir_x;
	ray->text_north.wall_x -= floor((ray->text_north.wall_x));
	ray->text_north.text_x = (int)(ray->text_north.wall_x *
		(double)(ray->text_north.width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_north.text_x = ray->text_north.width -
			ray->text_north.text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_north.text_x = ray->text_north.width -
			ray->text_north.text_x - 1;
}
