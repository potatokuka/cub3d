/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_text.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:57:50 by greed         #+#    #+#                 */
/*   Updated: 2020/06/30 10:57:34 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		start_text_west(t_ray *ray)
{
	ray->text_west.img_ptr = mlx_xpm_file_to_image(ray->mlx_ptr,
		ray->data.g_text_west, &(ray->text_west.width),
		&(ray->text_west.height));
	if (ray->text_west.img_ptr == NULL)
		put_error("Invalid West Texture Pic");
	ray->text_west.addr = mlx_get_data_addr(ray->text_west.img_ptr,
		&(ray->text_west.bits_pp),
		&(ray->text_west.line_len),
		&(ray->text_west.endian));
	if (ray->text_west.addr == NULL)
		put_error("Invalid West Texture Pic");
}

void		start_text_east(t_ray *ray)
{
	ray->text_east.img_ptr = mlx_xpm_file_to_image(ray->mlx_ptr,
		ray->data.g_text_east, &(ray->text_east.width),
		&(ray->text_east.height));
	if (ray->text_east.img_ptr == NULL)
		put_error("Invalid East Texture Pic");
	ray->text_east.addr = mlx_get_data_addr(ray->text_east.img_ptr,
		&(ray->text_east.bits_pp),
		&(ray->text_east.line_len),
		&(ray->text_east.endian));
}

void		start_text_south(t_ray *ray)
{
	ray->text_south.img_ptr = mlx_xpm_file_to_image(ray->mlx_ptr,
		ray->data.g_text_south, &(ray->text_south.width),
		&(ray->text_south.height));
	if (ray->text_south.img_ptr == NULL)
		put_error("Invalid South Texture Pic");
	ray->text_south.addr = mlx_get_data_addr(ray->text_south.img_ptr,
		&(ray->text_south.bits_pp),
		&(ray->text_south.line_len),
		&(ray->text_south.endian));
}

void		start_text_north(t_ray *ray)
{
	ray->text_north.img_ptr = mlx_xpm_file_to_image(ray->mlx_ptr,
			ray->data.g_text_north, &(ray->text_north.width),
			&(ray->text_north.height));
	if (ray->text_north.img_ptr == NULL)
		put_error("Invalid North Texture Pic");
	ray->text_north.addr = mlx_get_data_addr(ray->text_north.img_ptr,
		&(ray->text_north.bits_pp),
		&(ray->text_north.line_len),
		&(ray->text_north.endian));
}

void		start_text_img(t_ray *ray)
{
	start_text_north(ray);
	start_text_south(ray);
	start_text_east(ray);
	start_text_west(ray);
	start_text_sprite(ray);
}
