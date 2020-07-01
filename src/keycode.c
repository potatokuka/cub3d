/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keycode.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 12:18:54 by greed         #+#    #+#                 */
/*   Updated: 2020/07/01 11:09:04 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_press(int keycode, t_ray *ray)
{
	if (keycode == K_ESC)
	{
		ft_red_x(ray);
	}
	ray->moving = 1;
	if (keycode == K_W)
		ray->move_f = 1;
	if (keycode == K_S)
		ray->move_b = 1;
	if (keycode == K_D)
		ray->move_right = 1;
	if (keycode == K_A)
		ray->move_left = 1;
	if (keycode == K_RIGHT)
		ray->strafe_r = 1;
	if (keycode == K_LEFT)
		ray->strafe_l = 1;
	return (0);
}

int		handle_release(int keycode, t_ray *ray)
{
	if (keycode == K_W)
		ray->move_f = 0;
	if (keycode == K_S)
		ray->move_b = 0;
	if (keycode == K_D)
		ray->move_right = 0;
	if (keycode == K_A)
		ray->move_left = 0;
	if (keycode == K_RIGHT)
		ray->strafe_r = 0;
	if (keycode == K_LEFT)
		ray->strafe_l = 0;
	if (keycode == E_EXIT)
		ft_red_x(ray);
	ray->moving = 0;
	return (0);
}
