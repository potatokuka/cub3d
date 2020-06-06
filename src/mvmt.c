/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mvmt.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:18:07 by greed         #+#    #+#                 */
/*   Updated: 2020/05/25 17:15:04 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	handle_strafe(t_ray *ray)
{
	float	rotate;
	double	old_dir_x;
	double	old_plane_x;

	if (ray->strafe_r == 1)
		rotate = -ROT_SPEED;
	else
		rotate = ROT_SPEED;
	old_dir_x = ray->play_dir_x;
	ray->play_dir_x = ray->play_dir_x * cos(rotate) -
							ray->play_dir_y * sin(rotate);
	ray->play_dir_y = old_dir_x * sin(rotate) +
							ray->play_dir_y * cos(rotate);
	old_plane_x = ray->play_plane_x;
	ray->play_plane_x = ray->play_plane_x * cos(rotate) -
							ray->play_plane_y * sin(rotate);
	ray->play_plane_y = old_plane_x * sin(rotate) +
							ray->play_plane_y * cos(rotate);
}

void	move_forward(t_ray *ray)
{
	int		x;
	int		y;

	x = (int)(ray->play_pos_x + ray->play_dir_x *
		MV_SPEED);
	y = (int)(ray->play_pos_y);
	if (wall_col(ray, (int)(ray->play_pos_x + ray->play_dir_x *
		MV_SPEED), (int)(ray->play_pos_y)) == 0)
		ray->play_pos_x += ray->play_dir_x * MV_SPEED;
	else
		ray->play_pos_x += ray->play_dir_x * BUMP_B;
	if (wall_col(ray, (int)(ray->play_pos_x), (int)(ray->play_pos_y
			+ ray->play_dir_y * MV_SPEED)) == 0)
		ray->play_pos_y += ray->play_dir_y * MV_SPEED;
	else
		ray->play_pos_y += ray->play_dir_y * BUMP_B;
}

void	move_back(t_ray *ray)
{
	if (wall_col(ray, (int)(ray->play_pos_x - ray->play_dir_x
	* MV_SPEED), (int)(ray->play_pos_y)) == 0)
		ray->play_pos_x -= ray->play_dir_x * MV_SPEED;
	else
		ray->play_pos_x -= ray->play_dir_x * BUMP_B;
	if (wall_col(ray, (int)(ray->play_pos_x), (int)(ray->play_pos_y
	- ray->play_dir_y * MV_SPEED)) == 0)
		ray->play_pos_y -= ray->play_dir_y * MV_SPEED;
	else
		ray->play_pos_y -= ray->play_dir_y * BUMP_B;
}

void	move_left(t_ray *ray)
{
	double	dir;
	double	dir2;

	dir = cos(acos(ray->play_dir_y) + M_PI);
	dir2 = cos(acos(ray->play_dir_x) + M_PI);
	if (wall_col(ray, (int)(ray->play_pos_x + dir
	* MV_SPEED), (int)(ray->play_pos_y)) == 0)
		ray->play_pos_x += dir * MV_SPEED;
	else
		ray->play_pos_x += dir * BUMP_B;
	if (wall_col(ray, (int)(ray->play_pos_x), (int)(ray->play_pos_y
	- dir2 * MV_SPEED)) == 0)
		ray->play_pos_y -= dir2 * MV_SPEED;
	else
		ray->play_pos_y -= dir2 * BUMP_B;
}

void	move_right(t_ray *ray)
{
	double	dir;
	double	dir2;

	dir = cos(acos(ray->play_dir_y) + M_PI);
	dir2 = cos(acos(ray->play_dir_x) + M_PI);
	if (wall_col(ray, (int)(ray->play_pos_x - dir
	* MV_SPEED), (int)(ray->play_pos_y)) == 0)
		ray->play_pos_x -= dir * MV_SPEED;
	else
		ray->play_pos_x -= dir * BUMP_B;
	if (wall_col(ray, (int)(ray->play_pos_x), (int)(ray->play_pos_y
	+ dir2 * MV_SPEED)) == 0)
		ray->play_pos_y += dir2 * MV_SPEED;
	else
		ray->play_pos_y += dir2 * BUMP_B;
}
