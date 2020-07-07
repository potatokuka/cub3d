/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mvmt.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 22:44:25 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 22:46:07 by greed         ########   odam.nl         */
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
	old_dir_x = ray->play.dir.x;
	ray->play.dir.x = ray->play.dir.x * cos(rotate) -
							ray->play.dir.y * sin(rotate);
	ray->play.dir.y = old_dir_x * sin(rotate) +
							ray->play.dir.y * cos(rotate);
	old_plane_x = ray->play.plane.x;
	ray->play.plane.x = ray->play.plane.x * cos(rotate) -
							ray->play.plane.y * sin(rotate);
	ray->play.plane.y = old_plane_x * sin(rotate) +
							ray->play.plane.y * cos(rotate);
}

void	move_forward(t_ray *ray)
{
	int		x;
	int		y;

	x = (int)(ray->play.pos.x + ray->play.dir.x *
		MV_SPEED);
	y = (int)(ray->play.pos.y);
	if (wall_col(ray, (int)(ray->play.pos.x + ray->play.dir.x *
		MV_SPEED), (int)(ray->play.pos.y)) == 0)
		ray->play.pos.x += ray->play.dir.x * MV_SPEED;
	else
		ray->play.pos.x += ray->play.dir.x * BUMP_B;
	if (wall_col(ray, (int)(ray->play.pos.x), (int)(ray->play.pos.y
			+ ray->play.dir.y * MV_SPEED)) == 0)
		ray->play.pos.y += ray->play.dir.y * MV_SPEED;
	else
		ray->play.pos.y += ray->play.dir.y * BUMP_B;
}

void	move_back(t_ray *ray)
{
	if (wall_col(ray, (int)(ray->play.pos.x - ray->play.dir.x
	* MV_SPEED), (int)(ray->play.pos.y)) == 0)
		ray->play.pos.x -= ray->play.dir.x * MV_SPEED;
	else
		ray->play.pos.x -= ray->play.dir.x * BUMP_B;
	if (wall_col(ray, (int)(ray->play.pos.x), (int)(ray->play.pos.y
	- ray->play.dir.y * MV_SPEED)) == 0)
		ray->play.pos.y -= ray->play.dir.y * MV_SPEED;
	else
		ray->play.pos.y -= ray->play.dir.y * BUMP_B;
}

void	move_left(t_ray *ray)
{
	double	dir;
	double	dir2;

	dir = cos(acos(ray->play.dir.y) + M_PI);
	dir2 = cos(acos(ray->play.dir.x) + M_PI);
	if (wall_col(ray, (int)(ray->play.pos.x + dir
	* MV_SPEED), (int)(ray->play.pos.y)) == 0)
		ray->play.pos.x += dir * MV_SPEED;
	else
		ray->play.pos.x += dir * BUMP_B;
	if (wall_col(ray, (int)(ray->play.pos.x), (int)(ray->play.pos.y
	- dir2 * MV_SPEED)) == 0)
		ray->play.pos.y -= dir2 * MV_SPEED;
	else
		ray->play.pos.y -= dir2 * BUMP_B;
}

void	move_right(t_ray *ray)
{
	double	dir;
	double	dir2;

	dir = cos(acos(ray->play.dir.y) + M_PI);
	dir2 = cos(acos(ray->play.dir.x) + M_PI);
	if (wall_col(ray, (int)(ray->play.pos.x - dir
	* MV_SPEED), (int)(ray->play.pos.y)) == 0)
		ray->play.pos.x -= dir * MV_SPEED;
	else
		ray->play.pos.x -= dir * BUMP_B;
	if (wall_col(ray, (int)(ray->play.pos.x), (int)(ray->play.pos.y
	+ dir2 * MV_SPEED)) == 0)
		ray->play.pos.y += dir2 * MV_SPEED;
	else
		ray->play.pos.y += dir2 * BUMP_B;
}