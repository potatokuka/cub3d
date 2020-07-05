/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_calc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 19:41:30 by greed         #+#    #+#                 */
/*   Updated: 2020/07/05 19:52:01 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

unsigned int		ft_put_sprite(t_ray *ray, unsigned int color, int y)
{
	int d;
	int pos;

	d = (y) * 256 - ray->win_y * 128 + ray->sprite.sprite_height * 128;
	ray->sprite.text_y = ((d * ray->sprite.height) /
							ray->sprite.sprite_height) / 256;
	pos = ((ray->sprite.text_y * ray->sprite.line_len) +
			(ray->sprite.text_x * (ray->sprite.bits_pp / 8)));
	color = *((unsigned int *)(ray->sprite.addr + pos));
	return (color);
}

void				sprite_draw_calc(t_ray *ray)
{
	if (ray->sprite.draw_start_y < 0)
		ray->sprite.draw_start_y = 0;
	ray->sprite.draw_end_y = ray->sprite.sprite_height / 2 + ray->win_y / 2;
	if (ray->sprite.draw_end_y >= ray->win_y)
		ray->sprite.draw_end_y = ray->win_y - 1;
	ray->sprite.sprite_width = fabs((ray->win_y / (ray->sprite.transform_y)));
	ray->sprite.draw_start_x = -ray->sprite.sprite_width / 2 +
								ray->sprite.sprite_screen_x;
	if (ray->sprite.draw_start_x < 0)
		ray->sprite.draw_start_x = 0;
	ray->sprite.draw_end_x = ray->sprite.sprite_width / 2 +
							ray->sprite.sprite_screen_x;
	if (ray->sprite.draw_end_x >= ray->win_x)
		ray->sprite.draw_end_x = ray->win_x - 1;
	ray->sprite.stripe = ray->sprite.draw_start_x;
}

void				sprite_calc(t_ray *ray, int sprite_order[], int i)
{
	ray->sprite.sprite_x = g_sprite_list[sprite_order[i]].x -
							ray->play.pos.x;
	ray->sprite.sprite_y = g_sprite_list[sprite_order[i]].y -
							ray->play.pos.y;
	ray->sprite.inv_det = 1.0 / (ray->play.plane.x *
	ray->play.dir.y - ray->play.dir.x * ray->play.plane.y);
	ray->sprite.transform_x = ray->sprite.inv_det *
	(ray->play.dir.y * ray->sprite.sprite_x -
	ray->play.dir.x * ray->sprite.sprite_y);
	ray->sprite.transform_y = ray->sprite.inv_det *
	(-ray->play.plane.y * ray->sprite.sprite_x +
	ray->play.plane.x * ray->sprite.sprite_y);
	ray->sprite.sprite_screen_x = ((ray->win_x / 2) *
	(1 + ray->sprite.transform_x / ray->sprite.transform_y));
	ray->sprite.sprite_height = fabs((ray->win_y / (ray->sprite.transform_y)));
	ray->sprite.draw_start_y = -ray->sprite.sprite_height / 2 + ray->win_y / 2;
	sprite_draw_calc(ray);
}
