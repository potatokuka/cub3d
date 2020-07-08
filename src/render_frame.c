/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:10:34 by greed         #+#    #+#                 */
/*   Updated: 2020/07/08 13:27:57 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_put_pixel(t_ray *ray, unsigned int color, int y, int x)
{
	int	pos;

	pos = ((y * ray->line_len) + (x * (ray->bits_pp / 8)));
	if (ray->curr_img == 0)
		*((unsigned int *)(ray->addr + pos)) = color;
	else
		*((unsigned int *)(ray->addr2 + pos)) = color;
}

void			get_text_color(t_ray *ray, int y)
{
	if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->data.g_color = ft_put_text_south(ray, ray->data.g_color, y);
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->data.g_color = ft_put_text_north(ray, ray->data.g_color, y);
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->data.g_color = ft_put_text_east(ray, ray->data.g_color, y);
	else
		ray->data.g_color = ft_put_text_west(ray, ray->data.g_color, y);
}

void			draw_vert_line(t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->win_y)
	{
		if (y <= ray->draw_end && y >= ray->draw_start)
		{
			get_text_color(ray, y);
			ft_put_pixel(ray, ray->data.g_color, y, x);
			y++;
		}
		else if (y < ray->draw_start)
		{
			ft_put_pixel(ray, ray->ceil_clr, y, x);
			y++;
		}
		else if (y < ray->win_y)
		{
			ft_put_pixel(ray, ray->flr_color, y, x);
			y++;
		}
	}
}

int				render_frame_old(t_ray *ray)
{
	int	x;

	x = 0;
	while (x < ray->win_x)
	{
		start_calc(ray, x);
		perform_dda(ray);
		calc_wall_height(ray);
		calc_north_text(ray);
		calc_south_text(ray);
		calc_east_text(ray);
		calc_west_text(ray);
		ray->z_buff[x] = ray->perp_wall_dist;
		draw_vert_line(ray, x);
		x++;
	}
	cast_sprite(ray);
	return (0);
}

int				render_frame(t_ray *ray)
{
	if (ray->bmp != 0)
	{
		render_frame_old(ray);
		ft_img_to_bmp(ray);
	}
	mlx_sync(1, ray->img_ptr);
	new_movement(ray);
	render_frame_old(ray);
	if (mlx_put_image_to_window(ray->mlx_ptr, ray->mlx_wind,
		ray->img_ptr, 0, 0))
		put_error("MLX failed to put image to window");
	mlx_sync(2, ray->mlx_wind);
	return (0);
}
