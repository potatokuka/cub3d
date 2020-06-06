/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_save.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:47:47 by greed         #+#    #+#                 */
/*   Updated: 2020/05/24 22:28:07 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_write_color(int fd, t_color clr)
{
	write(fd, &clr.pack.red, 1);
	write(fd, &clr.pack.green, 1);
	write(fd, &clr.pack.blue, 1);
}

unsigned int	ft_pixel_from_img(t_ray *ray, int x, int y)
{
	char			*image;
	t_color			col;

	image = ray->addr;
	image += (int)(y * ray->line_len + (x * (ray->bits_pp / 8)));
	col.color = *(unsigned int *)image;
	return (col.color);
}

void			ft_zeropad(int fd, int len)
{
	int				i;
	unsigned char	c;

	c = 0x00;
	i = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
}

void			ft_header_write(t_ray *ray)
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	size;

	width = (unsigned int)ray->win_x;
	height = (unsigned int)ray->win_y;
	size = (3 * (width * height));
	size += ((width * 3) % 4) ? height * (4 - ((width * 3) % 4)) : 0;
	write(ray->bmp, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	write(ray->bmp, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	write(ray->bmp, &width, 4);
	write(ray->bmp, &height, 4);
	write(ray->bmp, "\x01\x00\x18\x00\x00\x00\x00\x00", 8);
	write(ray->bmp, &size, 4);
	ft_zeropad(ray->bmp, 16);
}

void			ft_img_to_bmp(t_ray *ray)
{
	int		x;
	int		y;
	t_color	pack;

	ft_header_write(ray);
	y = ray->win_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ray->win_x)
		{
			pack.color = ft_pixel_from_img(ray, x, y);
			ft_write_color(ray->bmp, pack);
			x++;
		}
		if ((ray->win_x * 3) % 4 != 0)
			ft_zeropad(ray->bmp, 4 - ((ray->win_x * 3) % 4));
		y--;
	}
	close(ray->bmp);
	exit(0);
}
