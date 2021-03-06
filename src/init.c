/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:29:37 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 17:07:38 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		change_start_dir(t_ray *ray)
{
	double		old_dir_x;
	double		old_plane_x;
	double		rotate;

	if (ray->start_dir == 'E')
		rotate = M_PI;
	if (ray->start_dir == 'S')
		rotate = (DEG270);
	if (ray->start_dir == 'N')
		rotate = (DEG90);
	old_dir_x = ray->play.dir.x;
	ray->play.dir.x = ray->play.dir.x * cos(rotate) -
						ray->play.dir.y * sin(rotate);
	ray->play.dir.y = old_dir_x * sin(rotate) + ray->play.dir.y * cos(rotate);
	old_plane_x = ray->play.plane.x;
	ray->play.plane.x = ray->play.plane.x * cos(rotate) -
							ray->play.plane.y * sin(rotate);
	ray->play.plane.y = old_plane_x * sin(rotate) +
							ray->play.plane.y * cos(rotate);
}

void		init(t_ray *ray)
{
	ray->play.dir.x = -1;
	ray->play.dir.y = 0;
	ray->play.plane.x = 0;
	ray->play.plane.y = 0.66;
	ray->map_x = 0;
	ray->map_y = 0;
	ft_direction_init(ray);
	ray->mlx_ptr = mlx_init();
	if (ray->mlx_ptr == NULL)
		put_error("mlx error");
	if (ray->bmp == 0)
		ray->mlx_wind = mlx_new_window(ray->mlx_ptr, ray->win_x,
			ray->win_y, "cub3D");
	if (ray->mlx_wind == NULL && ray->bmp == 0)
		put_error("mlx error");
	ray->z_buff = (double *)malloc(sizeof(double) * ray->win_x);
	if (!ray->z_buff)
		put_error("Memory Failure in Z_buff 1");
}
