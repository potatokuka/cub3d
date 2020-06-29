/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:29:37 by greed         #+#    #+#                 */
/*   Updated: 2020/06/26 12:36:20 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		change_start_dir(t_ray *ray)
{
	double		old_dir_x;
	double		old_plane_x;
	double		rotate;

	if (ray->start_dir == 'S')
		rotate = M_PI;
	if (ray->start_dir == 'E')
		rotate = (DEG270);
	if (ray->start_dir == 'W')
		rotate = (DEG90);
	old_dir_x = ray->play_dir_x;
	ray->play_dir_x = ray->play_dir_x * cos(rotate) -
						ray->play_dir_y * sin(rotate);
	ray->play_dir_y = old_dir_x * sin(rotate) + ray->play_dir_y * cos(rotate);
	old_plane_x = ray->play_plane_x;
	ray->play_plane_x = ray->play_plane_x * cos(rotate) -
							ray->play_plane_y * sin(rotate);
	ray->play_plane_y = old_plane_x * sin(rotate) +
							ray->play_plane_y * cos(rotate);
}

void		init(t_ray *ray)
{
	ray->play_dir_x = -1;
	ray->play_dir_y = 0;
	ray->play_plane_x = 0;
	ray->play_plane_y = 0.66;
	ray->map_x = 0;
	ray->map_y = 0;
	if (ray->start_dir != 'N')
		change_start_dir(ray);
	ray->mlx_ptr = mlx_init();
	if (ray->mlx_ptr == NULL)
		put_error("mlx error");
	if (ray->bmp == 0)
		ray->mlx_wind = mlx_new_window(ray->mlx_ptr, ray->win_x,
			ray->win_y, "cub3d");
	mlx_do_key_autorepeatoff(ray->mlx_ptr);
	if (ray->mlx_wind == NULL && ray->bmp == 0)
		put_error("mlx error");
	ray->z_buff = (double *)malloc(sizeof(double) * ray->win_x);
}
