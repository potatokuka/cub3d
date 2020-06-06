/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooking.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:53:19 by greed         #+#    #+#                 */
/*   Updated: 2020/05/20 15:01:06 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(t_ray *ray)
{
	int done;

	done = 0;
	ray->img_ptr = mlx_new_image(ray->mlx_ptr, ray->win_x, ray->win_y);
	ray->img_ptr2 = mlx_new_image(ray->mlx_ptr, ray->win_x, ray->win_y);
	ray->addr = mlx_get_data_addr(ray->img_ptr, &(ray->bits_pp),
		&(ray->line_len), &(ray->endian));
	ray->addr2 = mlx_get_data_addr(ray->img_ptr2, &(ray->bits_pp),
		&(ray->line_len), &(ray->endian));
	start_text_img(ray);
	mlx_loop_hook(ray->mlx_ptr, render_frame, ray);
	if (ray->bmp == 0)
	{
		mlx_hook(ray->mlx_wind, 17, 0L, &ft_red_x, ray);
		mlx_hook(ray->mlx_wind, E_KEY_PRESS, 1L << 0, handle_press, ray);
		mlx_hook(ray->mlx_wind, E_KEY_RELEASE, 1L << 1, handle_release, ray);
	}
	mlx_loop(ray->mlx_ptr);
}
