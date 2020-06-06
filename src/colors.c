/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 18:04:16 by greed         #+#    #+#                 */
/*   Updated: 2020/05/20 17:49:16 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	convert_flr_clr(int r, int g, int b)
{
	unsigned int	flr_color;

	flr_color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (flr_color);
}

void			set_floor_ceiling(t_ray *ray)
{
	ray->flr_color = convert_flr_clr(ray->data.g_floor_clr.red,
		ray->data.g_floor_clr.green,
		ray->data.g_floor_clr.blue);
	ray->ceil_clr = convert_flr_clr(ray->data.g_ceiling_clr.red,
		ray->data.g_ceiling_clr.green,
		ray->data.g_ceiling_clr.blue);
}
