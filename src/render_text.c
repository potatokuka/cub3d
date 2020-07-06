/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_text.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 18:26:19 by greed         #+#    #+#                 */
/*   Updated: 2020/07/06 16:46:11 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw_line(t_ray *ray, t_dda *dda, t_line line, t_texdata tex)
{
	int i;
	t_color color;
	double	tex_y;

	i = 0;
	tex_y = ((line.start - ray->win_y / 2 + line.len / 2) * tex.y_step)
				- tex.y_step;
	while (i < ray->win_y)
	{
		if (i >= line.start && i <= line.end)
		{
			color = ft_texture_get(ray, dda, tex.x,
					((int)tex_y > 0) ? (int)tex_y : 0);
			ft_put_pixel(ray, line.x, i, color.color);
			tex_y += tex.y_step;
		}
		else if (i < line.start)
			ft_put_pixel(ray, line.x, i, ray->ceil_clr);
		else if (i < ray->win_y)
			ft_put_pixel(ray, line.x, i, ray->flr_color);
		i++;
	}
}

t_color			ft_texture_get(t_ray *ray, t_dda *dda, int x, int y)
{
char	*image;
t_color	color;

if (dda->side == NORTH)
{
	image = ray->text_north.addr;
	image += (y * ray->text_north.line_len + (x * (ray->text_north.bits_pp / 8)));
}
if (dda->side == SOUTH)
{
	image = ray->text_south.addr;
	image += (y * ray->text_south.line_len + (x * (ray->text_south.bits_pp / 8)));
}
if (dda->side == EAST)
{
	image = ray->text_east.addr;
	image += (y * ray->text_east.line_len + (x * (ray->text_east.bits_pp / 8)));
}
if (dda->side == WEST)
{
	image = ray->text_west.addr;
	image += (y * ray->text_west.line_len + (x * (ray->text_west.bits_pp / 8)));
}
color.color = *(unsigned int *)image;
return (color);
}

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
