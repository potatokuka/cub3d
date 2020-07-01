/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot_dir.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 11:12:48 by greed         #+#    #+#                 */
/*   Updated: 2020/07/01 11:12:49 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

double	ft_deg_radial(double ang)
{
	return (ang * (M_PI / 180));
}

void	ft_rot_dir(t_ray *ray, double ang)
{
	t_vect	plane;
	t_vect	dir;

	ang = ft_deg_radial(ang);
	plane.x = ray->play.plane.x * cos(ang) + ray->play.plane.y * -sin(ang);
	plane.y = ray->play.plane.x * sin(ang) + ray->play.plane.y * cos(ang);
	dir.x = ray->play.dir.x * cos(ang) + ray->play.dir.y * -sin(ang);
	dir.y = ray->play.dir.x * sin(ang) + ray->play.dir.y * cos(ang);
	ray->play.dir = dir;
	ray->play.plane = plane;
}
