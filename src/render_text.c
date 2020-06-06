/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_text.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 18:26:19 by greed         #+#    #+#                 */
/*   Updated: 2020/05/18 14:48:31 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_put_text_north(t_ray *ray, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * ray->win_y) + (128 * ray->line_height);
	ray->text_north.text_y = ((d * ray->text_north.height) /
		ray->line_height) / 256;
	if (ray->text_north.text_y > 63)
		ray->text_north.text_y = 63;
	pos = ((ray->text_north.text_y * ray->text_north.line_len) +
				(ray->text_north.text_x * (ray->text_north.bits_pp / 8)));
	color = *((unsigned int *)(ray->text_north.addr + pos));
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_south(t_ray *ray, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * ray->win_y) + (128 * ray->line_height);
	ray->text_south.text_y = ((d * ray->text_south.height) /
		ray->line_height) / 256;
	if (ray->text_south.text_y > 63)
		ray->text_south.text_y = 63;
	pos = ((ray->text_south.text_y * ray->text_south.line_len) +
				(ray->text_south.text_x * (ray->text_south.bits_pp / 8)));
	color = *((unsigned int *)(ray->text_south.addr + pos));
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_east(t_ray *ray, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * ray->win_y) + (128 * ray->line_height);
	ray->text_east.text_y = ((d * ray->text_east.height) /
		ray->line_height) / 256;
	if (ray->text_east.text_y > 63)
		ray->text_east.text_y = 63;
	pos = ((ray->text_east.text_y * ray->text_east.line_len) +
				(ray->text_east.text_x * (ray->text_east.bits_pp / 8)));
	color = *((unsigned int *)(ray->text_east.addr + pos));
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_west(t_ray *ray, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * ray->win_y) + (128 * ray->line_height);
	ray->text_west.text_y = ((d * ray->text_west.height) /
		ray->line_height) / 256;
	if (ray->text_west.text_y > 63)
		ray->text_west.text_y = 63;
	pos = ((ray->text_west.text_y * ray->text_west.line_len) +
				(ray->text_west.text_x * (ray->text_west.bits_pp / 8)));
	color = *((unsigned int *)(ray->text_west.addr + pos));
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}
