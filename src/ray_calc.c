/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:38:40 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 13:06:26 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int				ft_set_side(int nb, int opt1, int opt2)
{
	if (nb < 0)
		return (opt1);
	return (opt2);
}

void			calc_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->play.pos.x +
								(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->play.pos.y +
								(1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(ray->win_y / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->win_y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->win_y / 2;
	if (ray->draw_end >= ray->win_y)
		ray->draw_end = ray->win_y - 1;
}

void			perform_dda(t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_array[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void			cont_calc(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		if (ray->time < 100)
		{
			ray->time += 1;
			/* printf("first if\n"); */
		}		
		ray->step_x = -1;
		ray->side_dist_x = (ray->play.pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		if (ray->time < 100)
		{
			ray->time += 1;
			/* printf("first else\n"); */
		}
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->play.pos.x) *
							ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		if (ray->time < 100)
		{
			ray->time += 1;
			/* printf("2nd if\n"); */
		}		
		ray->step_y = -1;
		ray->side_dist_y = (ray->play.pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else 
	{
		if (ray->time < 100)
		{
			ray->time += 1;
			/* printf("2nd else\n"); */
		}		
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->play.pos.y) *
							ray->delta_dist_y;
	}
}

void			start_calc(t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)(ray->win_x) - 1;
	ray->ray_dir_x = ray->play.dir.x + ray->play.plane.x * camera_x;
	ray->ray_dir_y = ray->play.dir.y + ray->play.plane.y * camera_x;
	ray->map_x = (int)(ray->play.pos.x);
	ray->map_y = (int)(ray->play.pos.y);
	ray->delta_dist_x = sqrt(1 + pow(ray->ray_dir_y, 2) /
		pow(ray->ray_dir_x, 2));
	ray->delta_dist_y = sqrt(1 + pow(ray->ray_dir_x, 2) /
		pow(ray->ray_dir_y, 2));
	/* ray->delta_dist_x = ft_abs(1.0 / (double)(ray->ray_dir_x)); */
	/* ray->delta_dist_y = ft_abs(1.0 / (double)(ray->ray_dir_y)); */
	cont_calc(ray);
}
