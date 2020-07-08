/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 18:34:10 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 23:17:11 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			sprite_cast_ex(t_ray *ray, int y)
{
	ray->sprite.text_x = (256 * (ray->sprite.stripe -
	(-ray->sprite.sprite_width / 2 + ray->sprite.sprite_screen_x))
	* ray->sprite.width / ray->sprite.sprite_width) / 256;
	if (ray->sprite.transform_y > 0 && ray->sprite.stripe > 0 &&
	ray->sprite.stripe < ray->win_x && ray->sprite.transform_y <
								ray->z_buff[ray->sprite.stripe])
	{
		y = ray->sprite.draw_start_y;
		while (y < ray->sprite.draw_end_y)
		{
			ray->data.g_color = ft_put_sprite(ray, ray->data.g_color, y);
			if ((ray->data.g_color & 0x00FFFFFF) != 0)
				ft_put_pixel(ray, ray->data.g_color, y, ray->sprite.stripe);
			y++;
		}
	}
	ray->sprite.stripe++;
	return (ray->sprite.stripe);
}

void		cast_sprite(t_ray *ray)
{
	int		i;
	int		y;
	int		sprite_order[ray->data.g_num_sprite];
	double	sprite_dist[ray->data.g_num_sprite];

	i = 0;
	y = 0;
	while (i < ray->data.g_num_sprite)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((ray->play.pos.x - g_sprite_list[i].x) *
		(ray->play.pos.x - g_sprite_list[i].x) + (ray->play.pos.y -
		g_sprite_list[i].y) * (ray->play.pos.y - g_sprite_list[i].y));
		i++;
	}
	comb_sort(sprite_order, sprite_dist, ray->data.g_num_sprite);
	i = 0;
	while (i < ray->data.g_num_sprite)
	{
		sprite_calc(ray, sprite_order, i);
		while (ray->sprite.stripe < ray->sprite.draw_end_x)
			ray->sprite.stripe = sprite_cast_ex(ray, y);
		i++;
	}
}

void		save_sprites(t_ray *ray)
{
	int		x;
	int		y;
	int		sprite_num;

	y = 0;
	g_sprite_list = malloc(sizeof(t_sprite_list) * ray->data.g_num_sprite);
	sprite_num = 0;
	if (ray->nsew != 1)
		put_error("No start direction");
	while (ray->map_array[y][0] && sprite_num < ray->data.g_num_sprite)
	{
		x = 0;
		while (ray->map_array[y][x] && sprite_num < ray->data.g_num_sprite)
		{
			if (ray->map_array[y][x] == 'U')
			{
				g_sprite_list[sprite_num].x = (x + 0.5);
				ray->map_array[y][x] = 'O';
				g_sprite_list[sprite_num].y = (y + 0.4);
				sprite_num++;
			}
			x++;
		}
		y++;
	}
}

void		start_text_sprite(t_ray *ray)
{
	ray->sprite.img_ptr = mlx_xpm_file_to_image(ray->mlx_ptr,
		ray->data.g_text_sprite,
		&(ray->sprite.width), &(ray->sprite.height));
	if (!ray->sprite.img_ptr)
		put_error("Invalid: Sprites");
	ray->sprite.addr = mlx_get_data_addr(ray->sprite.img_ptr,
		&(ray->sprite.bits_pp), &(ray->sprite.line_len),
		&(ray->sprite.endian));
	if (!ray->sprite.addr)
		put_error("Invalid: Sprites");
}
